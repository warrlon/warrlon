<h1>检测token有效</h1>

请求方式：**GET**

URL: http://ota.heclouds.com/ota/south/download/{token}/check

> 用户在设备升级过程中，根据需要使用此API，属于可选操作。

[我只想看示例！！！](#1)

#### http头部 
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
Content-Type | string | 是 | 必须为application/json
Authorization | string | 是 | 安全鉴权信息


#### http 请求参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
dev_id | long | 是 | 设备id

#### 返回参数
参数名称 | 格式 |  说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功


#### 错误码说明

<table>
<tr><th width="20%">错误码</th><th>说明</th></tr>
<tr><td>0</td><td>有效。</td></tr>
<tr><td>4</td><td>token和did不一致。</td></tr>
<tr><td>7</td><td>OneNET内部错误。</td></tr>
<tr><td>12</td><td>token过期，设备升级流程结束。</td></tr>
<tr><td>17</td><td>无效的状态，只有当设备的升级任务处于待升级和下载中时，才可以进行token校验，其他状态不支持token校验。</td></tr>
<tr><td>20</td><td>升级任务结束，设备升级流程结束。</td></tr>
<tr><td>21</td><td>无效操作，sdk逻辑错误。</td></tr>
<tr><td>22</td><td>升级任务被取消，无需上报升级失败。</td></tr>
</table>

#### 说明

1、设备通过任务检查接口获得任务信息后，需要通过token检测接口进行token检查（因为token存在2天有效期）；

2、token检测接口调用成功后，平台会将设备升级任务从“待升级”状态转变为“正在下载”状态。


<h4 id="1">返回示例</h4>

```json
{
	"errno": 0,
	"error": "succ"

}
```

<div>
    <a href="/book/develop/south-API/1task.md">
        <span> &#171; 上一篇：2-检查设备升级任务</span>
        </a>
		</div>
<div>
    <a href="/book/develop/south-API/4report_process.md">
        <span> &#187; 下一篇：4-下载资源</span>
    </a>
</div>

