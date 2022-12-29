#include "../OneNETMqttClient/OneNETMqttClient.h"
#include <pthread.h>


#define INTEGER_NAME "integer"
#define STRING_NAME "str_test"


OneNetMqttDevice dev;   //定义设备
char mqttpayload[2048];   //payload缓存大小
pthread_t mqtt_RecvData_id;    //接收数据处理进程

int number = 1;
char strdata[200] = "test";
char bindata[200] = {0x11,0x12,0x13,0x14,0x15};
DataStream testdata[2];
DataStream bindatastream;

//标准类型数据初始化
void DataInit(){
	testdata[0].dataPoint = &number;
	testdata[0].name = INTEGER_NAME;
	testdata[0].dataType = TYPE_INT;
	testdata[0].flag = true;
	testdata[1].dataPoint = strdata;
	testdata[1].name = STRING_NAME;
	testdata[1].dataType = TYPE_STRING;
	testdata[1].flag = true;
	bindatastream.dataPoint = bindata;
	bindatastream.name = "bindata";
	bindatastream.dataType = TYPE_BIN;
	bindatastream.datalen = 5;
	bindatastream.flag = true;
}



//标准设备命令处理回调函数，如需使用命令功能，则必须实现该函数处理命令
bool OneNETMQTTCmdCallback(Command* cmd){
	
	if (strstr(cmd->method,CMD_GET) != NULL)  //读命令
	{
		if (strstr(cmd->key,INTEGER_NAME) != NULL)
		{
		   cmd->vtype = vt_number;       //返回对应数据类型
	       cmd->value = &number;       //返回对应数据值
		} 
		else if (strstr(cmd->key,STRING_NAME) != NULL)
		{
			cmd->vtype = vt_string;
			cmd->value = strdata;
		}					
	} 
	else if (strstr(cmd->method,CMD_SET) != NULL)  //写命令
	{
		if (strstr(cmd->key,INTEGER_NAME) != NULL)
		{
	       number = *(int*)(cmd->value);      //设置数字命令
		} 
		else if (strstr(cmd->key,STRING_NAME) != NULL)
		{
			memset(strdata,0,sizeof(strdata));          //设置字符串命令
			memcpy(strdata,(char*)(cmd->value),strlen((char*)(cmd->value)));
		}	
	}
	return true;	
}


void main(void){
    
	int rc = 0;
	//初始化设备
    OneNETMQTTDeviceInit(&dev);

    //连接平台
	if(!OneNETMQTTConnect())  goto exit;


	//订阅平台命令
	if(!OneNETMQTTSubscribeCmd(OneNETStandardCmdHandler))  goto exit;
	
	//创建线程，定时循环接受数据
	pthread_create(&mqtt_RecvData_id, NULL, OneNETMQTTReceiveDataMultiThread, NULL);
    
	DataInit();

	while(1){
	    int lenth = 0;
        number++;
        sleep(10);
        
		//标准数据上报
        lenth = OneNETMQTTStandardDataPacket(FORMAT_TYPE3, testdata, sizeof(testdata)/sizeof(DataStream), mqttpayload, sizeof(mqttpayload));
        if(!OneNETMQTTPublishData(mqttpayload, lenth)) goto exit;		

        //二进制数据上报，二进制数据只能用FORMAT_TYPE2单个传输
		//lenth=OneNETMQTTStandardDataPacket(FORMAT_TYPE2,&bindatastream,1,mqttpayload,2048);
        //if(!OneNETMQTTPublishData(mqttpayload, lenth)) goto exit;
	}
exit:
    //断开设备连接和网络
	MQTTDisconnect(&dev.client);
	NetworkDisconnect(&dev.network);
}

