#include "OneNETMqttClient.h"

OneNetMqttDevice* mqttdev;

static void *(*onenet_malloc)(size_t sz) = malloc;    //可替换为自己的内存分配管理函数。
static void (*onenet_free)(void *ptr) = free;

/* 函数名：int setCstringData(char* string, char* data)
 * 输  入：
 *		cstring string	字符串结构体，成员包括char* data、int len
 *		char	*infor	装填入cstring结构体内的数据
 * 返  回：
 *		int		len		装填字符串长度
 * 功  能：
 *		将指针data指向的字符串装填入从string结构体内
 */
int setCstringData(char** str, char *data)
{
	if (!data) return 0;
	int len = strlen(data);
	*str = (char*)onenet_malloc(len * sizeof(char)+1);//分配空间
	memset(*str, 0, len);//分配空间清空
	memcpy(*str, data, len);//赋值
	return len;
}

void setUserTopicName(Topic* topic,char* model,char* device_id,char* product_id)
{
	if (!device_id)		return;
	if (!product_id)	return;

	char* topicNameTemp = (char*)onenet_malloc(200 * sizeof(char));

	memset(topicNameTemp, 0, 200);
	sprintf(topicNameTemp, "%s/data/pid/%s/devkey/%s",model, product_id, device_id);
	setCstringData(&topic->upload_dev_data, topicNameTemp);

	memset(topicNameTemp, 0, 200);
	sprintf(topicNameTemp, "%s/cmd/pid/%s/devkey/%s",model, product_id,device_id);
	setCstringData(&topic->cmd_dev_get, topicNameTemp);

	memset(topicNameTemp, 0, 200);
	sprintf(topicNameTemp, "%s/resp/pid/%s/devkey/%s",model, product_id, device_id);
	setCstringData(&topic->cmd_dev_resp, topicNameTemp);

	onenet_free(topicNameTemp);
}

/*@函数名@：void OneNETMQTTDeviceInit()
 *@输  入@：
 *@返  回@：
 *@功  能@：dev初始化
 *		
 */
void OneNETMQTTDeviceInit(OneNetMqttDevice* dev)
{
	mqttdev = dev;
    //定义接收发送缓存
    char recv_buffer[BUFFER_SIZE];
	char send_buffer[BUFFER_SIZE];

    setCstringData(&mqttdev->devInfo.device_id, DEVICE_ID);//装填设备ID
	setCstringData(&mqttdev->devInfo.product_id, PRODUCT_ID);//装填产品ID
	setCstringData(&mqttdev->devInfo.master_key, MASTER_KEY);//鉴权信息
    setCstringData(&mqttdev->mqttserver.host, ServerHost);//mqtt接入机IP
    mqttdev->mqttserver.port=ServerPort;//mqtt接入机端口
	setUserTopicName(&mqttdev->topic,MODEL,DEVICE_ID,PRODUCT_ID);

    NetworkInit(&mqttdev->network);
	MQTTClientInit(&mqttdev->client, &mqttdev->network, TIME_OUT, send_buffer, BUFFER_SIZE, recv_buffer, BUFFER_SIZE);   
}

/*@函数名@：bool OneNETMQTTConnect()
 *@输  入@：
 *@返  回@：
 *		false	失败
 *		true	成功
 *@功  能@：
 *		连接OneNET平台
 */
bool OneNETMQTTConnect(void)
{
    int rc = 0;
	rc = NetworkConnect(&mqttdev->network, mqttdev->mqttserver.host, mqttdev->mqttserver.port);
	ONENETLOG("NetworkConnect status: %d\n", rc);
    if (rc!=0) return false;

	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
	data.willFlag = 0;
	data.MQTTVersion = 3;
	data.clientID.cstring = mqttdev->devInfo.device_id;
	data.username.cstring = mqttdev->devInfo.product_id;
	data.password.cstring = mqttdev->devInfo.master_key;

	data.keepAliveInterval = 60;
	data.cleansession = 1;

	rc = MQTTConnect(&mqttdev->client, &data);
	ONENETLOG("OneNETMQTT Connected status:  %d\n", rc);
    if (rc!=0) return false;
    return true;
}    

