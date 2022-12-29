#ifndef ONENET_MQTT_CLIENT_H
#define ONENET_MQTT_CLIENT_H

#include "../PahoMQTTSDK/MQTTClient.h"
#include <stdbool.h>
#include "cJSON/cJSON.h"

/*-----------------------------------用户配置区上分界线-------------------------------*/
#define MODEL  "standard"           //standard:标准模式，customized:自定义模式
#define ServerHost	"10.12.4.25"   //mqtt接入机IP
//#define ServerPort	8899           //mqtt接入机端口
#define ServerPort	4433

#define DEVICE_ID	"51389"	// 设备ID   -  MQTT协议 ClientID，平台设备详情获取
#define PRODUCT_ID	"3021"	// 产品ID   -  MQTT协议 Username，平台产品详情获取
#define MASTER_KEY	 "MzVjZjdjMmYyOTVjYzJiYzZmNzM="  //  产品masterKey  -  MQTT协议 Password，平台产品详情获取
#define BUFFER_SIZE  2048   //读写缓存大小
#define TIME_OUT  1000   //读写超时时间
#define MQTTQOS  QOS0    //MQTT QOS，目前只支持QOS0和QOS1

/* 日志打印，用户可自定义日志输出 */
#define __ONENETLOG__   //调试总开关

#ifdef __ONENETLOG__
#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x
#define ONENETLOG(format,...) printf("******File: %s, Line: %05d******: "format"",filename(__FILE__), __LINE__, ##__VA_ARGS__)
#else
#define ONENETLOG(format,...)
#endif
/*-----------------------------------用户配置区下分界线-------------------------------*/

#define CMD_SET  "set"   
#define CMD_GET  "get"

#define StrStr(str1, str2) (unsigned char*)strstr(str1, str2)- (unsigned char*)str1
#define IsStrEquality(str1, str2) StrStr(str1, str2)==0?true:false

typedef struct 
{
	char*	product_id;	    //产品ID
	char*	device_id;	    //设备ID
	char*	master_key;		//masterkey
}DevInfo;

typedef struct 
{
	char*	host;
	int		port;
}Server;

typedef struct
{
	char* upload_dev_data;  //数据上报topic
	char* cmd_dev_get;      //命令接收topic
	char* cmd_dev_resp;	    //命令回复topic
}Topic;

typedef struct 
{
	DevInfo        devInfo;      //设备信息
	Server         mqttserver;   //mqtt broker信息
	Topic	       topic;        //topic
	Network        network;      //网络参数
	MQTTClient     client;       //MQTT客户端信息
}OneNetMqttDevice;

enum ValueType{vt_number = 1, vt_string, vt_bool};

typedef struct
{
	enum ValueType vtype;   //数据类型
	char* uuid;             //命令唯一id，用于返回校验
	char* method;           //”set“：写命令，”get“:读命令
	char* key;              //属性名
	void* value;		    //属性值
}Command;

typedef enum
{
	TYPE_BOOL = 0,

	TYPE_CHAR,
	TYPE_UCHAR,

	TYPE_SHORT,
	TYPE_USHORT,

	TYPE_INT,
	TYPE_UINT,

	TYPE_LONG,
	TYPE_ULONG,

	TYPE_FLOAT,
	TYPE_DOUBLE,

	TYPE_GPS,
	TYPE_LBS,

	TYPE_STRING,

	TYPE_BIN,

} DATA_TYPE;


typedef struct
{

	char *name;           //数据流名称，和平台产品功能定义中属性名对应
	void *dataPoint;      //数据
	DATA_TYPE dataType;   //数据类型
	int   datalen;        //二进制数据有效，string可用可不用。
	_Bool flag;           //上报使能，false数据被过滤不上报。

} DataStream;

//数据格式，目前只支持类型2，3，5
typedef enum
{
	FORMAT_TYPE2=2,
	FORMAT_TYPE3=3,
	FORMAT_TYPE5=5,
} FORMAT_TYPE;

/** OneNETMQTTDeviceInit - MQTT设备初始化
 *  @param dev - MQTT设备对象
 *  @return 无
 */
void OneNETMQTTDeviceInit(OneNetMqttDevice* dev);

/** OneNETMQTTConnect - MQTT设备连接平台
 *  @param 无
 *  @return 无
 */
bool OneNETMQTTConnect(void);

/** OneNETStanrdcmdHandler - 标准设备命令处理函数
 *  @param 无
 *  @return 无
 */
void OneNETStandardCmdHandler(MessageData* md);

/** OneNETMQTTSubscribeCmd - MQTT设备订阅平台命令
 *  @param  messageHandler 命令处理函数，标准设备调用OneNETStanrdcmdHandler，透传设备需用户自己定义命令处理函数。
 *  @return 无
 */
bool OneNETMQTTSubscribeCmd(messageHandler cmdhandler);

/** OneNETMQTTReceiveDataMultiThread - MQTT数据接受处理函数-多线程模式下单开线程调用
 *  @param 无
 *  @return 无
 */
void* OneNETMQTTReceiveDataMultiThread(void* __this);

/** OneNETMQTTReceiveDataSingleThread - MQTT数据接受处理函数-裸机单线程，需循环调用
 *  @param 无
 *  @return 无
 */
void* OneNETMQTTReceiveDataSingleThread();

/** OneNETMQTTStandardDataPacket - MQTT标准数据打包
 *  @param type 发送类型，支持type2，type3，type5
 *  @param streamArray 发送数据
 *  @param streamArrayCnt 发送数据个数
 *  @param buffer 发送缓存
 *  @param maxLen 发送缓存长度
 *  @return 无
 */
int OneNETMQTTStandardDataPacket(unsigned char type, DataStream *streamArray, unsigned short streamArrayCnt, char *buffer, int maxLen);

/** OneNETMQTTPublishData - MQTT发送数据
 *  @param buffer 发送缓存
 *  @param size 发送数据长度
 *  @return int  组包数据长度
 */
bool OneNETMQTTPublishData(char *buffer, int size);

/** OneNETMQTTPublishData - 标准设备命令处理回调函数，由调用者实现，uuid和method不变，读命令需返回类型和对应值
 *  @param cmd 命令接受以及返回结构体
 *  @return bool 命令处理结果，false则不回复平台
 */
extern bool OneNETMQTTCmdCallback(Command* cmd);

#endif