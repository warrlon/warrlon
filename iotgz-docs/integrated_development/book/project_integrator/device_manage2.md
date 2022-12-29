# 设备管理
本页目录

<a href="#1">1. 设备列表</a> 

<a href="#2">2. 群组管理</a> 

---

<h3 id="1"> <font color="#66CDAA">1. 设备列表</font></h3>

“设备列表”是当前项目下的设备列表，支持设备状态、激活时间、产品ID、设备SN的搜索，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/项目集成_设备列表.png">
    <br>
    图 1 设备列表
    <br>
</center>

#### &#9755; 参数说明

<table>
<tr><th width="20%">参数</th><th>说明</th></tr>
<tr><td>详情</td><td>每一个设备的“详情”包含了设备的基本信息。包括设备SN、产品ID、设备状态、最近使用时间、激活时间、
是否在线</td></tr>
<tr><td>数据看板</td><td>“数据看板”中可以查看设备相关数据。</td></tr>
<tr><td>群组</td><td>拥有该设备或管理该设备的列表信息。</td></tr>
<tr><td>转移</td><td>可以将没有绑定群组的设备转移到其它项目中。</td></tr>
</table>

如图2所示，“档案管理”主要用于项目的自定义信息管理，用户可以自定义字段和值，如型号、所属城市，可以统一赋值也可单独赋值，可以管理设备的档案字段、支持导入档案信息，项目将继承产品有的字段。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/档案管理.png">
    <br>
    图 2 档案管理
    <br>
</center>

<h3 id="2"> <font color="#66CDAA">2. 群组管理</font></h3>

群组管理表示项目生成的群组，如图7所示，项目可以根据不同的群组分配设备权限，一个群组拥有一个群组key，可以用于调用API，典型场景如下：

&#9921; 批量管理场景：将相同属性的设备放到一个群组，可以进行批量管理，如同一楼层的灯，可以使用同一个key进行管理和调用；

&#9920;用户管理场景：将一个用户对应一个群组key，用于该用户绑定设备。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/群组管理.png">
    <br>
    图 3 群组管理
    <br>
</center>

点击图3中右上角“新建群组”，可以创建新的群组。

> 列表每行显示的是群组拥有的设备、管理的设备，可以添加、编辑备注，也可以重置、删除群组的key值。

点击**拥有的设备**、**管理的设备**下的数字，可以对项目群组拥有或管理的设备进行操作。如图8所示，群组关联的设备，可以进行分享、删除设备的操作。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/群组_关联设备.png">
    <br>
    图 4 关联的设备
    <br>
</center>

<div>
    <a href="/book/project_integrator/create_project.md">
        <span> &#171; 上一篇：项目集成商_创建项目和集成产品</span>
    </a>
</div>
<div>
    <a href="/book/project_integrator/application_develop.md">
        <span> &#187; 下一篇：项目集成商_应用开发</span>
    </a>
</div>