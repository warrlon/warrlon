# 基本饼图

基础饼图是饼图的一种，支持自定义图形样式和多系列数据配置，能够通过修改数据灵活地增加、删除或修改图形的展示效果，适用于展示较多类别数据的占比情况。本文档为您介绍基础款饼图各配置项的含义，帮助您快速准确地使用基础款饼图组件。





## 配置

---

- **基础设置**

    - **width**：组件在编辑器中的宽度

    - **height**：组件在编辑器中的高度

    - **top**：组件与编辑器顶部的距离

    - **left**：组件与编辑器左侧的距离


- **全局**

    - **高亮扇区的偏移距离**：控制扇区呈现高亮状态时放大的比例，偏移距离越大放大比例越大

    ![pic](/images/components/pie-chart/global-1.png)

    - **间隙大小**：控制扇形区域之间的间隙，值越大间隙越大

    ![pic](/images/components/pie-chart/global-2.png)

    - **起始角度**：扇区起始角度值

    ![pic](/images/components/pie-chart/global-3.png)

    - **半径**：通过半径的设置可以使饼图中间镂空形成一个圆圈

        - **内半径**：饼图内圈的半径大小

        - **外半径**：饼图外圈的半径大小
    
    ![pic](/images/components/pie-chart/global-4.png)

    - **边线**：饼图外半径的边线

        - **边线宽度**：边线的宽度，单位px

        - **边线颜色**：边线的颜色，支持hex、rgb以及rgba格式的色值
    
    ![pic](/images/components/pie-chart/global-5.png)

    - **标签**

        - **显示/隐藏**：是否展示该图表的标签

        - **仅高亮展示**：标签仅在扇区呈现高亮状态时才进行展示

        ![pic](/images/components/pie-chart/global-6.png)

        - **位置**：控制标签展示的位置，可选：外侧、内侧、中心

        ![pic](/images/components/pie-chart/global-7.png)

        - **颜色**：标签的颜色，支持hex、rgb以及rgba格式的色值

        - **字号**：标签的字体大小

        - **字体粗细**：标签字体的粗细

        - **字体**：标签的字体

        - **格式**：标签的展示内容可支持自定义配置，其中{b}表示数据名、{c}表示数据值、{d}表示百分比

        ![pic](/images/components/pie-chart/global-8.png)

    - **南丁格尔图**：可通过半径和圆心维度区分数据大小

        - **开启/关闭**：是否以南丁格尔图的形式进行展示

        - **模式**：选择展现的形式，可选：半径、半径和圆心
    
    ![pic](/images/components/pie-chart/global-9.png)



- **标题**

    - **显示/隐藏**：是否展示该图表的标题

    - **标题名称**：该图表的标题的名称

    - **左边距**：标题离容器左侧的距离

    - **上边距**：标题离容器上侧的距离

    - **文本样式**

        - **字号**：标题的字体大小

        - **颜色**：标题的颜色，支持hex、rgb以及rgba格式的色值

        - **字体**：标题的字体

        - **字体粗细**：标题字体的粗细

![pic](/images/components/pie-chart/title-1.png)



- **提示框**

    - **显示/隐藏**：当鼠标悬浮到图表上的点时，是否展示其提示的信息

    - **触发类型**：如何触发提示框的展示

    - **格式**：提示框的展示内容可支持自定义配置，其中{b}表示数据名、{c}表示数据值、{d}表示百分比

    ![pic](/images/components/pie-chart/tooltips-1.png)

    - **背景颜色**：提示框的背景颜色，支持hex、rgb以及rgba格式的色值

    - **边线颜色**：提示框边线的颜色，支持hex、rgb以及rgba格式的色值

    - **边线宽度**：提示框边线的宽度，单位px

    - **内边距**：提示框的内边距，例如："5,5,5,5"，代表上右下左边距分别为5px、5px、5px、5px

![pic](/images/components/pie-chart/tooltips-2.png)



- **图例**

    - **显示/隐藏**：是否展示该表图的图例

    - **左间距**：图例与容器左侧的距离

    - **顶间距**：图例与容器上侧的距离

    - **排列方向**：图例的排列方向，可选择水平 or 垂直进行展示

    - **图例图标**：图例的图标，可选圆形、方形、三角形、菱形图标进行展示

    - **文本样式**

        - **字号**：图例的字体大小

        - **颜色**：图例的颜色，支持hex、rgb以及rgba格式的色值

        - **字体**：图例的字体

        - **字体粗细**：图例的字体粗细

![pic](/images/components/pie-chart/legend-1.png)



- **高亮轮播**

    - **是否轮播**：开启轮播后，饼图将自动高亮展示

    - **展示提示框**：轮播时，是否展示提示框

    - **动画间隔**：轮播的动画时间间隔，值越小，轮播速度越快

<div align="left">
    ![pic](/images/components/pie-chart/carousel-1.png')" with="350" height="170">
    ![pic](/images/components/pie-chart/carousel-2.gif')" height="170">
</div>




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
    
    ![pic](/images/components/pie-chart/series-1.png)

    - **图片**

        - **上传图片**：上传本地的图片

        - **图片宽度**：设置图片的宽度

        - **图片高度**：设置图片的高度

    ![pic](/images/components/pie-chart/series-2.png)




## 数据

---



```javascript
return [{
    graphic:[{
        text:"OneView"
    },{
        image:"https://open.iot.10086.cn/v4/static/common/file/logo.png"
    }],
    data:[
        { value: 62031, name: '奶牛', color:"#1089E7"},
        { value: 13521, name: '公鸡', color:"#F57474"},
        { value: 47655, name: '山羊', color:"#8B78F6"},
        { value: 92129, name: '竹鼠', color:"#56D0E3"},
        { value: 92129, name: '母猪', color:"#F8B448"},
    ]
}]
```

> 如果在配置项和数据项均对自定义元素进行了配置，系统会优先选择数据项的配置

- **graphic**：自定元素集合

    - **text**：自定义的文本内容

    - **image**：自定义图片的在线链接地址

![pic](/images/components/pie-chart/data-1.png)

- **data**：扇区数据集合

    - **value**：扇区数值

    - **name**：扇区名称

    - **color**：扇区颜色

![pic](/images/components/pie-chart/data-2.png)