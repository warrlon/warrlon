# 场景联动管理

# 场景联动规则创建


<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CreateSceneRule&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="17">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>name</td><td>string</td><td>必填</td><td>场景联动名称</td></tr>
<tr><td>conditions</td><td>array</td><td>必填</td><td>触发条件集合，如下的c表示conditions数组的单个对象标识</td></tr>
<tr><td>c. ctype</td><td>string</td><td>必填</td><td>触发方式 支持lifeCycle-设备生命周期、 notify-设备数据上报</td></tr>
<tr><td>c. device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>c. product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>c. identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>c. type</td><td>string</td><td>必填</td><td>功能点数据类型 支持int32、int64、float、double、string、bool</td></tr>
<tr><td>c. value</td><td>string</td><td>必填</td><td>功能点预设值 触发方式为lifecycle时，value值为online或者offline</td></tr>
<tr><td>c. operator</td><td>string</td><td>必填</td><td>比较运算符 支持eq-等于、lt-小于、gt-大于、lte-小于等于、gte-大于等于</td></tr>
<tr><td>actions</td><td>array</td><td>必填</td><td>执行动作集合，接口只支持设备生命周期、设备数据上报两种触发方式，定时触发、第三方数据触发可通过页面设置，如下的a表示actions数组的单个对象标识</td></tr>
<tr><td>a. device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>a. product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>a. identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>a. type</td><td>string</td><td>必填</td><td>功能点数据类型</td></tr>
<tr><td>a. value</td><td>string</td><td>必填</td><td>功能点值</td></tr>
<tr><td>emit_condition</td><td>string</td><td>必填</td><td>触发方式，all - 满足全部条件触发, any - 任意条件触发</td></tr>

<tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.id</td><td>string</td><td>场景ID</td></tr>

<tr><th>请求示例</th><td colspan="4">
{<br>
    "project_id":"ocgzVU", <br>
    "name":"联动测试",<br>
    "conditions":[ // 触发方式<br>
        { <br>  
            "ctype":"notify",<br>  
            "device_name":"no001",<br>
            "product_id":"30769",<br> 
            "identifier":"1",<br> 
            "type":"bool",<br> 
            "value":"true",<br>
            "operator":"eq"<br>
    }],<br>
    "actions":[  // 执行动作 <br>
        {<br>
            "device_name":"no001",<br>
            "product_id":"30769",<br>
            "identifier":"1",<br>
            "type":"bool",<br>
            "value":"true"<br>
    }],<br>
   "emit_condition":"all"<br>
}<br>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "id": "5ee2031009f703003737cd5b"<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>
