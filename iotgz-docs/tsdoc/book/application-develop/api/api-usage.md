# API usage

The platform provides an open API interface. Users can use HTTP/HTTPS calls to carry out device management, data query, device command interaction and other operations. On the basis of API, according to their individual needs, upper application is built.

## API Authentication

To improve API access security, authentication parameters of OneNET API exist as ** header ** parameters

OneNET supports both common and secure authentication methods. Compare the following tables:

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

### General Authentication

The common authentication method uses apiKey as authentication key, and apiKey is divided into two access levels: product level (Master) and device level.
<table>
<tr><th width="15%"> </th><th width="40%">产品级</th><th>设备级</th></tr>
<tr><td>数量</td><td>产品下唯一</td><td>产品下可以有多个</td></tr>
<tr><td>权限范围</td><td>产品下所有资源的操作，包括：<br>设备、数据流、数据点、触发器、文件、命令以及设备apiKey</td><td>部分设备的全量操作，包括<br>设备详情，设备数据流，设备数据点</td></tr>
<tr><td>自定义权限</td><td>不支持</td><td>支持设备级<br>需要用户进行apiKey与设备的关联操作，一旦关联则具备该设备的最大权限</td></tr>
</table>

#### Call examples
** (Take API for Inspecting Equipment Details as an example)**


```
GET /devices/3532392 
api-key: WhI3aidfa82SUBD34h123hv1c=

```

### Security Authentication

AccessKey is the core key of security authentication. Users need to use the core key to calculate signature through signature algorithm. Token is composed of other parameters, and then token is used as the request header parameter to authenticate.

Security authentication can improve authentication security by avoiding the direct transmission of core keys on the network, increasing the timeliness control of authentication parameters, and increasing the granularity control of key privileges (forthcoming), so as to maximize access security.

For more information, see Secure Authentication (/book/easy-manual/auth.md)


#### Call examples
** (Take API for Inspecting Equipment Details as an example)**


```
GET /devices/3532392 
Authorization: version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

```