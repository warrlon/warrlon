## 现有的交互模型清单及属性

模型在编辑器中使用时，将默认自带文档中提及的模型自定义属性，便于用户二次开发使用;使用方法见: 【塔吊模型交互】中的DATA配置

<table>
<tr><th width="10%">序号</th><th width="20%">设备名称</th><th width="15%">功能名称</th><th width="15%">功能字段</th><th width="15%">数据类型</th><th>图片</th></tr>
<tr><td rowspan="5">1</td><td rowspan="5">塔吊02</td><td>塔吊高度</td><td>height</td><td>number</td><td rowspan="4"><p align="center"><img src="/images/view/3D/62.png"></p></td></tr>
<tr><td>回转角度</td><td>elevation</td><td>number</td></tr>
<tr><td>幅度</td><td>radius</td><td>number</td></tr>
<tr><td>告警信息</td><td>warn</td><td>string</td></tr>
<tr><td>DATA测试地址</td><td colspan="3">https://open.iot.10086.cn/3d/api/v2/fortest/one</tr>

<tr><td rowspan="2">2</td><td rowspan="2">雾炮01</td><td>开关</td><td>onoff</td><td>int（0或者1）</td><td><p align="center"><img src="/images/view/3D/63.png"></p></td></tr>
<tr><td>DATA测试地址</td><td colspan="3">https://open.iot.10086.cn/3d/api/v2/fortest/two</tr>

<tr><td rowspan="4">3</td><td rowspan="4">门禁</td><td rowspan="4">车数据对象</td><td rowspan="4">car</td><td>carnumber (车牌号)</td><td rowspan="4"><p align="center"><img src="/images/view/3D/64.png"></p></td></tr>
<tr><td>type(车的类型支持1-10)</td></tr>
<tr><td>state(状态是否正常)</td></tr>
<tr><td>info</td></tr>

<tr><td rowspan="2">4</td><td rowspan="2">电风扇</td><td>开关</td><td>onoff</td><td>number(0,1)代表(关,开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/65.png"></p></td></tr>
<tr><td>速度</td><td>speed</td><td>number(0~1)代表(最慢~最快)</td></tr>

<tr><td>5</td><td>门(关)</td><td>状态</td><td>state</td><td>number(0-1-2)代表(正常-开门-关门)</td><td><p align="center"><img src="/images/view/3D/66.png"></p></td></tr>

<tr><td>6</td><td>鱼缸</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td><p align="center"><img src="/images/view/3D/67.png"></p></td></tr>

<tr><td>7</td><td>空调</td><td>状态</td><td>state</td><td>number(0-1-2)代表(正常-开-关)</td><td><p align="center"><img src="/images/view/3D/68.png"></p></td></tr>

<tr><td rowspan="2">8</td><td rowspan="2">LED灯</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/69.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td>9</td><td>门(关)</td><td>状态</td><td>state</td><td>number(0-1-2)代表(正常-开门-关门)</td><td><p align="center"><img src="/images/view/3D/70.png"></p></td></tr>

<tr><td rowspan="2">10</td><td rowspan="2">落地灯01</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/71.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td>11</td><td>药品柜</td><td>状态</td><td>state</td><td>number(0-1-2)代表(正常-开门-关门)</td><td><p align="center"><img src="/images/view/3D/72.png"></p></td></tr>

<tr><td rowspan="2">12</td><td rowspan="2">智能台灯</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/73.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td rowspan="2">13</td><td rowspan="2">台灯01</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/74.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td>14</td><td>垃圾桶</td><td>状态</td><td>state</td><td>number(0-1-2)代表(正常-开门-关门)</td><td><p align="center"><img src="/images/view/3D/75.png"></p></td></tr>

<tr><td rowspan="2">15</td><td rowspan="2">路灯01</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/76.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td rowspan="2">16</td><td rowspan="2">路灯02</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/77.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td rowspan="2">17</td><td rowspan="2">路灯03</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/78.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td rowspan="2">18</td><td rowspan="2">路灯04</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/79.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td rowspan="2">19</td><td rowspan="2">城市智慧路灯01</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/80.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td rowspan="2">20</td><td rowspan="2">城市智慧路灯02</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td rowspan="2"><p align="center"><img src="/images/view/3D/81.png"></p></td></tr>
<tr><td>光线状态</td><td>onoff_ray</td><td>number(0-1)代表(关-开)消耗有点大</td></tr>

<tr><td>21</td><td>洒水器</td><td>状态</td><td>onoff</td><td>number(0-1)代表(关-开)</td><td><p align="center"><img src="/images/view/3D/82.png"></p></td></tr>
</table>