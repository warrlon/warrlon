# 时间表盘

时间表盘是由基本仪表盘通过配置项转换而来，支持自定义文本图形和多系列数据配置，能够通过修改数据灵活地增加、删除或修改图形的展示效果。本文档为您介绍基本仪表盘各配置项的含义，帮助您快速准确地使用基础款仪表图组件。



## 配置

---

- **基础设置**

    - **width**：组件在编辑器中的宽度

    - **height**：组件在编辑器中的高度

    - **top**：组件与编辑器顶部的距离

    - **left**：组件与编辑器左侧的距离


- **提示框**

    - **显示/隐藏**：当鼠标悬浮到图表上的点时，是否展示其提示的信息

    - **触发类型**：如何触发提示框的展示

    - **格式**：提示框的展示内容可支持自定义配置，其中{a}表示系列名称、{b}表示表盘标题、{c}表盘数据值

    ![pic](/images/components/gauge/tooltips-1.png)

    - **背景颜色**：提示框的背景颜色，支持hex、rgb以及rgba格式的色值

    - **边线颜色**：提示框边线的颜色，支持hex、rgb以及rgba格式的色值

    - **边线宽度**：提示框边线的宽度，单位px

    - **内边距**：提示框的内边距，例如："5,5,5,5"，代表上右下左边距分别为5px、5px、5px、5px


- **自定义元素**

    > 该配置项为一个数组，可配置多个自定义元素，自定义的元素可以是普通文本也可以是图片

    - **类型**：选择自定义元素的类型，可选：文本、图片

    - **位置**

        - **控制类型**：位置的控制类型，可选：系统控制、手动控制

        - **系统控制**

            - **横向位置**：可选居左、居中、居右

            - **纵向位置**：可选上侧、居中、下侧

        - **手动控制**

            - **左边距**：自定义元素的左边距

            - **上边距**：自定义元素的上边距

    - **文本**

        - **文本内容**：文本所要展示的内容

        - **字号**：文本的字体大小

        - **颜色**：文本的颜色，支持hex、rgb以及rgba格式的色值

        - **字体**：文本的字体

        - **字体粗细**：文本字体的粗细
    
    ![pic](/images/components/gauge/graphic-1.png)

    - **图片**

        - **上传图片**：上传本地的图片

        - **图片宽度**：设置图片的宽度

        - **图片高度**：设置图片的高度

    ![pic](/images/components/gauge/graphic-2.png)


