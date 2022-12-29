# 常用过滤器代码

OneNET View  提供了过滤器来对数据源进行个性化处理，用户可以自行写入`JavaScript`代码，实现数据`结构转换`、`筛选`和一些`简单的计算`。本文将列举一些常用的过滤器代码供参考。如您在实际使用过程中遇到困难，请在可视化产品交流群中向我们提问。

## 迭代处理

通常数据源返回的结果大多是数组类型，通过迭代可以对每个元素进行处理。

```javascript
data.forEach((item, index) => {
  // console.log('元素：', item, '；下标：', index);
});
```

## 获取数组第一项

```javascript
// first([1, 2]); // -> 1
function first(arr) {
  var len = arr ? arr.length : 0;
  if (len) return arr[0];
}
```

## 获取数组最后一项

```javascript
// last([1, 2]); // -> 2
function last(arr) {
  var len = arr ? arr.length : 0;
  if (len) return arr[len - 1];
}
```

## 数组最大值，最小值

```javascript
//数组最大值
function maxArr(arr) {
  return Math.max.apply(null, arr);
}
//数组最小值
function minArr(arr) {
  return Math.min.apply(null, arr);
}
```

## 数组求和，平均值

```javascript
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
```

## 从数组中随机获取元素

```javascript
function randomOne(arr) {
  return arr[Math.floor(Math.random() * arr.length)];
}
```

## 随机返回一个范围的数字

```javascript
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
```

## 时间格式处理

```javascript
/**
 * @param timestamp 时间戳
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
```

## 返回数组（字符串）一个元素出现的次数

```javascript
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
```

## 对象数组排序

```javascript
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
```

## 数组逆序

```javascript
// arrayReverse([3,2,1,4])  // [4, 1, 2, 3]
function arrayReverse(arr) {
  var len = arr ? arr.length : 0;
  if (len) return arr.reverse();
}
```
