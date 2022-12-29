OneNET Studio OTA使用规范

功能概述

平台提供远程升级功能，用户可以通过平台管理升级包，添加设备升级任务，查看设备升级状态等，方便用户对设备进行升级等操作，升级流程如下：

  ![升级流程图](/book/devops&monitor/images/升级流程.jpg)

1、升级包管理

  1.1 登录OneNET Studio控制台，左侧导航栏选择 **运维监控\>远程升级**。

  1.2 在**升级包管理**标签页，单击**添加升级包**

  ![](/book/devops&monitor/images/添加升级包.png)    

  1.3 设置升级包参数，单击添加

  ![](/book/devops&monitor/images/添加升级包参数.png)
        
    | 参数       | 说明                                               |
    |------------|----------------------------------------------------|
    | 升级包类型 | 根据升级包是完整包或者差分包，选择对应的类型       |
    | 升级包名称 | 1-20个中文、英文、数字、下划线、连接符、点号、括号 |
    | 所属产品   | 选择将升级包挂在某个产品下                         |
    | 升级模块   | 根据升级包需要升级的版本选择模组固件或者MCU软件    |
    | 目标版本   | 1-20英文、数字、点号、连接符和下划线               |
    | 升级包描述 | 不超过100个字符，一个中文计为一个字符              |

  1.4 验证升级

    在进行批量升级之前，可以使用一个测试设备对升级包进行验证升级，保证升级包的可用性。

  ![验证升级](/book/devops&monitor/images/验证升级.png)

    | 参数         | 说明                                                                                                                 |
    |--------------|----------------------------------------------------------------------------------------------------------------------|
    | 待升级版本号 | 下拉框会显示指定产品下设备版本列表，如果设备没有上报过版本号，可以**选择未上传版本**                                 |
    | 通知方式     | 平台下发通知：仅支持MQTT和NB协议，将会给设备下发升级任务的命令 升级任务推送通知：将给配置的url服务中推送一个任务信息 |

  > 备注，设备上报版本：

    ```
    POST http://studio-ota.heclouds.com/ota/{pro_id}/{dev_name}/version
    
    Content-Type: application/json
    
    Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
    
    host:studio-ota.heclouds.com
    Content-Length:20
    
    {"s_version":"V1.3", "f_version": "V2.0"}
    
    ```
   
   响应结果如下：
   
   ![响应结果](/book/devops&monitor/images/上报版本号.jpg)

  > 用户也可以点击**跳过验证**

  ![](/book/devops&monitor/images/跳过验证.jpg)

  添加验证后，需要对所选择设备进行验证升级，流程和正式设备流程相同，如下一同讲解。

  验证通过后，升级包将被标识为"已验证"

  ![](/book/devops&monitor/images/已验证.png)

2、 设备升级任务管理

  2.1 添加升级任务

  在批次列表标签中，点击操作栏的取消升级，可以取消所有待升级、升级中的设备升级任务或者只取消尚未开始升级的定时任务。

  ![](/book/devops&monitor/images/添加升级任务.png)

  | 参数         | 描述                                                                                 |
  |--------------|--------------------------------------------------------------------------------------|
  | 待升级版本号 | 下拉框会显示指定产品下设备版本列表，如果设备没有上报过版本号，可以**选择未上传版本** |


  2.2 查看升级任务批次信息

  完成批量添加设备升级任务后，可以在升级包管理标签页中对应的升级包点击**查看**，查看所添加的升级批次信息。

  ![查看升级批次](/book/devops&monitor/images/查看升级批次.jpg)

  2.3 查看指定批次升级任务信息

  在**批次列表**标签中，选择指定批次操作栏的**查看**标签，可以查看到该批次中所有设备的升级任务信息。

  ![查看指定批次设备升级任务信息](/book/devops&monitor/images/查看升级批次任务信息.jpg)

  ![指定批次升级任务列表](/book/devops&monitor/images/指定批次升级任务列表.jpg)

  2.4  取消升级任务

  2.4.1  按批量取消升级

  在批次列表标签中，点击操作栏的取消升级，可以取消所有待升级、升级中的设备升级任务或者只取消尚未开始升级的定时任务。

  ![](/book/devops&monitor/images/按批次取消升级任务.jpg)
  
  点击"取消"后，批次状态将标识为"取消"状态
  
  ![批次显示为取消](/book/devops&monitor/images/批次显示为取消状态.jpg)

  2.4.2  按设备取消升级

  在批次详情标签中，可以根据设备升级任务状态选择取消指定设备的升级任务。
  
  ![指定设备升级任务](/book/devops&monitor/images/指定取消设备升级任务.jpg)
  
  取消后，设备任务状态将标识为"升级失败"
  
  ![设备显示为取消状态](/book/devops&monitor/images/设备显示为取消状态.jpg)
  
  3.1 设备检测升级任务

   以上四步完成后，设备升级任务已建成功，现在需要终端设备到平台检测升级任务，获取任务信息。

    ```
    GET http://studio-ota.heclouds.com/ota/{pro_id}/{dev_name}/check?type=1&version=1.2
    Content-Type: application/json
    Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
    host:studio-ota.heclouds.com
    Content-Length:20
    ```
    
   响应结果如下：
    
   ![检查升级任务](/book/devops&monitor/images/检查升级任务.jpg)

  3.2 下载升级包
    检查到升级任务后，设备根据任务信息进行升级包下载

    ```
      GET http://studio-ota.heclouds.com/ota/{pro_id}/{dev_name}/{tid}/download
      Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
      host:studio-ota.heclouds.com
    ```
  3.3 上报设备升级状态
    设备可以根据升级包的下载情况，上报下载进度和下载结果
    
    ```
    POST http://studio-ota.heclouds.com/ota/{pro_id}/{dev_name}/{tid}/status
    Content-Type: application/json
    Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
    host:studio-ota.heclouds.com
    Content-Length:20
    
    {"step":10} 
    ```                                                                             |
  响应结果如下：
   
  ![上报进度](/book/devops&monitor/images/上报进度.jpg)

  3.4 检测设备任务状态
    设备可以随时查询任务的状态，根据状态进行相应操作
    
    ```
    GET http://studio-ota.heclouds.com/ota/{pro_id}/{dev_name}/{tid}/check
    Content-Type: application/json
    Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
    host:studio-ota.heclouds.com
    Content-Length:20
    ```
  响应结果如下：
  
  ![检查设备状态](/book/devops&monitor/images/检测任务状态.jpg)
    
  3.5 查看设备版本号
    设备可以查询当前版本号
    
    ```
      GET http://studio-ota.heclouds.com//ota/{pro_id}/{dev_name}/version  
      Content-Type: application/json
      Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
      host:studio-ota.heclouds.com
      Content-Length:20
    ```
  响应结果如下：
  
  ![查询版本号](/book/devops&monitor/images/查询版本号.jpg)