- **数据系列**

    > 该配置项为一个数组，可配置多个系列，编辑器将遍历数据，使数据通过一个或多个系列配置循环渲染。若需要自定义某些数据为特定样式则需要手动对数据进行排序

    - **系列名**：该系列的名称，设置后，可以提示框中进行配置展示

    ![pic](/images/components/gauge/tooltips-1.png)

    - **时间表盘**

        > 请注意：开启时间表盘后，对于表盘的某些特定配置项将不再生效，例如：表盘最大值、表盘起始角度、数据项配置......

        - **启用/关闭**：是否开启时间表盘。

        - **类型**：时间表盘展示的类型，可选：星期、时、分、秒进行展示

        - **自定义时间标题**：开启时间表盘后，标题将自动展示为当前时间，你可以对其进行自定义，年份：{year}、月份：{month}、日份：{day}、小时：{hour}、分钟：{minute}、秒：{second}

    ![pic](/images/components/gauge/time-1.png)

    - **全局**

        - **表盘最小值**：表盘中所容纳数值的最小值

        - **表盘最大值**：表盘中所容纳数值的最大值

        ![pic](/images/components/gauge/global-1.png)

        - **表盘大小**：编辑器中规定区域中表盘的大小

        ![pic](/images/components/gauge/global-2.png)

        - **表盘起始角度**：表盘开始位置处的角度

        - **表盘结束角度**：表盘结束位置处的角度

        ![pic](/images/components/gauge/global-3.png)

        - **表盘分割段数**：

        ![pic](/images/components/gauge/global-4.png)

        - **偏移**：

            - **水平方向**：水平方向的偏移距离

            - **垂直方向**：垂直方向的偏移距离

    - **表盘标题**

        - **显示/隐藏**：是否展示表盘的标题

        ![pic](/images/components/gauge/title-1.png)

        - **颜色**：标题的颜色，支持hex、rgb以及rgba格式的色值

        - **字号**：标题的字体大小

        - **字体**：标题的字体

        - **字体粗细**：标题的字体粗细

        - **背景颜色**：标题的背景颜色，支持hex、rgb以及rgba格式的色值

        - **边框颜色**：标题的边框颜色，支持hex、rgb以及rgba格式的色值

        - **边框边框**：标题的边框宽度

        - **边框圆角**：可使标题的边框棱角变圆，值越大，边框越接近椭圆

        ![pic](/images/components/gauge/title-2.png)

        - **阴影颜色**：标题的阴影颜色，支持hex、rgb以及rgba格式的色值

        - **阴影大小**：标题的阴影大小

        ![pic](/images/components/gauge/title-3.png)

        - **内边距**：标题的内边距，例如："5,5,5,5"，代表上右下左边距分别为5px、5px、5px、5px

        - **偏移**

            - **水平偏移**：控制标题在水平方向上的偏移距离

            - **上下偏移**：控制标题在锤子方向上的偏移距离

        ![pic](/images/components/gauge/title-4.png)

    - **表盘数值**

        > 表盘数值配置项与表盘标题类似，相关配置可直接参照表盘标题

        - **显示/隐藏**：是否展示表盘的数值

        - **格式**：表盘数值的展示内容可支持自定义配置，其中{value}表示表盘数值

        ![pic](/images/components/gauge/detail-2.png)

        - **颜色**：数值的颜色，支持hex、rgb以及rgba格式的色值

        - **字号**：数值的字体大小

        - **字体**：数值的字体

        - **字体粗细**：数值的字体粗细

        - **背景颜色**：数值的背景颜色，支持hex、rgb以及rgba格式的色值

        - **边框颜色**：数值的边框颜色，支持hex、rgb以及rgba格式的色值

        - **边框边框**：数值的边框宽度

        - **边框圆角**：可使数值的边框棱角变圆，值越大，边框越接近椭圆

        - **阴影颜色**：数值的阴影颜色，支持hex、rgb以及rgba格式的色值

        - **阴影大小**：数值的阴影大小

        - **内边距**：数值的内边距，例如："5,5,5,5"，代表上右下左边距分别为5px、5px、5px、5px
        
        - **偏移**

            - **水平偏移**：控制标题在水平方向上的偏移距离

            - **上下偏移**：控制标题在锤子方向上的偏移距离
        
    ![pic](/images/components/gauge/detail-1.png)

    - **表盘轴线**

        - **显示/隐藏**：是否展示表盘轴线

        ![pic](/images/components/gauge/axisLine-1.png)  

        - **样式**

            - **阴影颜色**：轴线阴影颜色

            - **阴影大小**：轴线阴影大小

            - **轴线宽度**：轴线的宽度

            - **系列色**：轴线的宽度

                > 仪表盘的轴线可以被分成不同颜色的多段，end表示每段的结束位置和color表示颜色

                - **结束位置**：该段轴线的宽度

                - **颜色**：该段轴线的颜色

    ![pic](/images/components/gauge/axisLine-2.png)  

    - **表盘分割线**

        - **显示/隐藏**：是否展示表盘的分割线

        - **长度**：分割线的长度

        - **样式**

            - **颜色**：分割线的颜色，支持hex、rgb以及rgba格式的色值

            - **宽度**：分割线的宽度

            - **类型**：分割线的类型，可选实线、虚线

            - **阴影颜色**：分割线阴影颜色，支持hex、rgb以及rgba格式的色值

            - **阴影大小**：分割线的阴影大小

    ![pic](/images/components/gauge/splitLine-1.png)

    - **表盘刻度线**

        - **显示/隐藏**：是否展示表盘的刻度线

        - **刻度线数量**：表盘刻度线的数量

        - **刻度线长度**：表盘刻度线的长度

        - **样式**

            - **颜色**：刻度线的颜色，支持hex、rgb以及rgba格式的色值

            - **宽度**：刻度线的宽度

            - **类型**：刻度线的类型，可选实线、虚线

            - **阴影颜色**：刻度线阴影颜色，支持hex、rgb以及rgba格式的色值

            - **阴影大小**：刻度线的阴影大小

    ![pic](/images/components/gauge/axisTick-1.png)

    - **表盘刻度标签**

        > 表盘刻度标签配置项与表盘标题类似，相关配置可直接参照表盘标题

        - **显示/隐藏**：是否展示表盘的刻度标签

        - **标签与刻度线间距**：表盘刻度标签与刻度线之间的距离

        - **格式**：刻度标签的展示内容可支持自定义配置，其中{value}表示其刻度值

        - **颜色**：刻度标签的颜色，支持hex、rgb以及rgba格式的色值

        - **字号**：刻度标签的字体大小

        - **字体**：刻度标签的字体

        - **字体粗细**：刻度标签的字体粗细

        - **背景颜色**：刻度标签的背景颜色，支持hex、rgb以及rgba格式的色值

        - **边框颜色**：刻度标签的边框颜色，支持hex、rgb以及rgba格式的色值

        - **边框边框**：刻度标签的边框宽度

        - **边框圆角**：可使刻度标签的边框棱角变圆，值越大，边框越接近椭圆

        - **阴影颜色**：刻度标签的阴影颜色，支持hex、rgb以及rgba格式的色值

        - **阴影大小**：刻度标签的阴影大小

        - **内边距**：刻度标签的内边距，例如："5,5,5,5"，代表上右下左边距分别为5px、5px、5px、5px
            
    ![pic](/images/components/gauge/axisLabel-1.png)

    - **表盘指针**

        - **显示/隐藏**：是否展示表盘的指针

        - **指针长度**：表盘指针的长度

        - **指针宽度**：表盘指针的宽度

        - **样式**

            - **指针颜色**：指针的颜色，支持hex、rgb以及rgba格式的色值

            - **指针边框颜色**：指针边框的颜色，支持hex、rgb以及rgba格式的色值

            - **边框宽度**：指针的边框宽度

            - **边框类型**：指针的边框类型，可选实线、虚线

            - **阴影颜色**：指针的阴影颜色，支持hex、rgb以及rgba格式的色值

            - **阴影大小**：指针的阴影大小

            - **透明度**：指针的透明度

        - **高亮**

            - **指针颜色**：指针的颜色，支持hex、rgb以及rgba格式的色值

            - **指针边框颜色**：指针边框的颜色，支持hex、rgb以及rgba格式的色值

            - **边框宽度**：指针的边框宽度

            - **边框类型**：指针的边框类型，可选实线、虚线

            - **阴影颜色**：指针的阴影颜色，支持hex、rgb以及rgba格式的色值

            - **阴影大小**：指针的阴影大小

            - **透明度**：指针的透明度

    ![pic](/images/components/gauge/pointer-1.png)




## 数据

---

```javascript
return [{
    graphic:[{
        text:"OneView"
    },{
        image:"https://open.iot.10086.cn/v4/static/common/file/logo.png"
    }],
    data:[{
        value: 50, 
        name: '完成率'
    }]
}]
```


> 如果在配置项和数据项均对自定义元素进行了配置，系统会优先选择数据项的配置

- **graphic**：自定元素集合

    - **text**：自定义的文本内容

    - **image**：自定义图片的在线链接地址

- **data**：仪表盘数据集合

    - **value**：表盘数据值

    - **name**：表盘标题名称

![pic](/images/components/gauge/data-1.png)