# iframe加载器

iframe加载器是多媒体组件的一种，支持自定义iframe链接，适用于将网页嵌入大屏中进行显示。本文档为您介绍iframe各配置项的含义，帮助您快速准确地使用iframe组件。



## 配置

---

- **基础设置**

    - **width**：组件在编辑器中的宽度

    - **height**：组件在编辑器中的高度

    - **top**：组件与编辑器顶部的距离

    - **left**：组件与编辑器左侧的距离


- **iframe地址**：配置组件所显示页面的链接



## 数据

---

```javascript
return [{
    src: "https://open.iot.10086.cn/doc/"
}]
```

- **src**：配置组件所显示页面的链接，与配置项冲突时，优先展示数据中的配置






## 使用

---

> 为了应对更多复杂场景，编辑器提供了向iframe窗口单方向通信的接口，你可以在引入的iframe窗口中添加如下代码实现单向通信

```html
<script type="text/javascript">
    window.addEventListener("message", function(event) {
        console.log(event.data);
    }, false);
</script>
```

- **setId**：当iframe窗口在编辑器中加载时，便会收到来自"setId"的一个信息，此信息会返回该窗口在编辑器中的"id"属性

- **dataChange**：编辑器中的数据源一旦改变便会收到"dataChange"的一个消息，此信息会返回绑定的数据源结果