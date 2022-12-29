# 应用部署
## 1、功能概述
您可以根据已有的配置，将您的应用进行部署，您可以部署至已有的容器集群或者我们为您默认创建的集群。根据您的配置，整个部署过程可能需要耗费一些时间，请您耐心等待。


## 2、部署应用操作步骤
 点击 **应用部署** -> **+部署应用** 可进入部署操作栏

![image](/images/OCD/deploy01.png)


---


 应用部署名称需保证唯一，进入部署操作栏，从应用配置列表选择需要部署的配置。

![image](/images/OCD/deploy03.png)


---


 根据您选择的配置项，我们会计算出您所需的容器资源以及云资源，并为您推荐 **默认** 的容器Kubernetes集群。

![image](/images/OCD/deploy05.png)


---


 同时，您也可以选择已有的容器集群或者创建新的容器集群进行部署。

![image](/images/OCD/deploy06.png)

---


 您可以在 **费用测算** 中查看该次部署的价格，收费的规则是后付费形式，按小时收费。

![image](/images/OCD/deploy12.png)
![image](/images/OCD/deploy13.png)

---

![image](/images/OCD/deploy14.png)
![image](/images/OCD/deploy15.png)

---

 点击部署后便可在页面看到一条部署数据，**部署状态** 为 **部署进行中**，整个部署过程需要一定时间。

![image](/images/OCD/deploy09.png)

---

 完成部署后，部署状态会变为 **部署成功** ，可点击 **管理** 按钮进入应用管理页面

![image](/images/OCD/deploy10.png)

---

 在应用管理页面，可以看到应用的配置信息、节点信息、访问信息、以及节点的操作按钮。

![image](/images/OCD/deploy24.png)

## 3、查看日志
 **自研节点** 和 **第三方节点** 可以查看日志，主要包括节点调度情况以及节点内输出的日志。
 
 点击 **事件** 可以查看该节点在容器集群中的调度日志
 ![image](/images/OCD/deploy17.png)
 
 点击 **输出** 可以查看在节点内输出的日志。
 ![image](/images/OCD/deploy18.png)
 
## 4、查看监控
以**OneNET节点-RDS for mysql** 监控为例，您可以查看节点运行时的相关指标。
 ![image](/images/OCD/deploy20.png)
 
## 5、扩容与重启
#### **自研节点** 可以使用扩容与重启操作。

扩容操作能 **增加/缩减** 自研节点资源使用量，以便应对多变的业务使用场景。

 ![image](/images/OCD/deploy21.png)
 ![image](/images/OCD/deploy22.png)
 
重启操作能够 **初始化** 自研节点。

 ![image](/images/OCD/deploy25.png)
 
## 6、节点开机

当您的账户欠费一定时间后，后台会将您的节点关机。在您未欠费的情况下，可以为节点执行开机操作，开机过程会耗费一定的时间。

 ![image](/images/OCD/deploy26.png)

## 7、删除应用部署
已部署的应用只有在用户未欠费的情况下才能删除。删除后，会释放您的OneNET节点以及自研、第三方节点资源，但会保留您的容器集群资源，您可以在 **集群管理** 中手动释放。