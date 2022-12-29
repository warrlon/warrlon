## 请求地址
https://api.heclouds.com/oes{API Path}
- API Path：每个接口对应的路径信息，如*/api/v1/products*。

## 公共参数

**参数列表**

| Name           |        | Description              | Required | Type   | marks                              |
| -------------- | ------ | ------------------------ | -------- | ------ | ---------------------------------- |
| accessKeyId    | Query  | 用户访问服务所用的密钥ID | Yes      | string | 系统生成，在页面创建并获取         |
| signature      | Query  | 签名结果串               | Yes      | string | 具体规则请参考“签名机制”           |
| signatureNonce | Query  | 签名随机数               | Yes      | int    | 1小时内，同一用户需使用不同数字    |
| pageSize       | Query  | 分页大小                 | No       | int    | 所有分页接口的分页大小，不能超过50 |
| platform       | Header | 平台类型（2：ECP）       | Yes      | int    | 全局放在header里，必传             |



**参数含义以及获取**

*accessKeyId*

用于标识访问者身份，在用户管理控制台页面查看，每个用户账号可以创建多个accessKeyId 。

*signature*  

请求签名字符串，是对请求参数，包括URL请求路径参数，Body参数（目前仅支持JSON格式）的一种算法加密之后得到的字符串，用于防止请求参数被拦截修改。具体签名方法参考**签名机制**。

*signatureNonce*

一个数字随机数，要求在一个小时内不能重复，防止请求被窃听并进行重放攻击。
