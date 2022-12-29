# 最佳实践

## 1、开通镜像仓库

- Step1.如果您未曾使用过镜像仓库，系统会在您进入镜像仓库时，自动为您创建镜像仓库账号。

![image](/images/OCD/shijian01.png)

---
- Step2.创建镜像仓库项目，项目名称全局唯一。
![image](/images/OCD/shijian02.png)

---

- Step3.准备一台Linux服务器，并装有Docker环境，获取登录指令，在Linux服务器上登录，如果您没有修改过密码，那登录密码就为初始化密码。

![image](/images/OCD/shijian03.png)

---

![image](/images/OCD/shijian04.png)

---

![image](/images/OCD/shijian05.png)

- Step4.根据使用手册，为需要部署的镜像打tag，并且push到镜像仓库。

![image](/images/OCD/shijian06.png)

---

- Step5.查看仓库列表，显示已上传成功。

![image](/images/OCD/shijian07.png)

---

## 2、配置应用

- Step6.新建配置。

![image](/images/OCD/shijian08.png)

---

- Step7.配置节点，本案例以一个自研节点，一个第三方Mysql节点为例。自研节点镜像为刚刚上传的镜像，选择 **支持公网访问** ，然后保存配置。

![image](/images/OCD/shijian09.png)

## 3、部署应用

- Step8.配置部署信息，本案例选择使用创建默认集群。

![image](/images/OCD/shijian10.png)

---

![image](/images/OCD/shijian11.png)

---

- Step9.等待部署成功后，进入应用管理，获取自研节点的公网访问地址。

![image](/images/OCD/shijian12.png)

---

## 4、访问应用

- Step10.通过浏览器访问该地址，便能正常打开自研节点中的页面，并能够与第三方节点进行数据交互。

![image](/images/OCD/shijian13.png)