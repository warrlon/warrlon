# 错误码列表

<table style="text-align:center;">
<tr><th width="20%">error id</th><th width="40%">错误描述</th><th>原因及解决办法</th></tr>
<tr><td>1</td><td>解压dds.bin失败</td><td>系统IO错误</td></tr>
<tr><td>2</td><td>内核执行出错</td><td>请检查配置是否正确，或者联系DUI客服</td></tr>
<tr><td>3</td><td>系统启动超时</td><td>请检查配置是否正确，或者联系DUI客服</td></tr>
<tr><td>4</td><td>存储空间不足</td><td>请检查/data/目录剩余大小是否充足</td></tr>
<tr><td>70302</td><td>解码失败</td><td>联系DUI客服</td></tr>
<tr><td>70303</td><td>未发现新的版本</td><td>略</td></tr>
<tr><td>70304</td><td>请先升级您的客户端（SDK）</td><td>因为产品选择的dui内核和sdk不匹配，需要升级sdk</td></tr>
<tr><td>70305</td><td>网络异常, 无法连接至服务器</td><td>请检查网络是否正常或者配置是否正确</td></tr>
<tr><td>70306</td><td>解码失败</td><td>联系DUI客服</td></tr>
<tr><td>70307</td><td>补丁安装失败</td><td>存储空间不够</td></tr>
<tr><td>70308</td><td>备份压缩文件不存在</td><td>用户手动删掉了app私有空间的文件</td></tr>
<tr><td>70310</td><td>未设置产品ID</td><td>需要设置产品id</td></tr>
<tr><td>70311</td><td>无效客户端版本</td><td>请检查配置是否正确</td></tr>
<tr><td>70312</td><td>无效用户ID</td><td>需要设置用户id</td></tr>
<tr><td>70313</td><td>无效用户ID</td><td>设备id不正确</td></tr>
<tr><td>70314</td><td>资源地址无效</td><td>请检查配置是否正确</td></tr>
<tr><td>70315</td><td>无效的产品分支</td><td>需要设置产品分支</td></tr>
<tr><td>70316</td><td>无法找到资源</td><td>服务端资源生成有问题，请尝试重新发布一下，或者请提供产品id反馈给DUI客服，去后台查询根本原因</td></tr>
<tr><td>70317</td><td>资源校验失败</td><td>下载资源过程中资源被纂改</td></tr>
<tr><td>70319</td><td>当前产品中内核资源版本过低，请前往DUI控制台对应的产品中，选择最新的内核资源版本并重新发布产品</td><td>当前产品中内核资源版本过低，请前往DUI控制台对应的产品中，选择最新的内核资源版本并重新发布产品。</td></tr>
<tr><td>70320</td><td>存储空间不足</td><td>系统存储空间不足，请在错误的详细信息中查看需要的存储空间和现有的存储空间</td></tr>
<tr><td>70601</td><td>设备注册过程中无法连接到授权服务器</td><td>请检查网络是否畅通，或者productId与api key是否匹配</td></tr>
<tr><td>70602</td><td>设备注册过程无法颁发有效的profile文件</td><td>请检查产品ID或与客服联系</td></tr>
<tr><td>70603</td><td>API Key无效</td><td>请到产品授权配置页面查看api key信息是否正确,请确认签名证书是否匹配，包名是否匹配</td></tr>
<tr><td>70604</td><td>无效的产品ID</td><td>无效的产品ID，请确认是否未设置产品ID</td></tr>
<tr><td>70606</td><td>profile文件被禁用</td><td>请重新进行注册或者与客服联系</td></tr>
<tr><td>70607</td><td>profile文件过期</td><td>请重新进行注册或者与客服联系</td></tr>
<tr><td>70609</td><td>设备注册无法保存有效的profile文件</td><td>检查文件系统是否异常或者重新进行设备注册</td></tr>
<tr><td>70612</td><td>dns resolve failed: no answers（DNS失败）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70613</td><td>dns resolve failed: exceed retry count（DNS失败）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70614</td><td>dns resolve failed: network is unreachable（DNS失败）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70615</td><td>dns resolve timeout（DNS超时）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70616</td><td>connect ip failed: reasons for uncertainty（建立连接失败）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70617</td><td>connect ip failed: network is unreachable（建立连接失败）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70618</td><td>connect ip timeout（建立连接超时）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70619</td><td>websocket handshake failed: reasons for uncertainty（websocket握手失败）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70620</td><td>recv timeout（接收超时）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70621</td><td>send timeout（发送超时）</td><td>请检查网络是否畅通</td></tr>
<tr><td>70622</td><td>orderly shutdown（发完数据正常关闭）</td><td>请检查网络是否畅通</td></tr>
<tr><td>71301</td><td>TTS合成超时</td><td>请检查网络是否畅通</td></tr>
</table>