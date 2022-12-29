# 生态接入认证

## 服务介绍

生态接入认证服务是由中国移动物联网公司发起，对物联网终端是否符合平台接入及其他技术规范进行的产品认证服务。
通过认证后的产品可加入OneNET生态，并享受以下特权：
- 成为OneNET合作伙伴，共建物联网行业生态；
- 参与中国移动项目招标及行业招募活动；
- 中国移动全国全网同步销售；
- 线上线下以中国移动品牌或联合品牌营销推广；


## 生态接入认证流程

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/接入流程.jpg">
    <br>
    图1 接入流程
    <br>
</center>

## 流程操作说明

### 创建产品、设备
进入OneNET studio进行产品和设备创建。详情请参考
[设备接入与管理](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/product-create.html)

### 技术对接申请
进入OneNET控制台首页，点击“服务支持”，进入服务支持菜单进行生态接入认证申请。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/接入认证入口.jpg">
    <br>
    图2 认证入口
    <br>
</center>

点击【生态接入认证】，完善以下信息，提交技术对接申请

- 选择认证方式
- 选择认证产品和型号
- 完善企业联系人信息
- 选择与您对接的市场联系人

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/发起技术对接申请.jpg">
    <br>
    图3 技术对接申请
    <br>
</center>

提交后，将由对应的市场人员审核，同时将会有专业的技术支持人员与您联系，为您提供技术对接服务。

### 产品接入自测试
在进行接入自测试前，您需要按照技术支持人员为您提供的设备接入规范和说明文档进行研发工作，完成后才可进行自测试。
请按照以下步骤进行自测试：
#### 设备上线联网
选择需要认证产品下进行了开发接入的设备，点击开始测试，5分钟内让设备侧上电并且登录OneNET平台，设备登录在线后，系统会提示测试通过，自动进入下一测试环节。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/设备上线联网.jpg">
    <br>
    图4 设备上线联网
    <br>
</center>

#### 设备上报数据
进入设备上报数据测试环节，点击开始测试，让设备侧上报数据，页面会轮询查找5分钟内设备上报数据，查询到则展示上报数据在页面上，并提示测试通过。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/设备上报数据.jpg">
    <br>
    图5 设备上报数据
    <br>
</center>

#### 应用下发命令控制设备
进入应用下发命令测试环节，点击开始测试，5分钟内让应用调用api下发命令给设备，设备接收到命令且响应后，测试通过，自动进入下一测试环节。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/应用下发命令控制设备.jpg">
    <br>
    图6 应用下发命令控制设备
    <br>
</center>

#### 应用获取设备上报数据
进入应用获取设备上报数据测试环节，点击开始测试，5分钟内使用HTTP推送或MQ消息队列将设备上报数据推送到SAAS平台，上报数据成功，则测试通过。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/应用获取设备上报数据.jpg">
    <br>
    图7 应用获取设备上报数据
    <br>
</center>

以上四步测试都通过后，则表示完成产品自测试，同时可进入接入认证申请环节。

### 接入认证申请
完成了产品接入自测试后，您需要将进行自测试的设备邮寄到中国移动物联网公司，同时维护您邮寄的快递单号，便于对应技术支持人员收货。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/接入认证申请.jpg">
    <br>
    图8 接入认证申请
    <br>
</center>

### 技术支撑测试
对应技术支持人员收到货后，将开始对您邮寄的设备进行测试，测试过程中有任何问题您都可联系对应的技术支持人员。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/技术支撑测试.jpg">
    <br>
    图9 技术支撑测试
    <br>
</center>

### 认证完成
技术支持测试完成后，则完成了对应产品的生态接入认证，您可查看已完成认证的产品信息，同时OneNET物联网平台将为您出具对应的认证证书和认证报告。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/access-certification/已完成认证产品.jpg">
    <br>
    图10 查看认证产品
    <br>
</center>