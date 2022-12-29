# 开发实例

本demo主要以 **C语言** 为例，介绍在Linux平台下实现设备的接入。

## 准备条件

- 请确定本地已正确安装Linux环境，cmake项目构建工具(最低2.8版本)、gcc编译工具，本示例使用 `Ubuntu 14.04.3`。

- 本Demo依赖以下第三方库，请正确安装，本示例默认安装路径为 `/usr/local/`：

  ```
  openssl-OpenSSL_1_0_2q，paho.mqtt.c-1.3.0（编译paho时需打开PAHO_WITH_SSL选项）
  ```

- 请确定已正确创建产品及设备。

## 操作步骤

1. 登录Linux虚拟机。

2. 下载获取[demo工程](/images/tools/mqtts-c-demo.zip)。

3. 使用命令完成解压，解压后可以看到Linux本地新增 *OneNET-MQTT-demo-c* 文件夹。文件详细信息如下：

   ```python
   OneNET-MQTT-demo-c
   |- cert            #mqtts证书所在目录
       |- certificate.pem
   |- CmakeLists.txt  #构建cmake工程	
   |- busi.h          #用户具体业务循环函数声明
   |- call-back.h     #用户设定connection lost、下行数据回调声明
   |- mqtts-client.h  #mqtts-client头文件
   |- utils.h         #base64编解码、hmac_sha1、url_encode函数声明
   |- token.h         #计算鉴权token的函数声明
   |- types.h         #topic及dp payload format声明
   |- mqtts-sample.c  #主程序
   |- mqtts-client.c  #mqtts-client客户端创建、销毁、subscribe等函数实现
   |- token.c         #计算鉴权token的函数实现
   |- call-back.c     #connection lost、下行数据回调实现
   |- busi.c          #用户具体业务实现
   |- utils.c         #base64编解码、hmac_sha1、url_encode函数实现
   |- types.c         #topic及dp payload format定义
   ```


4. 在通过示例代码与物联网平台通信之前，需要将`mqtts-samples.c`中的设备参数修改为您已创建成功的设备信息，完成后保存退出。

   如下所示，在此处填入**产品ID**、**设备名称**、**设备key**。

   ```c
   /*设备所属产品*/   
   const char *pid = "您的产品ID";
   /*设备名称*/
   const char *device_name = "您的设备名称";
   /*设备级的access key*/
   const char *device_access_key ="您的设备Key";
   ```

   用户可根据需要自定义token的访问有效期（即过期时间），本示例默认为2019-12-31日。

   ```c
   /*token过期时间,请按照实际具体需求计算token过期时间,本例中为从1970-1-1到2019-12-31的秒数*/
   int64_t expire_time = 1577721600;
   ```

5. 修改完成后在示例代码目录，执行cmake命令，生成makefile文件。

   ```shell
   cmake .
   ```

6. 通过make指令编译示例程序。

   ```shell
   make clean
   make
   ```

   生成的示例程序`mqtts-sample`存放在当前目录下。

7. 运行示例程序。在控制台显示设备上线。此时，设备与物联网平台成功连接。

   ```shell
   ./mqtts-sample
   ```

   - 设备上线成功后，会自动向物联网平台上传数据点。在终端控制台返回信息：

   ```shell
   [datapoint] receive dp accepted response from OneNET...
   ```

   - 本示例默认上传的数据，您可以在 **设备列表**-**数据流展示** 进行查看，获取具体内容。

   ![image](/images/MQTTS/cdemo/数据流.png)

   ![image](/images/MQTTS/cdemo/数据点.png)

8. 在本示例中，除数据点上传外，也可以实现物联网平台下发命令控制设备。您可以在设备列表中，选择 **更多操作**-**下发命令** 完成设备命令的下发。

   ![image](/images/MQTTS/cdemo/命令下发.png)

   - 在命令成功下发后，在终端控制台返回信息，其中`payload`字段为下发命令内容的16进制转换结果。

   ```
   [cmd] receive cmd from OneNET
   	cmduuid:59aba784-ee98-4620-84b0-b8744fd4ad74
   	payload:54 68 69 73 69 73 61 74 65 73 74 6D 65 73 73 61 67 65 2E 
   ```

   - 在命令成功下发至设备后，设备会返回成功接收信息至物联网平台，平台会显示返回结果。

   ![image](/images/MQTTS/cdemo/命令应答.png)

   - 在设备成功接收物联网下发命令后，终端控制台会返回信息。

   ```
   [cmd] OneNET accept the cmd[59aba784-ee98-4620-84b0-b8744fd4ad74] response...
   ```
