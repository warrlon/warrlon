# 数据源类型

> View 支持多种数据源类型

## OneNET数据
添加数据源时，选择`OneNET`；

登陆OneNET开发者中心，在 OneNET 上查找到产品 APIKey，OneNET View  将根据这个 APIKey 自动拉取该产品下面的设备及数据流；

选择设备及数据流后，一条 OneNET 数据源就创建完成。

## 静态JSON数据
添加数据源时，选择`静态数据`；

将正确的`JSON`格式数据，填写到数据栏，保存即可。

## 第三方API

> 您可以在View使用任何平台的API接口作为数据源接入。

View 的API接入类似于接口调试工具`postman`。

首先您需要知道API请求地址，鉴权方式以及所需参数及参数的值。您可以询问提供给您API的开发人员获取这些信息。

目前，我们支持使用`GET`、`POST`方式来请求第三方API。

#### 接口路径
接口路径填写URL，当检测到您填写的 URL 中包含Query参数时，系统会自动将它们解析到Query列表中。
#### Query
这里代表的含义类似于http://aaa.com/user?name=sx&pass=111 这个地址中的name=sx&pass=111这样的参数。
#### Header
Header列表中的配置，会被拼成HTTP请求时的自定义头部，通常，我们可以在Header中填写鉴权信息。
#### Body
当我们切换请求方式到POST时，会出现Body这个标签页。目前仅支持以键值对形式（key-value)组织请求Body。
