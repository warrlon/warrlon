# Pull Upgrade Files - Get Resources

Request mode: ** GET**

URL: http://ota.heclouds.com/ota/download/$token

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Range | string | no | fragmentation information, if there is no Range field, returns all data by default

#### Description

```
头部Range字段解释：Range=start-end，目前只支持如下几种模式
 1、Range=start-, 获取第start+1个字节到最后的数据
    例如：Range=0-, 获取所有数据
          Range=2-,获取第3个到最后的数据
    注意：如果start>=文件总长度,则默认start=0
 2、Range=start-end, 获取第start+1个字节到第end+1个字节
    例如：Range=0-99,获取前100个字节
    注意：end>=文件总长度len，则默认end=len-1
          start>end, start被设置为0
 3、Range=-end,获取最后end个字节数据
    例如：Range=-100,获取最后100个字节数据
    注意：如果end>文件总长度len,则默认end=len（获取所有文件）

分片返回状态码：206
不分片状态码：200
```

#### Return parameters
```
返回二进制文件
```
```
响应报文中存在如下三个重要字段
Content-Disposition:该字段中包括filename，文件名
Content-Range:表示当前请求获取的数据位置和资源总数len
Content-Length:当前请求获取的数据大小
```