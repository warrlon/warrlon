# HTML code example

```json
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>模板签名短信接口测试</title>
</head>
<body>
<form name="form1" action="http://{ip}:{prot}/tempSignSmsSend" method="post">
    <table>
        <tr>
            <th>参数名</th>
            <th align="left">参数值</th>
        </tr>
        <tr>
            <td>si编码:</td>
            <td><input name="sicode" type="text" id="sicode" size="40"></td>
        </tr>
        <tr>
            <td>短信接收号码,最大99条,逗号分割:</td>
            <td><input name="mobiles" type="text" id="mobiles" /></td>
        </tr>
        <tr>
            <td>模板ID:</td>
            <td><textarea name="tempid" cols="70" rows="2" id="tempid"></textarea></td>
        </tr>
        <tr>
            <td>签名ID:</td>
            <td><textarea name="signId" cols="70" rows="2" id="signId"></textarea></td>
        </tr>
        <tr>
            <td>自定义key:</td>  //自定义key 的 textarea 标签的"name"属性值需要根据自定义模板修改为需要替换的参数值  
            <td><textarea name="key1" cols="70" rows="2" id="key1"></textarea></td>
        </tr>
        <tr>
            <td>……</td>
            <td><textarea name="……" cols="70" rows="2" id="……"></textarea></td>
        </tr>
        <tr>
            <td></td>
            <td><input type="submit" name="Submit" value="发送" /></td>
        </tr>
    </table>
</form>
</body>
</html>

```