# 数据使用

### **1.约定**

在数据可视化平台中，所有最终传递给组件的数据，都需要是一个对象数组，即使该组件只接收一个数据点，如折线图接收的最终数据：

````java
[
  {
    "x": "2010/01/01 00:00:00",
    "y1": 375,
    "y2": "1"
  },
  {
    "x": "2010/01/01 00:00:00",
    "y1": 180,
    "y2": "2"
  },
  {
    "x": "2010/02/01 00:00:00",
    "y1": 200,
    "y2": "1"
  },
  {
    "x": "2010/02/01 00:00:00",
    "y1": 100,
    "y2": "2"
  },
  {
    "x": "2010/03/01 00:00:00",
    "y1": 25,
    "y2": "1"
  },
  {
    "x": "2010/03/01 00:00:00",
    "y1": 125,
    "y2": "2"
  },
  {
    "x": "2010/04/01 00:00:00",
    "y1": 190,
    "y2": "1"
  },
  {
    "x": "2010/04/01 00:00:00",
    "y1": 110,
    "y2": "2"
  },
  {
    "x": "2010/05/01 00:00:00",
    "y1": 90,
    "y2": "1"
  },
  {
    "x": "2010/05/01 00:00:00",
    "y1": 60,
    "y2": "2"
  }
]
````

仪表盘接收的最终数据：

````java
[
 {
    "name": "温度",
    "value": 37.5,
 }
]
````

我们可以通过一些配置来生成这个数据对象数组。

### **2.数据配置表单**

当选中某个组件后，系统会自动显示该组件的数据配置表单。

<div align=center><img src ="/images\qinghua\device-management\configure-form.png"/></div>

在字段描述区域，会罗列当前组件可配置的数据项、数据源配置与选择创建数据源。物联平台采用应用中的数据源统一管理的模式，当组件需要使用某一个数据时，应先配置好数据源再选择该数据源，系统支持多种类型的数据源。

### **3.数据源**

- 静态JSON数据

添加数据源时，选择静态数据，将正确的JSON格式数据，填写到数据栏，保存即可。  
- 第三方API

您可以在数据可视化平台使用任何平台的API接口作为数据源接入。数据可视化平台的API接入类似于接口调试工具postman。首先您需要知道API请求地址，鉴权方式以及所需参数及参数的值。您可以询问提供给您API的开发人员获取这些信息。目前，我们支持使用GET、POST方式来请求第三方API。

- 接口路径 

接口路径填写URL，当检测到您填写的 URL 中包含Query参数时，系统会自动将它们解析到Query列表中。  
- Query

这里代表的含义类似于
````
http://aaa.com/user?name=sx&pass=111 
````
这个地址中的name=sx&pass=111这样的参数。  
- Header

Header列表中的配置，会被拼成HTTP请求时的自定义头部，通常，我们可以在Header中填写鉴权信息。  
- Body

当我们切换请求方式到POST时，会出现Body这个标签页。目前仅支持以键值对形式（key-value)组织请求Body。

### **4.数据源模板**

将一些已经设置好部分或全部配置项的数据源保存成数据源模板，下次创建类似的数据源时，就可以选择从这个数据源模板快速实例化创建。需要说明的是，数据源模板是跨应用的，同个用户账号下的数据源模板，在应用A创建，则在应用A可用，在应用B同样可用，而数据源仅在它被创建的那个应用下可用。 所以，当多个应用需要同一个数据源时，可以先把该数据源保存成模板，再在需要这个数据源的应用内用这个数据源模板实例化出数据源。

### **5.数据配置举例**

- 选择组件

选中一个组件，首先要看数据选项卡的组件接口说明。

<div align=center><img src ="/images\qinghua\device-management\component-interfaces.png"/></div>

我们以基础地图组件为例，该组件要求数据要由deviceName:{lon:'',lat:''}的数据点组成，数据可视化平台系统约定，传递给组件的数据必须是一个对象数组，所以传给组件最终数据格式应该是：

````java
[
  {
    "dev1": {
      "lon": 116.404,
      "lat": 39.915
    }
  },
  {
    "dev1": {
      "lon": 116.404,
      "lat": 39.815
    }
  }
  ...
]
````

- 查看初始私有过滤器

