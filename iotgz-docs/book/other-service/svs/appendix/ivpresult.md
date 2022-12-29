# 声纹业务结果说明

文本密码JSON示例

    {"txt_pwd":["芝麻开门"]}

数字密码JSON示例

    {"num_pwd":["03285469","09734658","53894276","57392804","68294073"]} 

声纹业务结果（NSDictionary类型结果）成员说明

<table>
<tr><th width="20%">成员名</th><th>说明</th></tr>
<tr><td>sst</td><td>业务类型，取值为train或verify</td></tr>
<tr><td>ret</td><td>返回值，0为成功，-1为失败</td></tr>
<tr><td>vid</td><td>注册成功的声纹模型id</td></tr>
<tr><td>score</td><td>当前声纹相似度</td></tr>
<tr><td>suc</td><td>本次注册已成功的训练次数</td></tr>
<tr><td>rgn</td><td>本次注册需要的训练次数</td></tr>
<tr><td>trs</td><td>注册完成描述信息</td></tr>
<tr><td>err</td><td>注册/验证返回的错误码</td></tr>
<tr><td>dcs</td><td>描述信息</td></tr>
</table>

