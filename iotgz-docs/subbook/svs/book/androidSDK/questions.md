# 常见问题

### SDK的软硬件配置要求

1）需要Android 4.0及其以上的系统；

2）/data分区剩余空间至少200MB。

### 授权失败

关于070603授权错误的问题，请做以下检查：

1）平台上生成的apikey和本地使用的apikey是否一致；

2）平台上release debug的sha256值是否和本地的对应；

3）gradle文件配置的signingConfigs，只针对generate生成的apk；

4）如果是点run运行的程序，debug的sha256要填的.android目录下的debug.keystore（最常见）。
