# 获取性别/年龄信息

在初始化DDS SDK的时候加入如下配置:

    config.addConfig(DDSConfig.K_USE_GENDER, "true");
    config.addConfig(DDSConfig.K_USE_AGE, "true");

然后订阅message：sys.dialog.start

内容为：{"gender":"male","age":"youth","reason":"wakeup.major"}

gender就是性别字段，age就是年龄字段,性别年龄信息只有在主唤醒词唤醒后，才会发出。
