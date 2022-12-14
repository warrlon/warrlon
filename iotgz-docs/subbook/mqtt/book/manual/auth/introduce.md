# 安全鉴权

MQTT物联网套件采用安全鉴权策略进行访问认证，即通过核心密钥计算的token进行访问认证

## 安全鉴权策略

安全鉴权策略主要通过如下方式保证访问安全：
- 避免核心密钥网络中直接传输，从而避免核心密钥在传输中泄露
- 通过包含由**非可逆算法**生成的签名的token来进行身份认证，即使token被窃取，攻击者也无法通过token反向获得核心密钥
- 鉴权参数token具有**用户自定义**的**过期时间**属性，可从时间维度降低被攻击/仿冒的风险

## 常见安全方案
#### 方案1
访问者（可以为**应用**或者**设备**）固化访问密钥于软件中，在需要进行服务访问时，通过密钥计算零时token，通过临时token进行服务访问认证

#### 方案2
访问者首先通过访问管理者获取临时访问token，访问管理者可根据需要自定义该token的访问有效期（即过期时间），访问者获取该token后方才能访问OneNET

![](/images/MQTTS/token安全方案1.png)

#### 方案3
访问管理者直接将密钥授权给访问者（例如，直接为设备烧写key），访问者通过密钥生成token进行访问

![](/images/MQTTS/token安全方案2-1.png)

## 更多帮助

- [了解token算法](/book/manual/auth/token.md)   
