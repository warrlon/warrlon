# 回调变量

## 什么是回调变量

在 OneNET View 中，`回调变量` 是指某个组件在响应用户操作或者自动触发更新时向别的组件或者数据源传递的参数。

在数据源中使用回调变量时，这个变量值可以用于数据查询时的动态变量。

例如，有些场景需要分页，我们可以在分页组件里面传递 `page` 参数，API 接口接收这个 `page` 变量之后，就可以动态去查询对应的页面数据。

![pic](/images/data/set-variables.jpg)

## 配置回调变量

### 在组件交互标签页下配置

当我们选中组件时，编辑器右侧会出现`设置`区，在该区域`交互`选项卡里，可以进行回调变量的设置。

每个回调变量均有一个独立的`启用`开关。

可以根据使用场景修改“绑定到变量”中的变量名称。

![pic](/images/data/interact-tab.png)

如图，我们将文本组件的值，绑定到变量`city`上，当文本组件被点击时(无特殊说明的交互事件，默认是组件被点击事件)，项目中会设置一个变量名为`city`，值为文本组件 value 值(图中的值为'重庆')

### 从项目 URL 链接上配置

> 系统已经占用的 query 参数不能被设置成回调变量，目前有：
> `id`,`shareCode`,`debug`

我们可以通过在 url 中设置`query`参数的形式来设置回调变量及对应的默认值，如：

```
http://open.iot.10086.cn/view/main/#/view2d?id=5e68872cb390c9c2e9af7ba9&hello=lingc
```

通过这个 url 访问时，在页面打开的时候，回调变量 `hello` 的值已经设置为`lingc`了。

多个回调变量之间使用&符号连接，如

```
http://open.iot.10086.cn/view/main/#/view2d?id=5e68872cb390c9c2e9af7ba9&hello=lingc&city=chongqing
```

这里同时设置了回调 `hello` 和 `city` 的默认值。

## 查看项目回调变量

我们在编辑页面和浏览页面(分享页面除外),提供了变量查看按钮，点击变量按钮后，将出现项目当前的变量以及对应的值。
![pic](/images/data/view-var.png)

## 使用回调变量

### 在数据源中使用

在数据源中使用:变量名(如:city)即可使用对应的回调变量。

#### 在 API 数据源中使用

API 数据源中，在 Path、Query、Header 以及 Body 中，均支持用回调变量来设置键值。如：
![pic](/images/data/use-api-var.png)
此处

```
http://apis.juhe.cn/simpleWeather/query?city=:city&key=73a0b2fe78c2e9d07df67ca848213ad7
```

中的`:city`在实际请求时，会被替换成回调变量具体的值。

#### 在 OneNET 数据源中使用

有了回调变量的支持，结合 OneNET 数据源，我们可以实现，在同一个大屏中切换观察多个 OneNET 设备数据。

> 设置设备变量后，如变量有值，则直接使用变量值作为设备 id
> 设置数据流变量后，如变量有值，则直接使用变量值作为数据流 id

如：
![pic](/images/data/use-onenet-var.png)
上图中的 OneNET 数据源，设备和数据流均绑定了回调变量。当回调变量有值时，优先采用回调变量的值，否则，采用下拉框选中的设备和数据流。


### 在过滤器中使用

在过滤器中使用:通过过滤器中参数variables即可访问到回调变量

#### 查看回调变量

<br>

![pic](/images/data/variables-1.png)

#### 使用回调变量

<br>

![pic](/images/data/variables-2.png)