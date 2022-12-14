# 事件交互蓝图快速入门

事件交互蓝图为用户提供低代码、可拖拽的可视化应用编辑器，帮助用户快速构建应用服务，以下是具体使用方式。

## 创建应用

进入到控制台后，选择**创建应用**按钮即可创建事件交互蓝图应用，事件交互蓝图以应用的形式对外提供服务，每一个应用对应着一个独立的实例在云端运行，但我们仅为每一位用户提供创建一个应用的许可。如下图所示：

![创建事件交互蓝图应用表单](/images/view/app/create_app_form.png)

填写完成后，点击**启动**按钮来启动应用，如下图所示：

![启动应用](/images/view/app/start_app.png)

等待应用启动成功后，即可点击应用进入到应用的流程列表，每一个流程列表对应着一个编辑器，我们可以通过**创建流程**来新建一个流程，如下图：

![创建流程表单](/images/view/app/create_flow_form.png)

完成创建后，即可点击完成流程创建，需要注意的是，虽然每一个流程对应着一个编辑器，但是编辑器编排好的流程都是部署到同一个实例当中。等待流程创建完成后，点击**进入编辑器**即可进入到编辑器页面，如下图所示

![编辑器](/images/view/app/editor.png)

上图中，第一部分是编辑器的地址，用红色线条圈出来的部分是编辑器的域名地址，在编辑器当中编排的接口都是通过该域名来访问的；第二部分是节点列表，节点指的是我们对某些能力的封装，例如邮件发送就是封装了发送邮件的能力，您只需要配置好该节点的基本内容即可；第三部分是编辑区域，可以将左侧节点列表当中的节点拖拽到编辑器并连接起来，形成完整流程；第四部分为介绍文档，选择某一个节点后会切换成该节点的配置表单。

# 编排流

在该示例中，我们需要编排一个接口，请求的接口地址为 `/hello`，访问的方式为 `GET`，可以接收参数并返回所发送的参数到客户端。

首先，需要定义接口的入口，所以选择 `HTTP 接口定义`节点，并拖入到编辑器中，在请求方式一栏选择`GET`方式，在接口地址当中填入`hello`如下所示：

![编辑器HTTP接口定义](/images/view/app/editor_http_in.png)

这个节点会把客户端请求所携带的所有参数按照规则映射到编辑器内置的对象当中，映射的规则可以在节点帮助中查看，如下图：

![编辑器节点帮助](/images/view/app/editor_node_help.png)

因为返回的数据也是从 `msg.payload` 当中读取，与请求时参数映射到的是同一对象，所以可以直接拖出 `HTTP响应` 节点，并将 `HTTP接口定义` 节点与 `HTTP响应` 节点连接起来，如下图所示：

![编辑器HTTP响应](/images/view/app/editor_http_res.png)

以上步骤就将流程编排好了，我们可以点击`保存`将本次的修改保存起来，如下图所示：

![编辑器保存](/images/view/app/editor_save.png)

保存完成后，点击部署，即可将该流程部署到实例当中，如下图所示：

![编辑器部署](/images/view/app/editor_deployment.png)

部署完成后即可在浏览器当中访问到该接口，如下图所示：

![服务响应](/images/view/app/server_response.png)

