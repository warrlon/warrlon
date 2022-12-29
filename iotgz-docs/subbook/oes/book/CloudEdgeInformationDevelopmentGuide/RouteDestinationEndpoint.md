# 路由目的地端点

##  **新建目的地端点**

注意: 云端目的地端点需要测试连接通过才能添加。

点击**云边消息**>**路由目的地端点**>**添加路由目的地端点**
  ![](/images\oes\CloudEdgeInformationDevelopmentGuide\address.png)

### REST目的地端点

转发方式选择**REST**, 填入要转发数据的服务器地址，端口及路径。

 注：此处为自定义REST接口，只支持POST转发方式，由系统自动调用，并将数据传递到该接口进行处理。

![](/images\oes\CloudEdgeInformationDevelopmentGuide\address_rest.png)


### MQTT目的地端点

转发方式选择**MQTT**，填入要转发数据的MQTT服务器地址，端口，客户端标识（ClientID），用户名和密码以及MQTT的TOPIC。

![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_mqtt.png)

### KAFKA目的地端点

转发方式选择**KAFKA**, 填入要转发数据的KAFKA集群地址，多个地址以逗号分隔，以及KAFKA的TOPIC。
![](/images\oes\CloudEdgeInformationDevelopmentGuide\address_kafka.png)

### MYSQL目的地端点

转发方式选择**MYSQL**,填入要转发数据的MYSQL服务器地址，端口，用户名和密码，以及数据库和表名。

新建MYSQL时，如果数据库里没有输入的表名，则会自动创建输入的表的名称，表结构则是event类型的表，如果有则不创建，但是如果该表不符合event的表结构则会转发失败。

新建MYSQL类型目的地端点时，同时会连接数据库，检测其数据库参数是否正确，如果不能连接则创建不了该目的地端点。
  ![](/images\oes\CloudEdgeInformationDevelopmentGuide\address_mysql.png)

## 修改目的地端点

点击**云边消息**>**路由目的地端点**>想要修改的目的地端点行后面的**编辑**按钮。
![](/images\oes\CloudEdgeInformationDevelopmentGuide\address_edit.png)

点击后进入编辑页面，修改相应的目的地端点参数 , 编辑完成后点击**确定**按钮。
![](/images\oes\CloudEdgeInformationDevelopmentGuide\address_edit_detail.png)

a. 修改各目的地端点时，参数和新建的时候是一样的，但是执行任务不能更改。

b. 当目的地端点被消息路由实例引用且该消息路由已启用时，此目的地端点不能修改，

需要把启用的消息路由实例禁用后才能修改。

## 删除目的地端点

 点击**云边消息**>**路由目的地端点**>想要删除的目的地端点行后面的**删除**按钮。
 当该目的地配置被已启用的客户端使用时，不能删除，必须先删除路由实例。
 
   ![](/images\oes\CloudEdgeInformationDevelopmentGuide\address_delete.png)
