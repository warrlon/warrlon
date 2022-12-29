# 地图热力层

地图热力层属于地图容器的一个图层，支持自定义GeoJSON数据，通过渐变色展示出不同区域的数值大小。本文档为您介绍地图热力层各配置项的含义，帮助您快速准确地使用地图热力层组件。



## 配置

---

- **填充颜色**

    - **最大值**：最大数值区域的填充颜色，支持hex、rgb以及rgba格式的色值

    - **最小值**：最小数值区域的填充颜色，支持hex、rgb以及rgba格式的色值

    - **无数据**：没有数据的区域填充颜色，支持hex、rgb以及rgba格式的色值

![pic](/images/components/leaflet/hotArea-layer-1.png)

- **边线选项**

    - **颜色**：描边区域的边线颜色，支持hex、rgb以及rgba格式的色值

    - **粗细**：边线的粗细

    - **类型**：边线的类型，可选实线、虚线、点

![pic](/images/components/leaflet/hotArea-layer-2.png)

- **交互设置**

    - **悬停**

        - **悬停颜色**：鼠标悬停到该区域时所展示的颜色,支持hex、rgb以及rgba格式的色值

        ![pic](/images/components/leaflet/hotArea-layer-3.png)

    - **点击**

        - **显示弹窗**：鼠标点击该区域后，是否展示弹窗

        ![pic](/images/components/leaflet/hotArea-layer-4.png)

## 数据

---

```javascript
return { 
    "type": "FeatureCollection", 
    "features": [{ 
        "type": "Feature", 
        "properties": { 
            "name": "内蒙古自治区", 
            "adchar": "NM", 
            "adcode": "150000",
            "data": 100          //区域的数值，设置的颜色深浅将会依赖于该值进行展示
        }, 
        "geometry": { 
            "type": "MultiPolygon", 
            "coordinates": [......]
        }
    }]
}
```