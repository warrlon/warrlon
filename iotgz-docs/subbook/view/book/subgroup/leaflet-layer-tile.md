# 地图瓦片层

地图瓦片层属于地图容器的一个图层，支持自定义地图瓦片地址，展示出你想要的瓦片地图。本文档为您介绍地图瓦片层各配置项的含义，帮助您快速准确地使用地图瓦片层组件。


## 配置

---

- **图层地址**：不同地图的瓦片图层地址

```javascript
图层1：http://map.geoq.cn/ArcGIS/rest/services/ChinaOnlineStreetPurplishBlue/MapServer/tile/{z}/{y}/{x}
图层2：http://webst02.is.autonavi.com/appmaptile?style=7&x={x}&y={y}&z={z}
图层3：https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png
```

![pic](/images/components/leaflet/tile-layer-1.png)


## 数据

---

```javascript
return [{
    "url": "http://webst02.is.autonavi.com/appmaptile?style=7&x={x}&y={y}&z={z}" 
}]
```

- **url**：同配置项一样，设置地图的瓦片地址，如果数据项进行了配置，会优先展示数据项的配置