# SDK示例

SDK下载地址：[https://github.com/cm-heclouds/video_sdk](https://github.com/cm-heclouds/video_sdk)

## 1.此文内容介绍

此文介绍设备接入OneNET视频云SDK示例。

## 2.SDK目录结构

SDK中的sample是遵循接入OneNET视频云原理的一个示例，其包含接入OneNET视频云、直播和点播功能。以下是sample各目录、文件简介：
```
bin：可执行文件及其运行时所需配置文件所在目录；
include：SDK对外接口声明文件所在目录；
lib：库目录；
platforms：跨平台代码；
sample：接入OneNET视频云示例；
src： ODVP接口等代码所在目录；
tools：构建sample生成可执行程序的脚本文件；
README.md：说明文件。
```
## 3.示例源码简介
### 3.1 配置文件简介
```json
{
    "profile":{
        "productid":产品ID,
        "deviceid":设备号,
        "pass":"产品注册码",
        "id":"设备标识"
    },

     "onvif": [
        {
            "title":"...",
            "channel_id":x,
            "url": "http://xxx.xxx.xxx.xxx/yyy/zzz",
            "user": "***",
            "passwd": "***",
            "desc":"...",
            "defaultlevel": y 
        }
    ],

    "rvod": [
        {
           "channel_id":x,
           "location":"~./filepath.mp4",
           "beginTime":"2016-12-08 00:00:00",
           "endTime":"2016-12-08 00:22:59",
           "videoTitle":"..."
        }
    ]
}
```

各字段含义如下：

- productid: 产品号
- deviceid: 设备号，可为0
- pass: 产品注册码
- id: 设备唯一标识
- channel_id:通道编号
- url: onvif设备地址
- user: 登录onvif设备的用户名
- passwd:登录onvif设备的密码
- defaultlevel: onvif设备默认的码率播放级别(1:流畅 2:标清 3:高清 4:超清)
- channel_id:本地视频通道编号
- location:本地存储路径
- beginTime:视频开始时间
- endTime:视频结束时间
- videoTitle:视频名称

### 3.2示例主程序简介
```c
int main(void)
{
    int err = 0;
    int tm_last = 0;
    int tm_diff = 0;
    ont_device_t *dev = NULL;

    /* init, create device instance, add callback to device;
     * exit or goto _ONT_DEVICE_END if failed */
    err = ont_device_init(&dev, &_g_device_cbs, &_g_ont_cmd);
    ONT_DEVICE_CHECK_ERR_GOTO_LABEL(ONT_ERR_OK, !=, err, __ONT_DEVICE_END);

    /* device connects to platform in randomly delay; 
     * reconnection would happen if connection failed last time */
__ONT_DEVICE_RECONN:
    ont_platform_sleep(ont_device_restart_random_delay(ONT_DEVICE_SLEEP_MAX, ONT_DEVICE_SLEEP_MIN));
    err = ont_device_acc_platform(dev);
    ONT_DEVICE_CHECK_ERR_GOTO_LABEL(ONT_ERR_OK, !=, err, __ONT_DEVICE_RECONN);
    RTMP_Log(RTMP_LOGINFO, "get device id %lu\n", dev->device_id);

    /* record cord time when connection done, used by keekplive */
    tm_last = ont_platform_time();

    /* device requests platform to do something by ODVP */
    (void)ont_device_requests_from_platform(dev);

    /* keeplive with platform;
     * check receive message comes from platform or APIs;
     * check stream and push it to platform */
    tm_diff = ONT_DEVICE_KEEPLIVE_TM_DIFF;
    ont_device_check_in_loop(dev, tm_last, tm_diff);

    /* reconnection would happen if ONT_DEV_EXIT_WHEN_SOCKET_ERR not be defined */
    ONT_DEVICE_CHECK_ERR_GOTO_LABEL(1, ==, ONT_DEV_RECONN, __ONT_DEVICE_RECONN);

__ONT_DEVICE_END:
    /* cleanup of device */
    ont_device_clean(dev);

    ONT_DEVICE_HOLD_CMD();
    return 0;
}

```

## 4.接入示例在Linux和windows下的构建参考

构建：根据源码生成可执行文件的过程。

### 4.1 Linux

#### 4.1.1 相关准备
[0]. 准备Linux环境，如VMware + Ubuntu这样的虚拟机。
[1]. 安装git 
```
sudo apt-get install git
git --version
```
[2]. 安装cmake 
```
sudo apt-get install cmake
cmake --version
cmake版本需大于等于2.8.8
```
[3]. 安装编译器及相关软件包
```
sudo apt-get install g++
由于安装cmake时已经安装了gcc及相关库，所以还只需安装g++，否则还需执行sudo apt-get install gcc build-essentail。
```
[4]. 下载SDK
```
mkdir workspace
cd workspace
git clone https://github.com/cm-heclouds/video_sdk video_sdk
```
#### 4.1.2 构建
```
chmod +x videosamplebuild.sh
./videosamplebuild.sh
```
对于新安装的linux系统，运行./videosamplebuild.sh构建接入示例有可能会失败。需要根据构建错误提示解决这些错误。以下是可能出现的一些错误及解决方案，以供参考。
```
(1) xlocale.h: No such file or directory
… video_sdk/sample/live/liveMedia/include/Locale.hh:47:10: fatal error: xlocale.h: No such file or directory
解法参考：打开 ~video_sdk/sample/live/CMakelist.txt，添加以下行：
add_definitions(-DXLOCALE_NOT_USED)
```
```
(2) /usr/bin/x86_64-linux-gnu-ld: cannot find -lssl -lcrypto
因为SDK用的是openssl-1.0.1g，保险起见，本应安装相同版本，可这个版本在ubuntu 18中不能安装，所以选择openssl-1.0.2g。
源码包：openssl-1.0.2g.tar.gz
tar -xzf openssl-1.0.2g.tar.gz
cd openssl-1.0.2g
./config --prefix=/usr/local/openssl --openssldir=/usr/lib/openssl
make depend
make
sudo make install
以上操作安装了静态库libssl.a/libcrypto.a，它们在/usr/local/openssl/lib/下。
链接器ld的默搜静态/动态库的路径有/usr/lib、/lib，现将openssl库路径告知链接器ld，让带链接器也到/usr/local/openssl/lib/下搜索库文件：
sudo vi /etc/profile
export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/openssl/lib/
source /etc/profile
注：LIBRARY_PATH用于设置链接器的链接库路径；LD_LIBRARY_PATH用于程序运行期间链接/加载动态库的路径。

```
```
(3)libmbedcrypto.a(bignum.c.o): recompile with –fPIC等系列错误
relocation R_X86_64_32S against `.rodata' can not be used when making a PIE object; recompile with –fPIC
…
libmbedcrypto.a在..video_sdk/lib/linux/下，是提前根据mbedtls源码在另一台Linux上编译好的静态库，提示它不能在本机中被链接。
解法参考：在本机中编译libmbed库并替换掉..video_sdk/lib/linux/libmbedcrypto.a。
mbedtls的下载和安装参考https://github.com/ARMmbed/mbedtls。
video sdk tool目录下有mbedtls源码包，可以直接使用它。
tar zxvf mbedtls-2.6.0-apache.tgz
cd mbedtls-2.6.0
make
sudo make install
mbedtls库被安装到/usr/local/lib/下。
cp /usr/local/lib/libmbedcrypto.a ../lib/linux/
```
```
(4) undefined reference to mbedtls_platform_set_calloc_free
video_sdk/src/security_mbedtls.c:39: undefined reference to mbedtls_platform_set_calloc_free
…
vi include/mbedtls/config.h
去掉以下宏的注释
#define MBEDTLS_PLATFORM_MEMORY
然后重新生成libmbedcrypto.a库。
make clean
make
make install
再用编译得到的libmbedcrypto.a覆盖原有的libmbedcrypto.a。
cp /usr/local/lib/libmbedcrypto.a ../lib/linux/
若没其他问题，则构建成功。在~/video_sdk/bin目录下生成名为sample_video_s的可执行文件。
```
```
(5) Relocations in generic ELF (EM: 40)
…
清除已有的编译（在build目录内执行make clean；或删除已有的build目录），重新构建即可。

```
### 4.2 Windows

#### 4.2.1 使用cmake生成vs工程

video sdk sample下载地址同
https://github.com/cm-heclouds/video_sdk。

下载并安装cmake和visual studio。下载可能比较缓慢，请提前进行下载并耐心等待。

cmake下载地址：https://cmake.org/ （cmake-3.12.0-rc1-win64-x64.msi）

visual studio下载地址：https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs

成功安装visual studio后（此文为vs2015），注意应将其安装路径(bin)添加到环境变量中，以避免cmake找不到visual studio的提示。准备好cmake和VS后，开始构建接入示例。

- 运行cmake，按提示进行配置。

![](/images/vedio-image/设备接入SDK示列介绍28.png)

注意visual studio的版本选择，比如这里安装的是visual studio 2015，那么这里应该选择相应的版本，否则会出错。

- 选择接入示例模块

```
SAMPLE/MP4V2/ONVIF/PROTOCOL_RTMP_CRYPT/PROTOCOL_SECURITY_MBEDTLS/PROTOCOL_SECURITY_OPENSSL。
```

![](/images/vedio-image/设备接入SDK示列介绍29.png)

- 使用vs2015打开Cmake构建的vs项目工程。

![](/images/vedio-image/设备接入SDK示列介绍30.png)

到此，就可以在windows平台下用vs打开sample了。

#### 4.2.2构建接入示例

C1900  “P1”(第“20161212”版)和“P2”(第“20150812”版)之间 Il 不匹配
若 勾选
```
_PROTOCOL_SECURIY_MBEDTLS
```
选项，VS编译时中遇到类似以上错误，可通过重新编译video_sdk/tools/mbedtls重新生成库，然后将相应库拷贝到~video_sdk/lib/win目录下。

- 解压mbedtls，将~mbedtls-2.6.0/include/mbedtls/config.h下的以下两个宏的注释去掉以配置sample所需功能：

```c
//#define MBEDTLS_PLATFORM_MEMORY
//#define MBEDTLS_HAVEGE_C
```

- 进入~/video_sdk/tools/mbedtls-2.6.0-apache/mbedtls-2.6.0/visualc/VS2010目录，用vs打开mbedTLS.sln；使用vs编译（使用F5即可）mbedtls以生成相应的库。编译完成后，在~/mbedtls-2.6.0/visualc/VS2010/Debug或~/mbedtls-2.6.0/visualc/VS2010/Release目录下生成mbedTLS.lib库文件，将该文件拷贝到~video_sdk/lib/win目录下。
编译成功后，将配置文件config.json拷贝到bin/Debug或bin/Release目录下，双击生成的sample_video_s即可运行。将config.json拷贝到vs所设置的目录下还可进行在线调试。

