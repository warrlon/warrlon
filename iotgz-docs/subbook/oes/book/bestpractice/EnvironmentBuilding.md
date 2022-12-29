# 边缘节点环境搭建

本文介绍如何在Centos 7.5的系统中搭建OneNET智能边缘计算套件边缘节点环境，实现节点与云端连接。

## 准备工作

边缘节点依赖Docker运行环境，需要提前安装好，建议安装/更新 Docker 版本到 18.09.2 及以上。可通过以下命令安装 docker 的最新版本（适用于 Linux 系统）：

```shell
curl -sSL https://get.docker.com | sh
```

或者参考[docker官网](https://docs.docker.com/install)进行安装。

## 创建边缘节点产品和节点

1. 在边缘IoT管理控制台，选择**设备管理>边缘节点管理**。

2. 添加一个边缘节点产品。

   - 点击**添加边缘节点产品**，填写节点产品名称。

   ![image-20191223110513183](/images\oes\bestpractice\environmentbuiding\添加边缘节点产品1.png)

   - 填写描述（可选），点击**添加**。

   ![image-20191223110606095](/images\oes\bestpractice\environmentbuiding\添加边缘节点产品2.png)

3. 创建一个边缘节点。

   - 在刚刚创建好的边缘节点产品列表，点击**查看**，进入节点产品详情。

   ![image-20191223141318080](/images\oes\bestpractice\environmentbuiding\添加边缘节点1.png)

   - 点击**添加边缘节点**，填写节点名称，选择操作系统和CPU架构。

   ![image-20191223141444099](/images\oes\bestpractice\environmentbuiding\添加边缘节点2.png)

   ![image-20191223141707836](/images\oes\bestpractice\environmentbuiding\添加边缘节点3.png)


   | 参数     | 描述                                                      |
   | -------- | --------------------------------------------------------- |
   | 操作系统 | 设备操作系统，仅支持Linux系统。                           |
   | CPU架构  | 设备对应的CPU架构，支持AMD64、ARM64、ARM。这里选择AMD64。 |


   - 参数设置完成后，点击**添加**，至此完成边缘节点创建。

## 安装并启动边缘节点软件

在平台完成节点创建工作后，需要在设备上安装并启动节点软件，才能完成接入工作。

1. 进入到边缘节点列表页面，点击操作栏中的**详情**进入**边缘节点详情**页面。

   ![image-20191223151301292](/images\oes\bestpractice\environmentbuiding\安装边缘节点软件1.png)

2. 点击**边缘节点软件栈安装**，在弹出的对话框中会显示安装操作指南。

   ![image-20200103145754786](/images\oes\bestpractice\environmentbuiding\安装边缘节点软件2.png)

3. Step1用于安装docker环境，前文已经说明怎么进行安装，参考准备工作。

4. Step2用于安装边缘节点程序，目前已支持一键安装，点击页面上**复制**按钮复制命令至设备上运行，等待下载完成并初始化。

   ![image-20200103145852134](/images\oes\bestpractice\environmentbuiding\节点安装操作指南.png)

   ![image-20191223154057130](/images\oes\bestpractice\environmentbuiding\节点安装命令行执行.png)

5. 复制Step3的命令启动边缘节点程序，根据系统是否支持systemd，选择相应的启动命令。这里复制第一个命令执行。

6. 启动后执行systemctl status onenetedge（如果不支持systemd，使用/usr/local/onenetedge/onenetedge.sh status）查看运行状态。

   ![image-20191223155415373](/images\oes\bestpractice\environmentbuiding\节点运行命令行执行.png)

   > 注：首次启动会拉取程序docker镜像，根据网络情况需要耗费不同时间，请耐心等待。拉取镜像过程中可以通过tail -f /usr/local/onenetedge/var/log/onenetedge.log查看相关日志。

7. 启动完成后，使用docker ps可以看到程序容器正常运行。

8. 在平台控制台刷新**边缘节点详情**页面，可以看到节点状态显示在线，同时节点的系统信息也上报成功。

   ![image-20191223165541426](/images\oes\bestpractice\environmentbuiding\边缘节点详情.png)

## 脚本常用命令

边缘节点程序（以下简称onenetedge）安装目录为**/usr/local/onenetedge**，配置边缘节点以及查看相关日志请切换到该目录。这里先执行

```shell
cd /usr/local/onenetedge
```

进入该目录。

- 安装onenetedge

  ```
  ./onenetedge.sh install -i {节点ID} -p {节点产品ID} -k {节点MasterKey} -r {云端mqtt地址} -l {日志级别}
  ```

  **参数说明**


  | 参数 | 描述                                                         |
  | ---- | ------------------------------------------------------------ |
  | -i   | 边缘节点ID，可在边缘节点详情查看                             |
  | -p   | 边缘节点产品ID，可在边缘节点详情查看                         |
  | -k   | 边缘节点Master Key，可在边缘节点详情查看                     |
  | -r   | 云端MQTT broker地址，在安装指南里可以查看                    |
  | -l   | 边缘节点日志级别：支持debug、info、warn、error、fatal，默认info级别 |


- 配置onenetedge

  ```shell
  ./onenetedge.sh config XXX
  ```

  config命令参数和install一致，区别在于，install先安装然后再配置，config只是执行配置操作。

- 启动onenetedge

  ```shell
  systemctl start onenetedge 或者 ./onenetedge.sh start 
  ```

- 停止onenetedge
  ```shell
  systemctl stop onenetedge 或者 ./onenetedge.sh stop 
  ```

- 查看onenetedge运行

  ```shell
  systemctl status onenetedge 或者 ./onenetedge.sh status 
  ```

- 查看onenetedge运行

  ```shell
  systemctl restart onenetedge 或者 ./onenetedge.sh stop && ./onenetedge.sh start
  ```

## 目录解析

如上文所说，边缘节点的安装目录在**/usr/local/onenetedge**下，在该目录下会存放程序的配置文件以及日志文件。配置文件目前提供的脚本可以进行快捷配置，一般来说用户不需要手动更改。用户主要关注日志的路径，便于快速排查一些问题。常用目录如下：

```shell
./
├── bin
│   └── onenetedge
├── etc
│   └── onenetedge
│       └── onenetedge.yml
├── onenetedge.sh
└── var
    ├── db
    │   └── module
    │       ├── agent
    │       ├── app_module.yml
    │       ├── dataparser
    │       ├── localhub
    │       ├── module.yml
    │       ├── msgroute
    │       ├── remotemqtt
    │       │   └── ca.crt
    │       └── scenelinkage
    ├── log
    │   ├── agent
    │   │   └── agent.log
    │   ├── dataparser
    │   │   └── dataparser.log
    │   ├── localhub
    │   │   └── localhub.log
    │   ├── msgroute
    │   │   └── msgroute.log
    │   ├── onenetedge.log
    │   ├── remotemqtt
    │   │   └── remotemqtt.log
    │   └── scenelinkage
    │       └── scenelinkage.log
    └── run
        └── onenetedge.sock
```

**目录说明**

| 路径                                                | 描述                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ |
| /usr/local/onenetedge/bin/onenetedge                | 边缘节点软件核心程序                                         |
| /usr/local/onenetedge/etc/onenetedge/onenetedge.yml | 程序配置文件                                                 |
| /usr/local/onenetedge/var/db                        | 各个模块配置文件目录                                         |
| /usr/local/onenetedge/var/log                       | 日志文件路径，核心程序日志文件为onenetedge.log，模块日志文件在相应子目录下 |



​		