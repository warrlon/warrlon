# API使用

平台提供开放的API接口，用户可以通过HTTP/HTTPS调用，进行设备管理，数据查询，设备命令交互等操作，在API的基础上，根据自己的个性化需求搭建上层应用

## API鉴权

为提高API访问安全性，物联平台 API的鉴权参数作为**header**参数存在

物联平台支持普通以及安全两种鉴权认证方式，对比如下表：

<table>
<tr><th width="20%"> </th><th width="40%">普通</th><th>安全（推荐）</th></tr>
<tr><td>核心密钥</td><td>apiKey</td><td>accessKey</td></tr>
<tr><td>header参数名</td><td>"api-key"</td><td>"Authorization"</td></tr>
<tr><td>header参数值</td><td>apiKey（直接传输密钥）</td><td>由参数组构成的token，不含密钥</td></tr>
<tr><td>访问时间控制</td><td>不支持</td><td>支持（由参数组中参数控制访问时效）</td></tr>
<tr><td>自定义权限</td><td>不支持</td><td>支持（即将到来）</td></tr>
<tr><td>核心密钥更新</td><td>不支持</td><td>支持（即将到来）</td></tr>
<tr><td>HTTPS</td><td>支持</td><td>支持</td></tr>
<tr><td>安全性</td><td>较低</td><td>较高</td></tr>
</table>

### 普通鉴权

普通鉴权方式通过apiKey作为鉴权密钥，apiKey分为两个访问层级：产品级（Master）与设备级
<table>
<tr><th width="15%"> </th><th width="40%">产品级</th><th>设备级</th></tr>
<tr><td>数量</td><td>产品下唯一</td><td>产品下可以有多个</td></tr>
<tr><td>权限范围</td><td>产品下所有资源的操作，包括：<br>设备、数据流、数据点、触发器、文件、命令以及设备apiKey</td><td>部分设备的全量操作，包括<br>设备详情，设备数据流，设备数据点</td></tr>
<tr><td>自定义权限</td><td>不支持</td><td>支持设备级<br>需要用户进行apiKey与设备的关联操作，一旦关联则具备该设备的最大权限</td></tr>
</table>

#### 调用示例
**（以“查询设备详情API”为例）**

```
GET /devices/3532392 
api-key: WhI3aidfa82SUBD34h123hv1c=

```

### 安全鉴权 

安全鉴权方式以accessKey为核心密钥，用户需要使用核心密钥通过签名算法计算签名，与其他参数共同组成token，然后将token作为请求Header参数进行鉴权

安全鉴权方式通过避免核心密钥在网络上直接传输，增加认证参数时效控制，增加密钥权限粒度控制（即将到来）等方式提高鉴权安全性，最大限度保证访问安全

详情请见[安全鉴权](/book/easy-manual/auth.md)章节


#### 调用示例
**（以“查询设备详情API”为例）**

```
GET /devices/3532392 
Authorization: version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

```