void OneNETStandardCmdHandler(MessageData* md)
{
    int rc = 0;
    Command cmd;
	char recvtopic[200];
	MQTTMessage* message = md->message;
	memset(recvtopic,0,200);
	memcpy(recvtopic,md->topicName->lenstring.data,md->topicName->lenstring.len);
    ONENETLOG("receive topic: %s\r\n",recvtopic);
	if (IsStrEquality(mqttdev->topic.cmd_dev_get,recvtopic))
	{	
        //命令解析
        cJSON * req = NULL;
        req = cJSON_Parse(message->payload);
		ONENETLOG("cmdreq:%s\n", cJSON_Print(req));

        cJSON * item; 
        item = cJSON_GetObjectItem(req, "uuid");
        if (item!=NULL){
             cmd.uuid = item->valuestring;
        }else{
			ONENETLOG("cmdreq error: no uuid!\n");
            return;
        }
        item = cJSON_GetObjectItem(req, "cmd");
        if (item!=NULL){
             cmd.key = item->valuestring;
        }else{
			ONENETLOG("cmdreq error: no cmd!\n");
            return;
        }

        item = cJSON_GetObjectItem(req, "method");
        if (item!=NULL){
             cmd.method = item->valuestring;
        }else{
			ONENETLOG("cmdreq error: no method!\n");
            return;
        }

        if (strstr(cmd.method,CMD_SET) != NULL){
            item = cJSON_GetObjectItem(req, cmd.key);
            if (item->type == cJSON_Number){   
                cmd.vtype=vt_number;            
                cmd.value = &item->valueint;
            }else if (item->type == cJSON_False||item->type == cJSON_True){
                cmd.vtype=vt_bool;  
                cmd.value = &item->valueint;
            }else if (item->type == cJSON_String){
                cmd.vtype=vt_string;  
                cmd.value = item->valuestring;
            }
        }
        //命令处理回调函数
        if (!OneNETMQTTCmdCallback(&cmd)){
			ONENETLOG("OneNETMQTTCmdCallback error!\n");
            return;
        }

        //命令回复
        cJSON *resp;
        char *s = NULL;
        resp = cJSON_CreateObject();
        if (!resp)return;
        cJSON_AddStringToObject(resp, "uuid", cmd.uuid);
        if (strstr(cmd.method,CMD_GET) != NULL)
        {
            if (cmd.vtype == vt_number){
                cJSON_AddNumberToObject(resp,cmd.key,(double)*(int*)cmd.value);
            }else if (cmd.vtype == vt_bool){
                cJSON_AddBoolToObject(resp,cmd.key,*(int*)cmd.value);
            }else if (cmd.vtype == vt_string){
                cJSON_AddStringToObject(resp,cmd.key,(char*)cmd.value);
            }           
        }
        s = cJSON_PrintUnformatted(resp); 

		ONENETLOG("cmdack:%s\n", s);     
		
        if(req) cJSON_Delete(req);
        if(resp)	cJSON_Delete(resp);		
        
        if(s){       
            MQTTMessage message;
		    message.qos = MQTTQOS;
		    message.retained = 0;
		    message.payload = s;
		    message.payloadlen = strlen(s);
	        rc = MQTTPublish(&mqttdev->client, mqttdev->topic.cmd_dev_resp, &message);
            ONENETLOG("Command Response status: %d\n", rc);
        }
        return;
	}
}

/*@函数名@：bool OneNETMQTTSubscribeCmd()
 *@输  入@：cmdhandler  命令处理函数
 *@返  回@：
 *		false	失败
 *		true	成功
 *@功  能@：
 *		连接OneNET平台
 */
bool OneNETMQTTSubscribeCmd(messageHandler cmdhandler)
{
    int rc = 0;
    rc = MQTTSubscribe(&mqttdev->client, mqttdev->topic.cmd_dev_get, MQTTQOS, cmdhandler);
	ONENETLOG("Subscribed %d\n", rc);
    if (rc!=0) return false;
    return true;
}    

/*@函数名@：bool OneNETMQTTSubscribeCmd()
 *@输  入@：
 *@返  回@：
 *		false	失败
 *		true	成功
 *@功  能@：
 *		连接OneNET平台
 */
