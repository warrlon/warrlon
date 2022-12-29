# 应用配置
## 1、功能概述
您可以在应用配置页面中通过可视化操作，选择您自研的容器节点，搭配OneNET推荐的中间件节点，以及第三方开源中间件，构建符合您需求的应用服务，并通过后续的应用部署将应用托管在OneNET平台。
## 2、应用配置操作步骤

点击**应用配置**进入应用配置界面，在该界面中您可以新建、编辑或删除已创建的应用

![image-20200618232126513](/images/OCD/image-appConfig-01.png)

---

点击**+创建应用**新建一个应用并添加相关描述，应用名称须保持唯一

![image-20200618232452357](/images/OCD/image-appConfig-02.png)

---

创建完成后可在**应用配置列表**中查看并管理所有应用

![image-20200618232725417](/images/OCD/image-appConfig-03.png)

---

在应用配置列表中点击**编辑**进入可视化应用配置界面。从左侧的节点列表中**拖拽**各类节点至中央画布，点击节点，在右侧弹出的配置框中对节点进行配置。不同的节点类型对应不同的配置项目。配置时须保持同一应用配置中每节点**服务名称**唯一。

通过点击节点下方小框，按住鼠标拖动至其他节点画出箭头，箭头指向的节点为被依赖的节点。只有容器节点可以指定依赖节点。被依赖节点的环境信息将通过**环境变量**的形式注入到源节点的容器中。**服务名称为后续获取环境变量的重要参数，请提前规划**。

指定依赖时不能形成环，即不可以循环依赖，否则可能导致部署失败。

配置完成后点击画布下方**保存**按钮，**保存**后关闭配置页面，即完成本次配置。在应用配置列表中点击编辑即可继续进行应用配置。

![image-20200618235216925](/images/OCD/image-appConfig-04.png)

---

## 3、各节点配置说明
### 1）、自研节点

- 选择自研节点镜像，镜像可从个人仓库、共享仓库、公开仓库中选择

- 为自研节点添加指定的环境变量

  ![image-20200619001036175](/images/OCD/image-appConfig-05.png)

  ---

- 配置自研节点资源数量，总副本至少1个，至多5个

- 配置自研节点资源限制

- 配置自研节点可选择公网访问，或仅在k8s集群内部访问

- 配置自研节点的端口映射即主机路径映射

  ![image-20200619001441588](/images/OCD/image-appConfig-06.png)
  
  ---

### 2）OneNET节点
#### ① Kafka

- 服务名称须保持在该应用配置中唯一。

- OneNET Kafak为三节点kafka集群。

- topic及消费者组为必填项，更多topic及消费者组可在**OneNET应用托管服务** ->  **消息队列** -> **Kafka**中进行添加。

- 消息保留时长为24~168小时。

- 当kafka节点被依赖时，kafka的访问IP及端口会通过环境变量提供，具体形如：

  ```
  key: cmiot_server_[kafka服务名称]_kafkaIps		value：10.0.0.1,10.0.0.2,10.0.0.3
  key: cmiot_server_[kafka服务名称]_kafkaPort		value：9092
  ```
  ![image-20200619002729412](/images/OCD/image-appConfig-07.png)

  ---

#### ② Redis

- 服务名称须保持在该应用配置中唯一。

- OneNET Redis分为单机版及集群版。单机版为单节点，集群版为三节点集群部署。

- 用户可在**OneNET应用托管服务** -> **Redis**中进行参数配置、调试等其他操作。

- 当Redis节点被依赖时，Redis的访问IP及端口会通过环境变量提供，具体形如：

  ```
  单机版：
  key: cmiot_server_[Redis服务名称]_redisIps		value：10.0.0.1
  key: cmiot_server_[Redis服务名称]_redisPorts	value：6379
  集群版：
  key: cmiot_server_[Redis服务名称]_redisIps		value：10.0.0.1,10.0.0.2,10.0.0.3
  key: cmiot_server_[Redis服务名称]_redisPorts	value：6379,6380
  ```
  
  ![image-20200619003839342](/images/OCD/image-appConfig-08.png)

#### ③ RDS for mysql

- 服务名称须保持在该应用配置中唯一。

- OneNET RDS for mysql提供MariaDB_v5.5.6及MySql_v5.7两种版本，均为两节点主备部署。

- 用户可在**OneNET应用托管服务** -> **RDS**中进行创建数据库、创建账户等其他操作。

- 数据库名称、字符集、用户名、密码均为必填项。数据库表需用户在自研节点中主动创建。该处提供的用户为高权限账号，拥有所有数据库权限。

- 当RDS节点被依赖时，RDS的访问IP及端口会通过环境变量提供（数据库名称、用户名、密码等须在自研节点中预先配置），具体形如：

  ```
  key: cmiot_server_[RDS服务名称]_mysqlUrl            value：10.0.0.1:3306
  key: cmiot_server_[RDS服务名称]_mysqlDatabase		value：dbName
  key: cmiot_server_[RDS服务名称]_mysqlUser			value：userName
  key: cmiot_server_[RDS服务名称]_mysqlPassword		value：userPwd
  ```

![image-20200619005230544](/images/OCD/image-appConfig-09.png)

---

### 3）第三方节点
#### ① MySql

- 服务名称须保持在该应用配置中唯一。

- 服务类型可选择集群内访问或公网访问。

- **当容器重启时，MySQL中的数据会丢失**

- 当MySql节点被依赖时，MySql的相关信息会通过环境变量提供，具体形如：

  ```
  key: cmiot_container_[RDS服务名称]_mysqlUrl		            value：10.0.0.1:3306
  key: cmiot_container_[RDS服务名称]_mysqlRootPass            value：rootPwd
  key: cmiot_container_[RDS服务名称]_mysqlDatabase            value：dbName
  key: cmiot_container_[RDS服务名称]_mysqlUsername            value：userName
  key: cmiot_container_[RDS服务名称]_mysqlPassword            value：userPwd
  ```
  
  ![image-20200619101201786](/images/OCD/image-appConfig-10.png)
  
  ![image-20200619102919916](/images/OCD/image-appConfig-11.png)

#### ②Redis

- 服务名称须保持在该应用配置中唯一。

- 服务类型可选择集群内访问或公网访问。

- **当容器重启时，Redis中的数据会丢失**

- 当Redis节点被依赖时，Redis的相关信息会通过环境变量提供，具体形如：

  ```
  key: cmiot_container_[Redis服务名称]_redisUrl		            value：10.0.0.1:6379
  key: cmiot_container_[Redis服务名称]_redisPassword				value：redisPwd
  ```

  ![image-20200619103503283](/images/OCD/image-appConfig-12.png)

#### ③Mongo

- 服务名称须保持在该应用配置中唯一。

- 服务类型可选择集群内访问或公网访问。

- **当容器重启时，Mongo中的数据会丢失**

- 当Mongo节点被依赖时，Mongo的相关信息会通过环境变量提供，具体形如：

  ```
  key: cmiot_container_[Mongo服务名称]_mongoUrl			        value：10.0.0.1:27017
  key: cmiot_container_[Mongo服务名称]_mongoRootPass		        value：mongoRootPass
  key: cmiot_container_[Mongo服务名称]_mongoDatabase		        value：mongoDatabase
  key: cmiot_container_[Mongo服务名称]_mongoUsername		        value：mongoUsername
  key: cmiot_container_[Mongo服务名称]_mongoPassword		        value：mongoPassword
  ```

  ![image-20200619104305766](/images/OCD/image-appConfig-13.png)

  ![image-20200619104551449](/images/OCD/image-appConfig-14.png)