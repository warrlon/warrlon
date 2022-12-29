
    编写md文件时请严格按照本示例中的格式进行编辑

# 1 标题

# 一级标题

## 二级标题

### 三级标题

#### 四级标题

# 2 表格
markdown

    gitbook默认渲染为单元格等宽

|姓名|技能|排行|
|--|:--:|--:|
|刘备|哭|大哥|
|关羽|打|二哥|
|张飞|骂|三弟|
|其他|挂|换行<br>换行|

html (灵活度较高，推荐)

<table>
<tr><th width="15%">Tables</th><th width="70%">Are</th><th>Cool</th></tr>
<tr><td>col 1 is</td><td>left-aligned</td><td>$1600</td></tr>
<tr><td>col 2 is</td><td>centered</td><td>$12</td></tr>
<tr>
    <td rowspan="3"> 文件状态：<br/>
        [√] 草稿<br/>
        [√] 正在修改<br/>
        [√] 正式发布 </td>
    <td>文件标识：</td>
    <td>ancdf</td>
</tr>
<tr>
    <td>当前版本：</td>
    <td>2.7</td>
</tr>
<tr>    
    <td>作    者：</td>
    <td></td>
</tr>
<tr><td>col 3 is</td><td>right-aligned</td><td>$1982</td></tr>
</table>


# 3 粗体 表示重点内容

**重点内容用粗体表示**


# 4 变量 用 $加大写表示 下划线_分隔

url://api.heclouds.com/devices/$DEV_ID


# 5 注释

    注释部分用四个空格开头

> dfdfsadf[abc]()


# 6 图片

![图片名称](相对链接)

![图片](/images/logo.png)

# 7 超链接

    [文本](链接)

这个是一个[超链接](https://open.iot.10086.cn/doc/develop/)

    url连接会以新窗口形式打开


详请见[安全鉴权](/book/easy-manual/auth.md)

    相对路径链接会以窗口内跳转的方式打开


# 8 引用代码或者示例

引用json，粘贴之前，一定记得先用工具格式化：[地址](http://www.bejson.com/)
    
    示例：{"title": "test_device","location": {"lon": 109,"lat": 23.54}}

```json
{
	"title": "test_device",
	"location": {
		"lon": 109,
		"lat": 23.54
	}
}
```

引用C代码

```c
int test(int a, int b)
{
    return a+b;
}
```

引用文本

```text
这个是一段引用文字
```


# 9 列表

有序列表：

1. step1
2. step2

无序列表：

- function1
- function2

列表嵌套

1. abc
    - 313

- function1
    - abc
    - 123
- function2
    - bce


[^_^]:

    - [短信服务](readme.md)
        - [开发流程](/book/other-service/onenet-sms/develop.md)
        - [调用说明](/book/other-service/onenet-sms/request.md)
        - [API](readme.md)
            - [模板短信下发](/book/other-service/onenet-sms/api/smsSend.md)
            - [状态报告获取](/book/other-service/onenet-sms/api/getStatus.md)
        - [代码示例](readme.md)
            - [C#](/book/other-service/onenet-sms/demo/csharp.md)
            - [HTML](/book/other-service/onenet-sms/demo/HTML.md)
            - [Java](/book/other-service/onenet-sms/demo/JAVA.md)