如果接口字段说明还无法清晰表达组件所接受的数据格式，组件在被新增到画布的初始状态下，都会有一个初始私有过滤器，这个初始过滤器提供了本组件接受的数据格式样例。
- 选择数据源

为了使地图组件中的点是根据数据源动态来新增或更改的，我们要在数据源选择中选带有地图数据点信息的数据源。

<div align=center><img src ="/images\qinghua\device-management\data-source-select.png"/></div>

暂时先不适用过滤器，先点击数据处理结果查看当前数据源的数据。

````java
[
  {
    "update_at": "2019-03-28 16:44:54",
    "id": "map",
    "create_time": "2018-11-05 10:34:31",
    "current_value": {
      "lon": "116.40530370152352",
      "lat": "39.90664650680615"
    },
    "at": "2019-03-28 16:44:54",
    "value": {
      "lon": "116.40530370152352",
      "lat": "39.90664650680615"
    }
  },
  {
    "update_at": "2019-03-28 16:44:59",
    "id": "map",
    "create_time": "2018-11-05 10:34:31",
    "current_value": {
      "lon": "116.41210366734866",
      "lat": "39.90668046099908"
    },
    "at": "2019-03-28 16:44:59",
    "value": {
      "lon": "116.41210366734866",
      "lat": "39.90668046099908"
    }
  },
  {
    "update_at": "2019-03-28 16:45:03",
    "id": "map",
    "create_time": "2018-11-05 10:34:31",
    "current_value": {
      "lon": "116.42254386324525",
      "lat": "39.90675495735355"
    },
    "at": "2019-03-28 16:45:03",
    "value": {
      "lon": "116.42254386324525",
      "lat": "39.90675495735355"
    }
  }
]
````

### **6.使用过滤器**

我们发现，数据源数据与基础地图组件的数据格式并不一致，需要使用数据过滤器做一些处理(数据过滤器只支持es5语法)。

````java
// 最终数据应该是一个数组
var result = [];
var dataPoint = null;
//循环处理选中的数据源的数据点
for (var i = 0; i < data.length; i++) {
  // 从数据点中取出需要的数据，通过配置键值对使得数据格式符合要求
  dataPoint = {
    dev1: {
      lon: data[i].value.lon,
      lat: data[i].value.lat,
    },
  };
  // 将这个数据点添加进结果中
  result.push(dataPoint);
}
return result;
````

在过滤器代码编辑区写入以上代码，点击保存，然后选中启用这个过滤器，就可以看到最后的数据处理结果了。

<div align=center><img src ="/images\qinghua\device-management\filter-configuration.png"/></div>

这个结果就符合组件的要求了。

<div align=center><img src ="/images\qinghua\device-management\data-processing-results.png"/></div>

### **7.数据过滤器**

数据可视化平台 支持用户自定义过滤器，用户可以自行写入javascript代码，借助过滤器实现数据结构转换、筛选和一些简单的计算。当前暂不支持es6及更高版本的ECMAScript语法，当出现以下情况，您可能需要使用数据过滤器：

- 数据源的值与组件中格式不相同
- 一个组件需要同时使用多个数据源

点击数据过滤器，勾选复选框，启用数据过滤器功能。在代码编辑区填写您的代码，过滤器在使用之前会先进行代码安全监测，无法通过安全监测的过滤器将不能使用。

### **8.数据过滤器类型**

数据可视化平台包含两种类型的过滤器：

- 私有过滤器：每个组件各自拥有一个不影响其他组件的过滤器，且这个过滤器只能这个组件自己使用。

- 全局过滤器：可以设计一些每个组件都可选择是否使用的过滤器。这些过滤器一旦被修改，将影响到所有使用到它的组件。

### **9.过滤器传参**

每个过滤器都是一个javascript函数，我们预先定义了这个过滤器函数的三个参数data 、rootData、variables:

- data:当前组件选中的数据源数据

- rootData:包含所有数据源数据的根对象

- variables:回调变量

- rootData是数据源列表，它是一个以数据源Id-数据值列表为键值对的对象，包含了该项目中所有的数据源。

### **10.数据过滤器常用代码**

数据可视化平台提供了过滤器来对数据源进行个性化处理，用户可以自行写入JavaScript代码，实现数据结构转换、筛选和一些简单的计算。本文将列举一些常用的过滤器代码供参考。

- 迭代处理

