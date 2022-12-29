# 文件管理

# 设备文件上传

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CreateDeviceFile&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json	</td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="3">请求体参数</td><td>device_name</td><td>string</td><td>必填</td><td>设备名称 ,参数需构造在同一个 form-data 中</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID ,参数需构造在同一个 form-data 中</td></tr>
<tr><td>file</td><td>file</td><td>必填</td><td>上传的图片文件(目前支持.jpg .jpeg .png .bmp .gif .webp .tiff .txt .exe .jar .zip .rar)</td></tr>

<tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.fid</td><td>string</td><td>文件上传成功后返回的文件ID</td></tr>

<tr><th>请求示例</th><td colspan="4">
{<br>
  "device_name": "device_name",<br>
  "product_id": "qwdfbht",<br>
  "md5": "f55c2e86ab864b64a6d939fbe3a7d65f",<br>
  "size": 12546,<br>
  "filename": "filename",<br>
  "file": file<br>
}<br>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
        "fid": "434fa51a170942c8a291be1e4b229582"<br>
    } <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>