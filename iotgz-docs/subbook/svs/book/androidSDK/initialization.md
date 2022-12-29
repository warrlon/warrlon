# 初始化SDK

### 初始化SDK

使用如下方法来初始化SDK

```javascript
    DDS.getInstance().init(
            getApplicationContext(),
            new CmiotDDSConfig(productId)
                    .addConfig(CmiotDDSConfig.K_DEVICE_ID, deviceId)
                    .addConfig(CmiotDDSConfig.K_API_KEY, apiKey),
            new DDSInitListener() {
                @Override
                public void onInitComplete(boolean isFull) {
                    AILog.d(TAG, "onInitComplete: " + isFull);
                }
    
                @Override
                public void onError(int what, String msg) {
                    AILog.d(TAG, "onError: " + what + ", error: " + msg);
                }
            }, new DDSAuthListener() {
                @Override
                public void onAuthSuccess() {
                    AILog.d(TAG, "onAuthSuccess");
                }
    
                @Override
                public void onAuthFailed(String errId, String error) {
                    AILog.d(TAG, "onAuthFailed: " + errId + ", error:" + error);
                }
            });
```

在收到 onInitComplete 回调之后，就可以使用DDS来完成对应的操作。
isFull如果为true，则表示完全初始化，所有功能就绪。

除了通过监听onInitComplete回调外，还可以直接通过判断DDS.getInstance().getInitStatus()的返回值来检查初始化是否完毕。

    /**
     * 获取当前初始化的状态
     *
     * @return DDS.INIT_COMPLETE_NONE     还未初始化完成，表示DDS正在初始化
     *         DDS.INIT_COMPLETE_NOT_FULL 部分初始化完成，表示DDS已经初始化完成，但还没有完成更新
     *         DDS.INIT_COMPLETE_FULL     完全初始化完成，已经完成更新
     */
    DDS.getInstance().getInitStatus();

注意：

-  DDS.getInstance().init()和DDS.getInstance().release()方法不会阻塞应用程序的主线程，也不会影响应用程序性能。
-  当未初始化完成时，尝试调用一些方法时，会抛出 DDSNotInitCompleteException 异常。
-  当调用DDS.getInstance().release()之后，之前注册的observers会失效，再次DDS.getInstance().init()后，您需要对之前的observers重新注册。

使用以下方法来释放SDK：

    DDS.getInstance().release();

代码中授权参数含以如下：

| 参数名 | 取值 | 说明 | 是否必须 | 取值实例 |
| :- | :- | :- | :-| :- |
| productId| 产品标识 | 来源：产品-产品Id | 是 | piaVPKsmfENDXXw4 |
| deviceId| 设备Id |  | 否 | 0ddddeeeeeeeeeeee88888888260c8ab |
| apiKey| apikey<br>字符串 | 限制一个API Key只被指定的客户端使用，来源：产品-授权管理-app授权 | 是 | 81057e57a9aa81057e57a9aa5ef06c6e |

### 权限说明

SDK需要的权限如下表，请在AndroidManifest.xml 文件中添加。

| 权限 | 用途 |
| :- | :- |
| android.permission.INTERNET | 允许接入互联网，以便访问我们的云服务 |
| android.permission.RECORD_AUDIO | 允许采集音频 |
| android.permission.READ_PHONE_STATE | 允许读取必要的设备数据 |
| android.permission.ACCESS_WIFI_STATE | 获取WIFI状态 |
| android.permission.ACCESS_NETWORK_STATE | 获取网络状态 |
| android.permission.WRITE_EXTERNAL_STORAGE | 写入外部存储数据，用于存储一些缓存文件 |
| android.permission.READ_EXTERNAL_STORAGE | 读取外部存储数据 |

### 代码混淆

 如果您的应用使用了混淆， 请添加：

 **proguard-rules.pro**

    -dontwarn com.aispeech.**
    -keep public class com.aispeech.lasa{*;}
    -keep public class com.aispeech.dui.dds.luaBug{ *; }
