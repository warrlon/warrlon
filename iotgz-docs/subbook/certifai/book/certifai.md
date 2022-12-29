# API接口文档

## API调用

### API鉴权
实名认证采用OneNET统一的[安全鉴权](https://open.iot.10086.cn/doc/easy-manual/book/auth.html)。其中res参数固定为ai-registration

### 获取实名认证服务URL

**请求方式:**
```
POST URL: http(s)://api.heclouds.com/real_name_reg/auth_url
```

- **header参数**
<a name="table20200422000"></a>
<table>
<thead valign="left">
<tr id="row202004220000">
<th class="cellrowborder" valign="top" width="20%"><p>参数名称</p></th>
<th class="cellrowborder" valign="top" width=""><p></a>参数值</p></th>
</tr>
</thead>
<tbody>
<tr id="row202004220001">
<td><p>Authorization</p></td>
<td><p>参见<a href="https://open.iot.10086.cn/doc/easy-manual/book/auth.html">安全鉴权</a> </p></td>
</tr>
<tr id="row202004220002">
<td><p>Content-Type</p></td>
<td><p>application/json</p></td>
</tr>
</tbody>
</table>

- **body参数**
<a name="table20200422002"></a>
<table>
<thead valign="left">
<tr id="row2020042200020">
<th class="cellrowborder" valign="top" width="20%"><p>参数名称</p></th>
<th class="cellrowborder" valign="top" width="20%"><p></a>格式</p></th>
<th class="cellrowborder" valign="top" width="20%"><p></a>是否必填</p></th>
<th class="cellrowborder" valign="top" width="40%"><p></a>说明</p></th>
</tr>
</thead>
<tbody>
<tr id="row202004220021">
<td><p>user_id</p></td>
<td><p>int</p></td>
<td><p>是</p></td>
<td><p>用户在OneNET平台的uid</p></td>
</tr>
<tr id="row202004220022">
<td><p>phone</p></td>
<td><p>string</p></td>
<td><p>是</p></td>
<td><p>进行实名认证的用户的手机号</p></td>
</tr>
<tr id="row202004220023">
<td><p>callback_url</p></td>
<td><p>string</p></td>
<td><p>是</p></td>
<td><p>实名认证结果接收地址</p></td>
</tr>
</tbody>
</table>

- **返回参数**
<a name="table20200422001"></a>
<table>
<thead valign="left">
<tr id="row2020042200010">
<th class="cellrowborder" valign="top" width="20%"><p>参数名称</p></th>
<th class="cellrowborder" valign="top" width="20%"><p></a>格式</p></th>
<th class="cellrowborder" valign="top" width=""><p></a>说明</p></th>
</tr>
</thead>
<tbody>
<tr id="row202004220011">
<td><p>errno</p></td>
<td><p>int</p></td>
<td><p>调用错误码，为0表示调用成功</p></td>
</tr>
<tr id="row202004220012">
<td><p>error</p></td>
<td><p>string</p></td>
<td><p>错误描述，为"succ"表示调用成功</p></td>
</tr>
<tr id="row202004220013">
<td><p>data</p></td>
<td><p>json</p></td>
<td><p>接口调用成功之后返回的相关信息，见data描述表</p></td>
</tr>
</tbody>
</table>

- **Data描述表**
<a name="table20200422002"></a>
<table>
<thead valign="left">
<tr id="row2020042200020">
<th class="cellrowborder" valign="top" width="20%"><p>参数名称</p></th>
<th class="cellrowborder" valign="top" width="20%"><p></a>格式</p></th>
<th class="cellrowborder" valign="top" width=""><p></a>说明</p></th>
</tr>
</thead>
<tbody>
<tr id="row202004220021">
<td><p>busi_seq</p></td>
<td><p>string</p></td>
<td><p>业务流水号，每次实名认证请求唯一标识</p></td>
</tr>
<tr id="row202004220022">
<td><p>auth_url</p></td>
<td><p>string</p></td>
<td><p>实名认证URL，用户实名认证引导页地址</p></td>
</tr>
</tbody>
</table>

- **示例代码** 

HTTP请求
```
POST https://api.heclouds.com/real_name_reg/auth_url 
Authorization: version=2018-10-31&res=ai-registration&et=1595385530&method=sha1&sign=5ydHlfsQ%2BOLvcGWieEDkLBOXQs8%3D
Content-Type: application/json
```
HTTP请求参数
```
{
    "user_id": 38453,
    "phone": "15522223333",
    "callback_url": "http://api.heclouds.com/callback"
}
```
HTTP响应
```
{
    "errno": 0,
    "error": "succ",
    "data": {
        "auth_url": "http://127.0.0.1:9090/edcreg/standardWeChat/signTheCheck?requestSource=230030&transactionID=23003020200411180717000126&param=06e01f3d477ad7ebec35220db228b8fc139529437946c5c9c4f4a801feeb0119df9d766fa602b7bb477ffa31b0bbbf89dab80af432e4b4a008954ae9a43322fce22d145aaddb71b6fac8320be3057fe8df0bc4fe3db14c6938e0ad27ddd7a754ec85e186858e8c902257101015fd09656c4a96f49aee56e2132a4972752f2a41a4e9f5dc21fc73b4&signature=cMeFJcsDDZfuPD2LbnwQ7bxt6Ab0%2BAalfyWfXBxQYaZkhKboY%2BGd9h1%2FM69Au%2F9HnoggW1sY9EUHhDcwJoAyOlHX%2FLo%2FLdekOJ1PsrQzFq4rKf0yEqb36PODEEa4H0Q1ObhD1DOMKqFGX9fs3bkkGzAgMqt3gV4CW1Q9IVG2B8DKfgcbVOyvz2XlxyjN4n%2FJDDRCOWK6adxJ%2FIQGxtHkkNHqryCWLWrF415Umka4c6iU9yuNGJ3rE2uA3iBX1a6KToqQzjep5uLupd5crK1XXSydEF%2FkBUuTfOdrktce4J6yo5rb04wejNmEGhJTi6ahGXhFOAOR026mgAAVBVuRUw%3D%3D",
        "busi_seq": "OneNET20200411180717000126"
    }
}
```

### 实名认证结果推送
**请求方式:**
```
POST URL: http(s):xxx.xxx(获取实名认证服务URL接口中指定的callback_url参数)
```

- **HTTP请求参数**

| 父节点 | 参数名称 | 格式 | 说明 |
| :--: | :--: | :--: | :--: |
|auditResult|auditStatus|string|0：认证通过 1：认证待审核 2：认证不通过 3：二次稽查通过 4：二次稽查不通过|
||transactionID|string|业务流水|
||busiSeq|string|请求业务流水（同发起认证流水号）|
||phone|string|发起认证手机号|
||responseTime|int|响应时间(Unix时间戳)|
||auditMessage|string|认证失败原因|
|auditInfo|custName|string|证件人员姓名|
||custCertNo|string|证件号|
||custCertAddr|string|家庭住址|
||gender|string|性别：0: 女 1:男|
||nation|string|名族|
||birthday|int|生日(Unix时间戳)|
||issuingAuthority|string|证件签发机关|
||certValidDate|int|证件生效时间(Unix时间戳)|
||certExpDate|int|证件失效时间(Unix时间戳)|
||createTime|int|不需关注(Unix时间戳)|
||modifyTime|int|不需关注(Unix时间戳)|
||busiSeq|string|请求业务流水|
||channelId|string|发起方渠道标识|

- **HTTP响应**

**注意**：只有当接口返回以下响应时，OneNET平台认为实名认证结果推送成功，否则，重试请求三次（重试时间为3秒、6秒、12秒）
```
{
    "errno": 0,
    "error": "succ"
}
```

<a name="table20200422003"></a>
<table>
<thead valign="left">
<tr id="row2020042200030">
<th class="cellrowborder" valign="top" width="20%"><p>参数名称</p></th>
<th class="cellrowborder" valign="top" width="20%"><p></a>格式</p></th>
<th class="cellrowborder" valign="top" width=""><p></a>说明</p></th>
</tr>
</thead>
<tbody>
<tr id="row202004220031">
<td><p>errno</p></td>
<td><p>int</p></td>
<td><p>调用错误码，为0表示调用成功</p></td>
</tr>
<tr id="row202004220032">
<td><p>error</p></td>
<td><p>string</p></td>
<td><p>错误描述，为"succ"表示调用成功</p></td>
</tr>
</tbody>
</table>

- **示例代码**
```
{
    "auditResult": {
        "auditStatus": "0",
        "transactionID": "23003020200404161716000047",
        "busiSeq": "OneNET20200408231042000087",
        "phone": "12345678901",
        "responseTime": 1583570441871,
        "auditMessage": "认证成功"
    },
    "custInfo": {
        "custName": "六三",
        "custCertNo": "50010419999033025000",
        "custCertAddr": "重庆市大渡口区",
        "gender": "1",
        "nation": "汉",
        "birthday": 1583570441871,
        "issuingAuthority": "重庆市渝北区双凤桥公安局",
        "certValidDate": 1583570441871,
        "certExpDate": 1583570441871,
        "createTime": 1583570441871,
        "modifyTime": 1583570441871,
        "busiSeq": "OneNET20200404161716000047",
        "channelId": "OneNET"
    }
}
```