bool OneNETMQTTPublishData(char *buffer, int size)
{
    int rc = 0;
    MQTTMessage message;
	message.qos = MQTTQOS;
	message.retained = 0;
	message.payload = buffer;
	message.payloadlen = size;		
	rc = MQTTPublish(&mqttdev->client, mqttdev->topic.upload_dev_data, &message);
	if (rc!=0) {
		ONENETLOG("OneNETMQTTPublishData  %d\n", rc);
        return false;
	}
	ONENETLOG("OneNETMQTTPublishData  %2d %2d %2d %s\n",buffer[0],buffer[1],buffer[2], buffer+3);
    return true;
}    

/*@函数名@void OneNETMQTTReceiveDataMultiThread()
 *@输  入@：
 *@返  回@：
 *@功  能@：
 *		连接OneNET平台
 */
void* OneNETMQTTReceiveDataMultiThread(void* __this)
{
	while(1){
       MQTTYield(&mqttdev->client, TIME_OUT);//后台接收数据处理函数
	}
}    

/*@函数名@void OneNETMQTTReceiveDataSingleThread()
 *@输  入@：
 *@返  回@：
 *@功  能@：
 *		连接OneNET平台
 */
void* OneNETMQTTReceiveDataSingleThread()
{
    MQTTYield(&mqttdev->client, TIME_OUT);//后台接收数据处理函数
}    


//==========================================================
//	函数名称：	DSTREAM_toString
//
//	函数功能：	将数值转为字符串
//
//	入口参数：	StreamArray：数据流
//				buf：转换后的缓存
//				pos：数据流中的哪个数据
//				bufLen：缓存长度
//
//	返回参数：	无
//
//	说明：		
//==========================================================
void DSTREAM_toString(DataStream *streamArray, char *buf, unsigned short pos, unsigned short bufLen)
{

	memset(buf, 0, bufLen);

	switch ((unsigned char)streamArray[pos].dataType)
	{
	case TYPE_BOOL:
	    if(*(_Bool *)streamArray[pos].dataPoint > 0)
		{
			snprintf(buf, bufLen, "%s", "true");
		}
		else
		{
			snprintf(buf, bufLen, "%s", "false");
		}
		//snprintf(buf, bufLen, "%d", *(_Bool *)streamArray[pos].dataPoint);
		break;

	case TYPE_CHAR:
		snprintf(buf, bufLen, "%d", *(signed char *)streamArray[pos].dataPoint);
		break;

	case TYPE_UCHAR:
		snprintf(buf, bufLen, "%d", *(unsigned char *)streamArray[pos].dataPoint);
		break;

	case TYPE_SHORT:
		snprintf(buf, bufLen, "%d", *(signed short *)streamArray[pos].dataPoint);
		break;

	case TYPE_USHORT:
		snprintf(buf, bufLen, "%d", *(unsigned short *)streamArray[pos].dataPoint);
		break;

	case TYPE_INT:
		snprintf(buf, bufLen, "%d", *(signed int *)streamArray[pos].dataPoint);
		break;

	case TYPE_UINT:
		snprintf(buf, bufLen, "%d", *(unsigned int *)streamArray[pos].dataPoint);
		break;

	case TYPE_LONG:
		snprintf(buf, bufLen, "%ld", *(signed long *)streamArray[pos].dataPoint);
		break;

	case TYPE_ULONG:
		snprintf(buf, bufLen, "%ld", *(unsigned long *)streamArray[pos].dataPoint);
		break;

	case TYPE_FLOAT:
		snprintf(buf, bufLen, "%f", *(float *)streamArray[pos].dataPoint);
		break;

	case TYPE_DOUBLE:
		snprintf(buf, bufLen, "%f", *(double *)streamArray[pos].dataPoint);
		break;

	case TYPE_GPS:
		snprintf(buf, bufLen, "{\"lon\":%s,\"lat\":%s}", (char *)streamArray[pos].dataPoint, (char *)(streamArray[pos].dataPoint) + 24);
		break;

	case TYPE_LBS:
		snprintf(buf, bufLen, "{\"cid\":\"%s\",\"lac\":\"%s\",\"networktype\":%d,\"flag\":%d}",
			(char *)streamArray[pos].dataPoint, (char *)(streamArray[pos].dataPoint) + 8,
			*((unsigned char *)streamArray[pos].dataPoint + 16), *((unsigned char *)streamArray[pos].dataPoint + 17));
		break;

	case TYPE_STRING:
		snprintf(buf, bufLen, "\"%s\"", (char *)streamArray[pos].dataPoint);
		break;
	}

}


