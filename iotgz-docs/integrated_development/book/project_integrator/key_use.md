# key值管理

#### 名词解释

<table>
<tr><th width="20%">名词</th><th>解释</th></tr>
<tr><td>masterkey</td><td>每个项目的主key，拥有最高权限，可对项目下所有设备进行下发命令等操作，每个项目仅一个masterKey，masterKey只可重置不可删除</td></tr>
<tr><td>群组</td><td>拥有该设备或管理该设备的列表信息</td></tr>
<tr><td>群组key</td><td>每个项目可以拥有多个群组，一个群组拥有一个群组key，群组key可以用于调用API,且群组key仅拥有群组内设备的操作权限，群组key可以删除可以重置</td></tr>
<tr><td>access_key</td><td>鉴权密钥，不具备操作设备的权限。用户在加密模式下使用API时access_key作为对称加密密钥使用，在非加密模式直接传递masterKey或者群组key的值无需使用access_key</td></tr>
</table>

#### 使用场景
- 批量管理场景：将相同属性的设备放到一个群组，可以进行批量管理，如同一楼层的灯，可以使用同一个key进行管理

- 用户管理场景：一个用户对应一个群组key，用于该用户绑定设备

#### 使用说明

点击新建群组，可以创建新的群组，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/新建群组.png">
    <br>
    图 1 新建群组
    <br>
</center>

群组列表每行显示的是群组拥有的设备、管理的设备，可以添加、编辑备注，也可以重置、删除群组的key值。点击拥有的设备、管理的设备下的数字，可以对项目群组拥有或管理的设备进行操作，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/群组列表.png">
    <br>
    图 2 群组列表
    <br>
</center>

在群组关联的设备列表页，可以进行分享、删除设备的操作，如图3所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/群组关联的设备.png">
    <br>
    图 3 群组关联设备列表
    <br>
</center>

<div>
    <a href="/book/project_integrator/application_develop.md">
        <span> &#171; 上一篇：项目集成商_应用开发</span>
    </a>
</div>
<div>
    <a href="/book/api/open_api.md">
        <span> &#187; 下一篇：API列表调试</span>
    </a>
</div>