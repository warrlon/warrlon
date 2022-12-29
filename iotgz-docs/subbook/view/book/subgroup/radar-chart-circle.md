# 雷达图-圆形

雷达图是常规图表中的一种，支持自定义文本、图形，支持多系列数据配置，能够使用雷达图直观地展示多维度的类目数据对比情况。本文档为您介绍基本雷达图各配置项的含义，帮助您快速准确地使用基本雷达图组件。



## 配置

---

- **基础设置**

    - **width**：组件在编辑器中的宽度

    - **height**：组件在编辑器中的高度

    - **top**：组件与编辑器顶部的距离

    - **left**：组件与编辑器左侧的距离



- **雷达图设置**

    - **绘制类型**：控制雷达图的轮廓样式，可选圆形、多边形

    ![pic](/images/components/radar-chart/radar-1.png)

    - **半径比例**：雷达图在固定区域中的展示大小

    ![pic](/images/components/radar-chart/radar-2.png)

    - **名称与轴的间距**：雷达图名称与轴的间距大小

    ![pic](/images/components/radar-chart/radar-3.png)

    - **分割段数**：雷达图的分割区域层级

    ![pic](/images/components/radar-chart/radar-4.png)

    - **指示器名称**

        - **显示/隐藏**：是否展示指示器名称

        - **字号**：指示器名称的字体大小

        - **颜色**：指示器名称的颜色，支持hex、rgb以及rgba格式的色值

        - **字体粗细**：指示器名称字体的粗细

        - **字体**：指示器名称的字体

        - **背景颜色**：指示器的背景颜色

        - **上下内边距**：指示器的上下内边距

        - **左右内边距**：指示器的左右内边距

    ![pic](/images/components/radar-chart/radar-name-1.png)

    - **轴线**

        - **显示/隐藏**：是否展示轴线

        - **箭头**：轴线两端的箭头

        - **轴线样式**

            - **颜色**：轴线的颜色，支持hex、rgb以及rgba格式的色值

            - **粗细**：轴线的粗细

            - **样式**：轴线的样式，可选实线、虚线

            - **透明度**：轴线的透明度

    ![pic](/images/components/radar-chart/radar-line-1.png)

    - **分割线**

    - **显示/隐藏**：是否展示分割线

    - **分割线样式**

        - **颜色**：分割线的颜色，支持hex、rgb以及rgba格式的色值

        - **粗细**：分割线的粗细

        - **样式**：分割线的样式，可选实线、虚线

        - **透明度**：分割线的透明度

    ![pic](/images/components/radar-chart/radar-split-1.png)

    - **分割区域**

    - **显示/隐藏**：是否展示分割区域

    - **分割区域样式**

        - **间隔色1**：奇数间隔区域颜色，支持hex、rgb以及rgba格式的色值

        - **间隔色2**：偶数间隔区域颜色，支持hex、rgb以及rgba格式的色值

        - **透明度**：分割区域的透明度

    ![pic](/images/components/radar-chart/radar-area-1.png)


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

![pic](/images/components/radar-chart/title-1.png)



- **提示框**

    - **显示/隐藏**：当鼠标悬浮到图表上的点时，是否展示其提示的信息

    - **触发类型**：如何触发提示框的展示

    - **格式**：提示框的展示内容可支持自定义配置，其中{b}表示数据名、{c}表示数据值

    ![pic](/images/components/radar-chart/tooltips-1.png)

    - **背景颜色**：提示框的背景颜色，支持hex、rgb以及rgba格式的色值

    - **边线颜色**：提示框边线的颜色，支持hex、rgb以及rgba格式的色值

    - **边线宽度**：提示框边线的宽度，单位px

    - **内边距**：提示框的内边距，例如："5,5,5,5"，代表上右下左边距分别为5px、5px、5px、5px



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

![pic](/images/components/radar-chart/legend-1.png)



- **数据系列**

     > 该配置项为一个数组，可配置多个系列，编辑器将遍历数据，使数据通过一个或多个系列配置循环渲染。若需要自定义某些数据为特定样式则需要手动对数据进行排序

    - **拐点标记**

        - **标记图形**：可选圆形、正方形、三角形、菱形、针形、箭头

        - **标记大小**：标记图形的大小

        ![pic](/images/components/radar-chart/series-1.png)

        - **标记颜色**：标记图形的颜色，支持hex、rgb以及rgba格式的色值

        - **标记透明度**：标记图形的透明度

        - **标签**

            - **显示/隐藏**：是否显示标记图形处的标签

            - **与标记的间距**：标签与标记图形的间距

            - **字号**：标签的字体大小

            - **颜色**：标签的颜色，支持hex、rgb以及rgba格式的色值

            - **字体**：标签的字体

            - **字体粗细**：标签的字体粗细

        ![pic](/images/components/radar-chart/series-2.png)

        - **高亮**

            - **开启高亮**：是否开启高亮

            - **标记颜色**：高亮状态下标记图形的颜色，支持hex、rgb以及rgba格式的色值

            - **标记透明度**：高亮状态下标记图形的透明度


    - **连接线**

        - **颜色**：连接线的颜色，支持hex、rgb以及rgba格式的色值

        - **线宽**：连接线的宽度，单位px

        - **样式**：连接线的样式，可选实线、虚线

        - **透明度**：连接线的透明度

        - **高亮**

            - **开启高亮**：是否开启高亮

            - **颜色**：高亮状态下连接线的颜色，支持hex、rgb以及rgba格式的色值

            - **线宽**：高亮状态下连接线的宽度，单位px

            - **样式**：高亮状态下连接线的样式，可选实线、虚线

            - **透明度**：高亮状态下连接线的透明度

        ![pic](/images/components/radar-chart/series-3.png)


    - **连接区域**

        - **颜色**：连接区域的颜色，支持hex、rgb以及rgba格式的色值

        - **透明度**：连接区域的透明度

        - **高亮**

            - **开启高亮**：是否开启高亮

            - **颜色**：高亮状态下连接区域的颜色，支持hex、rgb以及rgba格式的色值

            - **透明度**：高亮状态下连接区域的透明度

        ![pic](/images/components/radar-chart/series-4.png)




## 数据

---

```javascript
return [{
    indicator:[
        { name: '指标1',max: 100, min:0 },
        { name: '指标2',max: 100, min:0 },
        { name: '指标3',max: 100, min:0 },
        { name: '指标4',max: 100, min:0 },
        { name: '指标5',max: 100, min:0 },
        { name: '指标6',max: 100, min:0 }
    ],
    data:[{
        value: [ 50, 50, 50, 50, 50, 50],
        name: '公司A',
    }]
}]
```
![pic](/images/components/radar-chart/data-1.png)


- **indicator**：指示器数据，用来指定雷达图中的变量维度

    - **name**：指示器名称

    - **max**：指示器的最大值

    - **min**：指示器的最小值
    

- **data**：雷达图数据集合

    - **name**：数据名称

    - **value**：数据值

```javascript
return [{
    indicator:[
        { name: '语12文', max: 100, min:0 },
        { name: '数撒旦士大夫学', max: 100, min:0 },
        { name: '英语', max: 100, min:0 },
        { name: '物理', max: 100, min:0 },
        { name: '化学', max: 100, min:0 },
        { name: '生物', max: 100, min:0 }
    ],
    data:[{
        value: [ 70, 95, 60, 80, 30, 60],
        name: '小王',
    }]
}]
```
![pic](/images/components/radar-chart/data-2.png)