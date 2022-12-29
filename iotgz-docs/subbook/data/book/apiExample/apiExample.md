## API使用方式

#### 输出管理模块API调用方式

| 请求方式 | GET|
|:----:|:----|
|url|输出管理页面对应接口的URL|
|header|secretKey=xxx  //用户专属的秘钥,在用户中心页面可查看|
|成功返回结果|{<br>&emsp;"code": "0000",<br>&emsp;"msg": "success",<br>&emsp;"data": {<br>&emsp;&emsp;&emsp;&emsp;&emsp;"data": [{<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;//返回的数据字段名会根据定义结果集类型的元数据数据结构来返回<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;"fieldName1": "val1",<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;"fieldName2": "val2",<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;"fieldName3": val3",<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;//表示该条记录的保存时间<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;"record_ts": "1568084048003"//固定字段<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;}]<br>&emsp;&emsp;&emsp;&emsp;}<br>}|

#### API数据接入的API调用方式

| 请求方式 | POST|
|:----:|:----|
|url|https://open.iot.10086.cn/bds/v1/collect/api/push|
|header|Content-Type = application/json<br>token=XXX   //token为接入管理页面对应API数据接入的密钥|
|request-body|{<br>&emsp;"list":<br>&emsp;&emsp;&emsp;[{<br>&emsp;&emsp;&emsp;&emsp;//用户外部数据上传的数据结构字段名和值<br>&emsp;&emsp;&emsp;&emsp;" fieldName1" : "val1",<br>&emsp;&emsp;&emsp;&emsp;" fieldName2" : "val2",<br>&emsp;&emsp;&emsp;&emsp;" fieldName3" : "val3"<br>&emsp;&emsp;&emsp;}]<br>}
