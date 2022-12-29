#include "../OneNETMqttClient/OneNETMqttClient.h"
#include <pthread.h>

OneNetMqttDevice dev;   //定义设备
char mqttpayload[2048];   //payload缓存大小
pthread_t 	mqtt_RecvData_id;    //接收数据处理进程

int number = 1;
char strdata[200] ="test";
char bindata[200] ={0x11,0x12,0x13,0x14,0x15};


int UserCustomizedDataPacket(){
	//用户自己实现数据组包
}

void UserCustomizedCmdHandler(MessageData* md){
    //用户自己实现命令解析，业务处理，命令回复逻辑，可参考标准命令处理流程
}

void main(void){
    
	int rc = 0;
	//初始化设备
    OneNETMQTTDeviceInit(&dev);

    //连接平台
	if(!OneNETMQTTConnect())  goto exit;

	
	//订阅平台命令
	if(!OneNETMQTTSubscribeCmd(UserCustomizedCmdHandler))  goto exit;

	//创建线程，定时循环接受数据
	pthread_create(&mqtt_RecvData_id, NULL, OneNETMQTTReceiveDataMultiThread, NULL);
    
	while(1){
	    int lenth=0;
        number++;
        sleep(10);        
		//标准数据上报
        lenth=UserCustomizedDataPacket();
        if(!OneNETMQTTPublishData(mqttpayload, lenth)) goto exit;

	}
exit:
    //断开设备连接和网络
	MQTTDisconnect(&dev.client);
	NetworkDisconnect(&dev.network);
}
