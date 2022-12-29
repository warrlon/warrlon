# 消息目的地—云存储RDS

<a href="#1">1. 应用场景</a> 

<a href="#2">2. 使用说明</a> 

<a href="#3">3. 操作步骤</a>  

---

<h3 id="1">1. 应用场景</font></h3>

云存储RDS为平台提供的云上关系型数据库，具有高可靠、高可用及动态扩展的特点。使用云存储RDS，可以将数据直接写入数据库，省去数据开发及存储工作，适合单纯的业务开发场景，无需购买服务器部署，即可实现采集+计算+存储的全栈服务。

<h3 id="2">2. 使用说明</font></h3>

规则引擎配置推送规则前，需要先购买平台云存储RDS资源，同时配置规则时，需要注意：

- 需要登录有完全操作权限的数据库账号，才能将消息数据存入RDS。
- 不同消息源可以选择存入同1个数据表，同1个数据字段可以存入不同的键。
- 1种消息源要对应1个数据表并至少完成一组消息数据和数据库中键的匹配，否则不能成功保存。
- 如果是对已有规则引擎进行编辑，需要注意：修改消息源和查询字段可能会导致输出的数据格式有变化，需要重新匹配变化的数据的存储位置。

<h3 id="3">3. 操作步骤</font></h3>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息数据流转至RDS流程.png">
    <br>
    图1 物联网平台数据转发至RDS实例流程
    <br>
</center>

<h4>登录数据库</h4>

1. 选择消息目的地为RDS实例，页面显示当前用户的RDS实例信息；如果未创建RDS实例，需要点击链接前往"物联网应用托管“进行配置。如果已有RDS实例时，选择需要存入的RDS实例和数据库，输入数据库账号、密码，点击"验证“登录数据库，只有拥有完全操作权限的账号，才能验证成功进入下一步。

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎-目的地rds.png">
    <br>
    图2 选择RDS消息目的地
    <br>
</center>

<h4>映射数据存储关系</h4>

1. 选择消息源：页面显示编辑规则引擎选择的消息源，每类消息源需要分次存入数据表并完成数据映射操作流程，然后再回到该页面选择剩下的消息源，以此类推直到已选消息源都完成映射。

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎-映射数据选择.png">
    <br>
    图5 选择消息源
    <br>
</center>

2. 选择数据表：选择消息源对应存入的数据表，1种消息源对应存入1个数据表，不同消息源可以存入同1个数据表。

3. 映射数据关系：

   -  下拉框选择数据表里的键，输入要存入这个键的数据字段，数据字段和键的对应关系不是唯一的，同一个数据字段可以存入不同的键中。
   -  点击"添加新映射关系“，重复以上操作为数据字段和键做映射。
   -  点击"删除“，删除该组数据字段和键；
   -  点击“确定”，完成1种消息源和数据库的映射关系，再重复以上操作，完成所有消息源和数据库的映射。

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎数据映射关系配置.png">
    <br>
    图6 映射数据关系
    <br>
</center>

4. 确认添加：点击"添加“按钮，规则引擎列表增加一行规则，为启用状态。

<h4>异常情况</h4>

当消息数据插入RDS发生异常时，系统会根据异常原因判断是否自动禁用规则，被系统禁用的规则引擎可通过规则引擎列表中启用状态列查看禁用原因，异常原因分类见下表。
<center>
    表1 消息数据流转至RDS产生异常原因分类表
</center>

| 序号 | RDS异常原因 | 是否禁用规则 |
| :-----:|  :---- | :----: |
| 1 | 用户账户欠费 | 是|
| 2 | 用户的实例、数据库删除 | 是 |
| 3 | 表不存在导致插入失败 | 是 |
| 4 | 登陆数据库的账号被删除 | 是 |
| 5 | 登陆数据库的账号的密码被修改 | 是 |
| 6 | RDS服务不可用 | 否 |
| 7 | RDS数据库不可用 | 否 |
| 8 | RDS网路不可访问 | 否 |
| 9 | RDS插入超时 | 否 |
| 10 | 由于对表设置了唯一索引等操作，导致数据重复插入失败 | 否 |
|11|RDS插入特殊字符导致失败，如设置了不支持插入特殊字符的编码|否|
| 12 | 表的列不存在导致插入失败 | 否 |
| 13 | 表的列的长度不够导致插入失败 | 否 |