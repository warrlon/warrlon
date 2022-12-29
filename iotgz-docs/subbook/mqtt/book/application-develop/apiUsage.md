# API使用

平台提供开放的API接口，用户可以通过 HTTP / HTTPS 调用（**推荐使用 HTTPS**），进行设备管理，数据查询，设备命令交互等操作，在API的基础上，根据自己的个性化需求搭建上层应用

## API服务地址

API地址为：**api.heclouds.com**


## API鉴权

为提高API访问安全性，OneNET API的鉴权参数作为**header**参数存在

MQTT物联网套件中以accessKey为核心密钥，用户需要使用核心密钥通过签名算法计算签名，与其他参数共同组成token，然后将token作为请求Header参数进行鉴权，见[token算法](/book/manual/auth/token.md)

token 示例如下：
    
    version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D
    

#### 调用示例
**（以“查询设备详情API”为例）**

```
GET /devices/3532392 
Authorization: version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

```
## API返回

API返回内容中，HTTP状态码进行如下分类：

<table>
<tr><th width="30%">HTTP状态码</th><th>状态码说明</th></tr>
<tr><td>2xx</td><td>执行成功</td></tr>
<tr><td>4xx</td><td>客户端的错误，通常情况下客户端需要修改请求然后再次发送请求</td></tr>
<tr><td>5xx</td><td>服务端的错误</td></tr>
</table>

API返回内容如下所示：

```json
{
    "request_id": "855b2fe4-3f54-41f2-8cd5-3e34bcfa8356",
    "code_no"："000000",
    "code"："onenet_common_success",
    "message"："success",
    "data":{}   /* 返回结果数据 */
}
```

其中，固定参数说明如下：

<table>
<tr><th width="30%">参数</th><th>参数说明</th></tr>
<tr><td>request_id</td><td>平台为每次请求分配的唯一ID</td></tr>
<tr><td>code_no</td><td>错误码</td></tr>
<tr><td>code</td><td>错误码说明</td></tr>
<tr><td>message</td><td>错误码详情</td></tr>
<tr><td>data</td><td>请求返回数据内容</td></tr>
</table>

错误码相关说明，请见[错误码详情](/book/application-develop/errorCode.md)