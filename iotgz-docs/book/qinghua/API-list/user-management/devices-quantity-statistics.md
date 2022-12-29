# 用户下设备数量统计

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=UserDeviceStatistics&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td>URL请求参数</td><td colspan="4">无</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="12">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.count</td><td>number</td><td>总设备数量</td></tr>
<tr><td colspan="2">data.statistcs</td><td>array</td><td>数组对象，设备分类统计，如下的s表示statistcs数组的单个对象标识</td></tr>
<tr><td colspan="2">s.uid</td><td>string</td><td>设备所属用户ID</td></tr>
<tr><td colspan="2">s.dev_new<td>number</td><td>每日新增设备数量</td></tr>
<tr><td colspan="2">s.dev_lively</td><td>number</td><td>日活设备数量</td></tr>
<tr><td colspan="2">s.insert_time</td><td>array</td><td>设备统计的具体日期</td></tr>
<tr><td colspan="2">s.dev_actived</td><td>number</td><td>日激活设备数</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=UserDeviceStatistics&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
         "count":27, // 总设备数<br>
         "statistcs":[<br>
            {<br>
                "uid":5,<br>
                "dev_new":0, // 每日新增设备数<br>
                "dev_lively":1, // 日活备数<br>
                "insert_time":"20211213", //  日期<br>
                "dev_actived":13 // 日激活设备数<br>
            },<br>
            {<br>
                "uid":5,<br>
                "dev_new":0,<br>
                "dev_lively":1,<br>
                "insert_time":"20211214",<br>
                "dev_actived":13<br>
            }<br>
        ]}<br> 
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>
