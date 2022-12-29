# 标识数据模板

定义标识数据模板，是接入工业互联网标识服务的第二步准备工作。通过使用产品/设备基础属性、设备物模型上报数据功能点、自定义数据点的形式来创建设备工业标识数据模板，帮助您根据自身业务来快速定义设备在工业互联网标识解析下标识数据的内容和规范。

### 添加数据模板
在数据模板菜单页，点击“添加数据模板”，为具体的产品创建数据模板，一个产品只能关联一个数据模板，且关联了数据模板后，该产品下的所有设备注册标识时都将按照该数据模板定义的数据点生成和更新标识数据。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/添加数据模板.png">
    <br>
    图1 添加数据模板
    <br>
</center>

### 设置数据点
维护了数据模板基础信息后，将自动进入到数据模板详情页，您需要先为当前数据模板设置对应的标识数据点，定义标识数据点即为定义设备在工业互联网标识解析体系下的标识解析内容。

**OneNET定义了以下三类数据点：**
- 基础属性数据点：获取产品/设备基础属性信息作为数据点，当产品/设备基础属性数据更新时，可同步更新标识数据；
- 物模型数据点：获取产品定义的物模型功能点作为数据点，当物模型功能点数据上报更新时可同步更新标识数据；
- 自定义数据点：用户自定义标识数据点，自定义的标识数据点手动进行更新后才会同步更新标识数据；

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/设置数据点.png">
    <br>
    图2 设置数据点
    <br>
</center>

**添加基础属性数据点**

点击添加基础属性数据点即可进入选择基础属性数据点页，选择您需要添加的产品/设备的基础信息作为标识模板数据点。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/添加基础属性数据点.png">
    <br>
    图3 添加基础属性数据点
    <br>
</center>


**添加物模型数据点**

点击添加物模型数据点即可进入选择物模型数据点页，选择您需要添加物模型功能点来作为标识模板数据点。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/添加物模型数据点.png">
    <br>
    图4 添加物模型数据点
    <br>
</center>

您可为具体产品数据模板选择的物模型数据点必须为在该产品下设置的物模型功能点，因此在添加物模型数据点前，请先前往OneNET Studio中为产品添加物模型功能点。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/添加物模型功能点.png">
    <br>
    图5 添加物模型功能点
    <br>
</center>

**添加自定义数据点**

点击添加自定义数据点即可进入添加自定义数据点页，添加自定义数据点时需要您手动设置对应的数据点信息和限制条件。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/添加自定义数据点.png">
    <br>
    图6 添加自定义数据点
    <br>
</center>

**其它说明：**

- 添加数据点时可设置具体数据点是否必录，当设置了数据点必录后只有当对应数据点数据有更新时才会同步更新标识数据。

- 数据点设置完成需要保存后才可生效。




