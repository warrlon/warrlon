<h1>下载资源</h1>

请求方式：**GET**

URL: http(s)://ota.heclouds.com/ota/south/download/{token}

#### http头部 
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
Range | string | 否 | 分片信息，如果没有Range字段，默认返回所有数据

#### 说明

头部Range字段解释：Range=start-end，目前只支持如下几种模式：

	 1、Range=start-, 获取第start+1个字节到最后的数据；例如：
	 	Range=0-, 获取所有数据。
		Range=2-,获取第3个到最后的数据。
		注意：如果start>=文件总长度,则默认start=0
	 2、Range=start-end, 获取第start+1个字节到第end+1个字节；例如：
	 	Range=0-99,获取前100个字节。
		注意：end>=文件总长度len，则默认end=len-1；start>end, start被设置为0。
	 3、Range=-end,获取最后end个字节数据；例如：
	 	Range=-100,获取最后100个字节数据。
		注意：如果end>文件总长度len,则默认end=len（获取所有文件）。
	 4、如果头部Range不存在、或者Range没有按照如上规则上传，都视为返回所有数据。
	 5、Range:01-02,视为1-2。

状态码：

	分片返回状态码：206
	不分片状态码：200

每一次调用都需要token校验。

如果响应Header中没有返回Content-Length，说明拉取文件发送一次，这时响应内容只有一个字节数据，如果返回的字符是：

    1：未找到资源，上报下载失败（107）

    2：文件大小不一致，上报下载失败（107）

    3：无效token，上报下载失败（107）


#### 返回参数
```
返回二进制文件
```


如果header中没有Range字段，默认返回所有数据。响应报文中存在如下三个重要字段：

	1、Content-Disposition:该字段中包括filename，文件名。
	2、Content-Range:表示当前请求获取的数据位置和资源总数len。
	3、Content-Length:当前请求获取的数据大小