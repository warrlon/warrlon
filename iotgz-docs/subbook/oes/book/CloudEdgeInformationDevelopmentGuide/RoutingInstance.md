# 路由实例管理

路由实例功能提供添加，修改，删除，启用和禁用路由实例功能。路由实例分在云端和边缘端执行，提供标准的数据转发功能。路由实例数据转发支持数据加密、压缩、和格式转化。具体如下：

加密方式：暂只支持AES加密。

数据格式：JSON，XML，SERIALIZED，CSV（其中SERIALIZED暂时与JSON等同）。

压缩方式：支持gzip和zip压缩。

## 添加路由实例

点击**云边消息**>**路由实例**>**添加路由实例**

![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter.png)

![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_add.png)

## 编辑路由实例

  点击**云边消息**>**路由实例**>想要修改的路由实例行后面的**编辑**按钮后进入编辑页面。

  注：已启用的路由实例进行不能修改，应该先禁用后才能进行修改。

  ![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_edit.png)

## 启用/禁用路由实例

路由实例创建后默认处于禁用状态，不会进行数据转发，需点击启用才能进行相应的数据转发。

### 启用

  点击**云边消息**>**路由实例**>想要修改的路由实例行后面的**启用**按钮。

  ![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_enable.png)

### 禁用

  点击**云边消息**>**路由实例**>想要修改的路由实例行后面的**禁用**按钮。

  当该路由实例状态处于启用状态时，原启用按钮将会变为禁用按钮。点击“禁用”，将终止该路由实例数据转发。

  ![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_disable.png)

## 删除路由实例

注意：处于启用状态的路由实例不能删除，必须先禁用才能删除。

### 普通删除

点击“云边消息”-> “路由实例”-> 想要删除路由实例行后面的”删除”按钮。

  ![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_delete.png)

### 批量删除

勾选要删除路由实例的多个路由实例，  点击 批量删除按钮删除。

![](/images\oes\CloudEdgeInformationDevelopmentGuide\datarouter_batch_delete.png)

