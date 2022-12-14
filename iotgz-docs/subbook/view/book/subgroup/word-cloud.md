# 词云

词云是文字组件的一种，支持自定义文本的内容、颜色、绘制形状等，支持多系列颜色配置，支持根据权重值映射文本大小，能够以词云的形式在大屏中展示较多数量的文本。本文档为您介绍词云各配置项的含义，帮助您快速准确地使用词云组件。



## 配置

---

- **基础设置**

    - **width**：组件在编辑器中的宽度

    - **height**：组件在编辑器中的高度

    - **top**：组件与编辑器顶部的距离

    - **left**：组件与编辑器左侧的距离


- **全局样式**

    - **字体**：词云中每一个单词的字体

    - **字体最大比例**：词云中单词展示的最大比例

    - **字体最小比例**：词云中单词展示的最小比例


- **布局**：控制词云的排列方式



- **单词间距比例**：单词之间的间距，比例越大，单词之间的间距也越大




## 数据

---

```javascript
return [{
    text:"OneView",
    color:"#48a7f4",
    weight:8,
    rotation:50,
    fontWeight:"bolder"
}, ......]
```

- **text**：单词内容

- **color**：单词颜色

- **weight**：单词大小比例

- **rotation**：单词旋转角度

- **fontWeight**：单词字体粗细