int OneNETMQTTStandardDataPacket(unsigned char type, DataStream *streamArray, unsigned short streamArrayCnt, char *buffer, int maxLen)
{

	int count = 0, numBytes = 0;								//count-循环计数。numBytes-记录数据装载长度
	char stream_buf[112];
	char data_buf[56];
	short cBytes = 0;

	char *dataPtr = buffer+3;

	for (; count < streamArrayCnt; count++)
	{
		if (streamArray[count].flag)
			break;
	}

	if (count == streamArrayCnt)
		return -1;

	count = 0;

	maxLen -= 1;												//预留结束符位置
	buffer[0] = type;
	switch (type)
	{
	// case FORMAT_TYPE1:

	// 	if (numBytes + 16 < maxLen)
	// 	{
	// 		memcpy(dataPtr, "{\"datastreams\":[", 16);
	// 		numBytes += 16;
	// 	}
	// 	else
	// 		return 0;

	// 	for (; count < streamArrayCnt; count++)
	// 	{
	// 		if (streamArray[count].flag)						//如果使能发送标志位
	// 		{
	// 			DSTREAM_toString(streamArray, data_buf, count, sizeof(data_buf));
	// 			snprintf(stream_buf, sizeof(stream_buf), "{\"id\":\"%s\",\"datapoints\":[{\"value\":%s}]},", streamArray[count].name, data_buf);

	// 			cBytes = strlen(stream_buf);
	// 			if (cBytes >= maxLen - numBytes)
	// 			{
	// 				//UsartPrintf(USART_DEBUG, "dStream_Get_dFormatBody Load Failed %d\r\n", numBytes);
	// 				return 0;
	// 			}

	// 			memcpy(dataPtr + numBytes, stream_buf, cBytes);

	// 			numBytes += cBytes;
	// 			if (numBytes > maxLen)						//内存长度判断
	// 				return 0;
	// 		}
	// 	}

	// 	dataPtr[numBytes] = '\0';							//将最后的','替换为结束符

	// 	if (numBytes + 1 <= maxLen)
	// 	{
	// 		memcpy(dataPtr + numBytes - 1, "]}", 2);
	// 		numBytes++;
	// 	}
	// 	else
	// 		return 0;

	// 	buffer[1] = (numBytes & 0xFF00)>>8;
	// 	buffer[2] = numBytes;

	// 	//printf("%d-%02X-%02X\tdataPtr is %s", buffer[0], buffer[1], buffer[2], buffer+3);
	// 	break;
	case FORMAT_TYPE2:
       
		if (streamArray[0].flag) 						//如果使能发送标志位
		{
			snprintf(stream_buf, sizeof(stream_buf), "{\"ds_id\":\"%s\"}", streamArray[0].name);

			cBytes = strlen(stream_buf);
			if (cBytes >= maxLen - numBytes-2)
			{
				return 0;
			}
            buffer[1] = (cBytes & 0xFF00)>>8;
		    buffer[2] = cBytes;

			memcpy(dataPtr + numBytes, stream_buf, cBytes);
			numBytes+=cBytes;

		} else {
			return 0;
		}

		if (streamArray[0].datalen >= maxLen - numBytes-4)
		{
			return 0;
		}

        dataPtr[numBytes] = (streamArray[0].datalen&0xFF000000)>>24;
		dataPtr[numBytes+1] = (streamArray[0].datalen&0x00FF0000)>>16;
		dataPtr[numBytes+2] = (streamArray[0].datalen&0x0000FF00)>>8;
		dataPtr[numBytes+3] = (streamArray[0].datalen&0x000000FF)>>0;
		numBytes+=4;
		memcpy(&dataPtr[numBytes],streamArray[0].dataPoint,streamArray[0].datalen);
		numBytes+=streamArray[0].datalen;

		break;

	case FORMAT_TYPE3:

		if (numBytes + 1 < maxLen)
		{
			memcpy(dataPtr, "{", 1);
			numBytes++;
		}
		else
			return 0;

		for (; count < streamArrayCnt; count++)
		{
			if (streamArray[count].flag) 						//如果使能发送标志位
			{
				DSTREAM_toString(streamArray, data_buf, count, sizeof(data_buf));
				snprintf(stream_buf, sizeof(stream_buf), "\"%s\":%s,", streamArray[count].name, data_buf);

				cBytes = strlen(stream_buf);
				if (cBytes >= maxLen - numBytes)
				{
					//UsartPrintf(USART_DEBUG, "dStream_Get_dFormatBody Load Failed %d\r\n", numBytes);
					return 0;
				}

				memcpy(dataPtr + numBytes, stream_buf, cBytes);

				numBytes += cBytes;
				if (numBytes > maxLen)						//内存长度判断
					return 0;
			}
		}

		dataPtr[numBytes] = '\0';							//将最后的','替换为结束符

		memcpy(dataPtr + numBytes - 1, "}", 1);

		buffer[1] = (numBytes & 0xFF00)>>8;
		buffer[2] = numBytes;
		break;

	// case FORMAT_TYPE4:
        
	// 	if (numBytes + 1 < maxLen)
	// 	{
	// 		memcpy(dataPtr, "{", 1);
	// 		numBytes++;
	// 	}
	// 	else
	// 		return 0;

	// 	for (; count < streamArrayCnt; count++)
	// 	{
	// 		if (streamArray[count].flag) 						//如果使能发送标志位
	// 		{
	// 			DSTREAM_toString(streamArray, data_buf, count, sizeof(data_buf));
	// 			snprintf(stream_buf, sizeof(stream_buf), "\"%s\":{\"2016-08-10T12:31:17\":%s},", streamArray[count].name, data_buf);

	// 			cBytes = strlen(stream_buf);
	// 			if (cBytes >= maxLen - numBytes)
	// 			{
	// 				//UsartPrintf(USART_DEBUG, "dStream_Get_dFormatBody Load Failed %d\r\n", numBytes);
	// 				return 0;
	// 			}

	// 			memcpy(dataPtr + numBytes, stream_buf, cBytes);

	// 			numBytes += cBytes;
	// 			if (numBytes > maxLen)						//内存长度判断
	// 				return 0;
	// 		}
	// 	}

	// 	dataPtr[numBytes] = '\0';							//将最后的','替换为结束符

	// 	memcpy(dataPtr + numBytes - 1, "}", 1);
	// 	buffer[1] = (numBytes & 0xFF00)>>8;
	// 	buffer[2] = numBytes;
	// 	break;

	case FORMAT_TYPE5:

		if (numBytes + 2 < maxLen)
		{
			memcpy(dataPtr, ",;", 2);
			numBytes += 2;
		}
		else
			return 0;

		for (; count < streamArrayCnt; count++)
		{
			if (streamArray[count].flag && streamArray[count].dataType != TYPE_GPS)	//如果使能发送标志位 格式5不支持GPS
			{
				DSTREAM_toString(streamArray, data_buf, count, sizeof(data_buf));
				snprintf(stream_buf, sizeof(stream_buf), "%s,%s;", streamArray[count].name, data_buf);

				cBytes = strlen(stream_buf);
				if (cBytes >= maxLen - numBytes - 2)
				{
					//UsartPrintf(USART_DEBUG, "dStream_Get_dFormatBody Load Failed %d\r\n", numBytes);
					return 0;
				}

				memcpy(dataPtr + numBytes, stream_buf, cBytes);

				numBytes += cBytes;
				if (numBytes > maxLen)						//内存长度判断
					return 0;
			}
		}
		buffer[1] = (numBytes & 0xFF00)>>8;
		buffer[2] = numBytes;

		break;

	default:
		break;
	}
	
	return numBytes+3;
}


