# 识别结果说明

语义识别结果说明:

|json字段|英文全称|类型|说明|
|-|-|-|-|
|sn|sentence|int|第几句
|ls|last sentence|boolean|是否最后一句
|bg|begin|int|开始
|ed|end|int|结束
|ws|words|array|词
|cw|chinese word|array|中文分词
|w|word|string|单字
|sc|socre|int|分数

听写结果示例：

    {"sn":1,"ls":true,"bg":0,"ed":0,"ws":[
	{"bg":0,"cw":[{"w":" 今天 ","sc":0}]},
	{"bg":0,"cw":[{"w":" 的","sc":0}]},
	{"bg":0,"cw":[{"w":" 天气 ","sc":0}]},
	{"bg":0,"cw":[{"w":" 怎么样 ","sc":0}]},
	{"bg":0,"cw":[{"w":" 。","sc":0}]}]}

多候选结果示例：

    {"sn":1,"ls":false,"bg":0,"ed":0,"ws":[
    {"bg":0,"cw":[{"w":"我想听","sc":0}]},
    {"bg":0,"cw":[{"w":"拉德斯基进行曲","sc":0},{"w":"拉得斯进行曲","sc":0}]}]}

语法识别结果示例:

    {"sn":1,"ls":true,"bg":0,"ed":0,"ws":[
		        {"bg":0,"cw":[{"sc":"70","gm":"0","w":"北京到上海"},
			                  {"sc":"69","gm":"0","w":"天京到上海"},
			                  {"sc":"58","gm":"0","w":"东京到上海"}]}]}