通常数据源返回的结果大多是数组类型，通过迭代可以对每个元素进行处理。

````java
data.forEach((item, index) => {
  // console.log('元素：', item, '；下标：', index);
});
````

- 获取数组第一项

````java
// first([1, 2]); // -> 1
function first(arr) {
  var len = arr ? arr.length : 0;
  if (len) return arr[0];
}
````

- 获取数组最后一项

````java
// last([1, 2]); // -> 2
function last(arr) {
  var len = arr ? arr.length : 0;
  if (len) return arr[len - 1];
}
````

- 数组最大值，最小值

````java
//数组最大值
function maxArr(arr) {
  return Math.max.apply(null, arr);
}
//数组最小值
function minArr(arr) {
  return Math.min.apply(null, arr);
}
````

- 数组求和，平均值

````java
// 这一块的封装，主要是针对数字类型的数组
// 求和
function sumArr(arr) {
  return arr.reduce(function(pre, cur) {
    return pre + cur;
  });
}
// 数组平均值,小数点可能会有很多位，这里不做处理
function covArr(arr) {
  return this.sumArr(arr) / arr.length;
}
````

- 从数组中随机获取元素

````java
function randomOne(arr) {
  return arr[Math.floor(Math.random() * arr.length)];
}
````

- 随机返回一个范围的数字

````java
//ecDo.randomNumber(5,10)
//返回5-10的随机整数，包括5，10
//ecDo.randomNumber(10)
//返回0-10的随机整数，包括0，10
//ecDo.randomNumber()
//返回0-255的随机整数，包括0，255
function randomNumber(n1, n2) {
  if (arguments.length === 2) {
    return Math.round(n1 + Math.random() * (n2 - n1));
  } else if (arguments.length === 1) {
    return Math.round(Math.random() * n1);
  } else {
    return Math.round(Math.random() * 255);
  }
}
````

- 时间格式处理

````java
/**
 *@param timestamp 时间戳
 **/
function formatDate(timestamp) {
  var date = new Date(timestamp); //时间戳为10位需*1000，时间戳为13位的话不需乘1000
  var Y = date.getFullYear() + '-';
  var M =
    (date.getMonth() + 1 < 10
      ? '0' + (date.getMonth() + 1)
      : date.getMonth() + 1) + '-';
  var D = (date.getDate() < 10 ? '0' + date.getDate() : date.getDate()) + ' ';
  var h =
    (date.getHours() < 10 ? '0' + date.getHours() : date.getHours()) + ':';
  var m =
    (date.getMinutes() < 10 ? '0' + date.getMinutes() : date.getMinutes()) +
    ':';
  var s = date.getSeconds() < 10 ? '0' + date.getSeconds() : date.getSeconds();
  return Y + M + D + h + m + s;
}
````

- 返回数组（字符串）一个元素出现的次数

````java
//ecDo.getEleCount('asd56+asdasdwqe','a')
//result：3
//ecDo.getEleCount([1,2,3,4,5,66,77,22,55,22],22)
//result：2
function getEleCount(obj, ele) {
  var num = 0;
  for (var i = 0, len = obj.length; i < len; i++) {
    if (ele === obj[i]) {
      num++;
    }
  }
  return num;
}
````

- 对象数组排序

````java
//var arr=[{a:1,b:2,c:9},{a:2,b:3,c:5},{a:5,b:9},{a:4,b:2,c:5},{a:4,b:5,c:7}]
//ecDo.arraySort(arr,'a,b')a是第一排序条件，b是第二排序条件
//result：[{"a":1,"b":2,"c":9},{"a":2,"b":3,"c":5},{"a":4,"b":2,"c":5},{"a":4,"b":5,"c":7},{"a":5,"b":9}]
function arraySort(arr, sortText) {
  if (!sortText) {
    return arr;
  }
  var _sortText = sortText.split(',').reverse(),
    _arr = arr.slice(0);
  for (var i = 0, len = _sortText.length; i < len; i++) {
    _arr.sort(function(n1, n2) {
      return n1[_sortText[i]] - n2[_sortText[i]];
    });
  }
  return _arr;
}
````

- 数组逆序

````java
// arrayReverse([3,2,1,4])  // [4, 1, 2, 3]
function arrayReverse(arr) {
  var len = arr ? arr.length : 0;
  if (len) return arr.reverse();
}
````
