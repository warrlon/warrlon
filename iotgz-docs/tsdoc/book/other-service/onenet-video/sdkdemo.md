# SDK example

SDK download address:[https://github.com/cm-heclouds/video_sdk](https://github.com/cm-heclouds/video_sdk)

## 1. Introduction to this article

This article introduces an example of device access to OneNET video cloud SDK.

## 2. SDK directory structure

Sample in SDK is an example of the principle of accessing OneNET video cloud, which includes accessing OneNET video cloud, live broadcast and on demand functions. Following is a brief introduction to the directories and files of sample:
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
## 3. Introduction to sample source code
### 3.1 Profile Introduction


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

Each field has the following meanings:

- Product id: Product number
- deviceid: Device number, which can be 0
- pass: Product Registration Code
- id: Device Unique Identification
- Channel_id: Channel Number
- url: onvif device address
- user: Username for login onvif device
- passwd: Password to log on to onvif device
- default level: The default rate playback level for onvif devices (1: Smooth 2: Clear 3: High Definition 4: Super Clear)
- Channel_id: Local Video Channel Number
- Location: Local Storage Path
- beginTime: Video Start Time
- endTime: Video End Time
- Video Title: Video Name

### 3.2 Brief introduction of sample main program









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

## 4. Reference for the Construction of Access Examples under Linux and Windows

Construction: The process of generating executable files from source code.

### 4.1 Linux

#### 4.1.1 Preparations
[0]. Prepare Linux environments, such as VMware + Ubuntu virtual machines.
[1]. Install Git
```
sudo apt-get install git
git --version
```
[2]. Install cmake
```
sudo apt-get install cmake
cmake --version
cmake版本需大于等于2.8.8
```
[3]. Installation of compilers and related software packages
```
sudo apt-get install g++
由于安装cmake时已经安装了gcc及相关库，所以还只需安装g++，否则还需执行sudo apt-get install gcc build-essentail。
```
[4]. Download SDK
```
mkdir workspace
cd workspace
git clone https://github.com/cm-heclouds/video_sdk video_sdk
```
#### 4.1.2 Construction
```
chmod +x videosamplebuild.sh
./videosamplebuild.sh
```
For newly installed Linux systems, running the. / videosamplebuild. sh build access example may fail. These errors need to be resolved based on build error hints. Here are some possible mistakes and solutions for your reference.
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

#### 4.2.1 Generating vs Project with cmake

The video SDK sample download address is the same
https://github.com/cm-heclouds/video_sdk。

Download and install cmake and visual studio. Download may be slow, please download ahead of time and wait patiently.

Cmake download address: https://cmake.org/(cmake-3.12.0-rc1-win64-x64.msi)

Visual studio download address: https://www.visual studio.com/en-us/downloads/download-visual-studio-vs

After successful installation of visual studio (this article is vs2015), note that its installation path (bin) should be added to the environment variable to avoid cmake failing to find the visual studio prompt. Once cmake and VS are ready, start building access examples.

- Run cmake and configure as prompted.

![](/images/vedio-image/设备接入SDK示列介绍28.png)

Note the version selection of visual studio, such as the one installed here is visual studio 2015, then the corresponding version should be selected here, otherwise there will be errors.

- Select Access Sample Module

```
SAMPLE/MP4V2/ONVIF/PROTOCOL_RTMP_CRYPT/PROTOCOL_SECURITY_MBEDTLS/PROTOCOL_SECURITY_OPENSSL。
```

![](/images/vedio-image/设备接入SDK示列介绍29.png)

- Use vs2015 to open the vs project project built by Cmake.

![](/images/vedio-image/设备接入SDK示列介绍30.png)

At this point, you can open sample with vs under Windows platform.

#### 4.2.2 Building an Access Example

Il mismatch between C1900 "P1" (version 20161212) and "P2" (version 20150812)
If checked
```
_PROTOCOL_SECURIY_MBEDTLS
```
Option: When VS compiles, it encounters similar errors as above. The library can be regenerated by recompiling video_sdk/tools/mbedtls, and then the corresponding library can be copied to the ~video_sdk/lib/win directory.

- Unzip mbedtls and remove the following two macros under ~mbedtls-2.6.0/include/mbedtls/config.h to configure the required functions of sample:

```c
//#define MBEDTLS_PLATFORM_MEMORY
//#define MBEDTLS_HAVEGE_C
```

- Enter the ~/video_sdk/tools/mbedtls-2.6.0-apache/mbedtls-2.6.0/visual c/VS2010 directory, open mbedTLS.sln with vs, compile with vs (use F5) mbedtls to generate the corresponding library. After compilation, the mbedTLS.lib library file is generated in the ~/mbedtls-2.6.0/visual c/VS2010/Debug or ~/mbedtls-2.6.0/visual c/VS2010/Release directory, and copied to the ~video_sdk/lib/win directory.
After successful compilation, the configuration file config.json is copied to the bin/Debug or bin/Release directory, and double-click the generated sample_video_s to run. Copying config. JSON to the directory set by vs can also be debugged online.