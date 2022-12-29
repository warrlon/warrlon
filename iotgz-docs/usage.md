# 城市物联网平台文档

## 编写教程

### 1.目录

目录统一存放在根目录的 `SUMMARY.md` 文件中。
编写格式是markdown的链接列表，例如

```
- [平台概述](README.MD)
- [产品创建](deploy.md)
- [硬件接入](book/one.md)
	- [接入说明](book/one/one.md)
	- [HTTP协议](book/one/two.md)
		- [HTTP协议接入说明](https://open.iot.10086.cn)
```
说明： 
1. 项目根目录的 `README.MD` 必须存在，且如果在 `SUMMARY.md` 中没有写入，会在顶部自动生成一个 `Introduction` 的链接     
2. 链接地址可以是内部地址（相对根目录的相对地址，会在本项目打开） 或者 外部地址（会新页面打开）。
3. 层级关系通过缩进来实现。
4. 页面的展示是根据链接来判断的，所以如果两个同样的链接，会被认为是打开的第一个
5. 后面链接的文件名、拓展名 是区分大小写的，一定要注意


### 2.文档

所有文档都放在/book目录下（不是强制要求，我们自己约定的），尽量按照大的板块分文件夹存储。

文档编写按照标准markdown语法编写。

图片统一存在 /images 目录下，可以分多层文件，在文档里写相对路径就行，比如 “/images/OneNET_logo.png”
如果要把图片放到自己目录，请避免使用 images 关键词

---------------


### 整体流程




```
graph LR
获取最新文档-->新建分支
新建分支-->编辑文档
编辑文档-->完成自测

提交修改-->提交MergeRequests
提交MergeRequests-->合并代码
合并代码-->推送上线

```


## 文档规范 -- 逐渐完善中

1. master权限。回收master权限，暂定只有 罗庆波（luoqingbo@cmiot.chinamobile.com），敬威（jingwei@cmiot.chinamobile.com） 具有master权限，处理MergeRequests
2. 涉及到主站地址如果带有协议，要写https，而不是http
3. 文档中多余空白行会导致排版的序列错误
4. 所有文档的文件名、文件夹名、图片 统一使用英文小写，。（固定的SUMMARY.md和README.MD除外）
5. 子项目（subbook目录的文档），所有的图片放到根目录的images目录下


## 文档本地预览
1. 拉取git仓库后，安装node.js，版本必须是v10.24.1
2. 在工作目录下，使用`gitbook serve`，等待执行结束，出现`Serving book on http://localhost:4000` 后，在浏览器里面，输入`http://localhost:4000`后就可以预览整个文档；
3. 建议在文档写完之后，提交之前，现在自己的本地预览确认。
