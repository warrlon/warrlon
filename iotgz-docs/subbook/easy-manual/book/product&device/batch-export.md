# 批量导出设备

平台提供批量导出工具，应对需要批量导出设备的场景

使用步骤如下

### Step 1 

下载导出工具包，请点击[下载链接](https://codeload.github.com/cm-heclouds/onenet_device_export/zip/master)

    仅支持Windows操作系统

### Step 2 

修改配置文件，用编辑app.conf中的api-key改为用户的api-key

    注意“(your api-key)”的括号不应保留

 配置文件修改示例如下：


```
[onenet]
url=http://api.heclouds.com
apiKey=T14Rq2Ovjs9d12bc30aplyeLeU=

[search]
key_words=my
auth_info=203x1
tag=mobile
online=ture
private=false
begin=
end=
[app]
goroutine=20
```

参数说明：

|参数名称|说明|是否必填|
|:-|:-|:-|
|apiKey|产品的Master-APIkey，产品概况页可见，形如T14Rq2Ovjs9d12bc30aplyeLeU=|必填|
|key_words|匹配关键字,形如key_words=my, 匹配关键字，从id和title字段中左匹配|选填|
|auth_info|鉴权信息，形如auth_info=203x1 ，对应注册时的sn参数，唯一设备编号|选填|
|tag|通过接口或者页面添加的设备标签，形如tag=mobile |选填|
|online|在线状态，布尔值，形如online=true/false|选填|
|private|是否私有，布尔值，形如private=true/false /|选填|
|begin|起始时间，形如begin=2016-06-20 //起始时间，包括当天|选填|
|end|end=结束时间，形如2016-06-20 //结束时间，包括当天|选填|

### Step 3

双击执行exe程序，将自动生成批量导出设备的Excel文件，根据设备量不同耗时不同，请等待；

