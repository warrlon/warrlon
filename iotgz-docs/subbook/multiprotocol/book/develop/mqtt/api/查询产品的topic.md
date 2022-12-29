# 查询产品的topic
请求方式：**GET**

URL: http://api.heclouds.com/mqtt/topic

#### 返回参数
参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功
data | array-string | topic列表

#### 请求头部示例
```text
GET http://api.heclouds.com/mqtt/topic HTTP/1.1
```

#### 返回示例
```json
{
	"errno": 0,
	"data": ["topic/test/01", "topic/test/02"],
	"error": "succ"
}
```