# 预备工作

### 导入SDK

将开发工具包中libs目录下的Msc.jar复制到您自己工程的libs目录中。

在自己工程的src/main目录下新建jniLibs文件夹，并将开发工具包中的armeabi目录复制到jniLibs中

### AndroidManifest.xml 配置

    <manifest>
      <!--连接网络权限，用于执行云端语音能力 -->
      <uses-permission android:name="android.permission.INTERNET"/>
      <!--获取手机录音机使用权限，听写、识别、语义理解需要用到此权限 -->
      <uses-permission android:name="android.permission.RECORD_AUDIO"/>
      <!--读取网络信息状态 -->
      <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
      <!--获取当前wifi状态 -->
      <uses-permission android:name="android.permission.ACCESS_WIFI_STATE"/>
      <!--允许程序改变网络连接状态 -->
      <uses-permission android:name="android.permission.CHANGE_NETWORK_STATE"/>
      <!--读取手机信息权限 -->
      <uses-permission android:name="android.permission.READ_PHONE_STATE"/>
      <!--读取联系人权限，上传联系人需要用到此权限 -->
      <uses-permission android:name="android.permission.READ_CONTACTS"/>
      <application>
         <!-- 在 OneNET 平台上注册的 appid --> 
         <meta-data
            android:name="com.cmiot.onenet.lingxi.APP_ID" android:value="xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"/>
      </application>
    </manifest>


### 代码混淆

在proguard.cfg中添加如下代码:

    -keep class com.iflytek.**{*;}
    -keep class com.cmiot.onenet.lingxi.**{*;}

### Android P 适配

首先在res文件夹下创建xml文件夹，然后创建名为network_security_config.xml的文件，并在文件中增加如下内容:

    <?xml version="1.0" encoding="utf-8"?> 
    <network-security-config>
        <domain-config cleartextTrafficPermitted="true">
           <!-- 测试 api 地址 -->
           <domain includeSubdomains="true">183.230.40.149</domain>
        </domain-config>
    </network-security-config>

最后在AndroidManifest.xml的application标签中增加如下属性：

    <application
        android:networkSecurityConfig="@xml/network_security_config"> 
    </application>


### 初始化

初始化即创建语音配置对象，只有初始化后才可以使用MSC的各项服务。建议将初始化放在程序入口处（如Application、Activity的onCreate方法），初始化代码如下:


    // 将“123456789012”替换成您在OneNET上创建应用所获取的APPID
    SpeechUtility.createUtility(context, SpeechConstant.APPID +"=123456789012");

SpeechUtility常用参数说明：

<table>
<tr><th width="25%">参数名称</th><th width="20%">是否必填</th><th>说明</th></tr>
<tr><td>appid</td><td>是</td><td>应用的唯一标识，可在控制台中查看</td></tr>
<tr><td>force_login</td><td>否</td><td>在createUtility时会对进程名称进行检查，如果名称与应用包名不一致则不进行login操作，返回null，用以规避在子进程反复进行调用的问题。此参数设置是否强制login。<br>默认值:false (进行检查，不强制login)。</td></tr>
<tr><td>lib_name</td><td>否</td><td>在createUtility时会加载动态库，此时可以传入动态库名称。如您是预装软件，为了避免动态库冲突建议修改名称<br>例如：libmsc_xxx_1072.so(xxx为您的公司名,1072为灵犀云sdk版本号) 默认值:msc。</td></tr>
</table>

注意：参数需要以键值对的形式存储在字符串中传入createUtility方法，以逗号隔开，如“appid=123456789012,lib_name=msc”。

