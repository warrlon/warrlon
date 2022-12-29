# 集成准备

### 获取产品ID

集成SDK之前，您需要到地址获取如下到产品ID

![pic](/images/svs/获取产品ID.png)

### SDK和资源文件

将SDK包中的aar文件( 如lib-dsg-1.0.0.aar )导入到现有的工程中，放入到libs目录下，并在build.gradle中添加配置:

```javascript

    repositories {
        flatDir {
            dirs 'libs'
        }
    }
    dependencies {
        compile(name:'lib-dsg-1.0.0', ext:'aar')
        compile 'com.google.android.exoplayer:exoplayer-core:2.6.0'
        compile 'com.squareup.okhttp3:okhttp:3.9.0'
        compile 'com.squareup.okio:okio:1.13.0'
    }
```

资源文件以及它们的md5编码文件放在src.main.assets下

![pic](/images/svs/SDK和资源文件.png)