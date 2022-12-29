# 编辑组件

项目新建后，在项目列表中点击编辑相应项目，直接跳转至可视化界面， 用户结合实际需要，拖拽顶部列表的组件添加至可视化编辑页面。针对模板及用户行业特性，可自定义修改组件样式。

<div align=center><img src ="/images\qinghua\device-management\subassembly-edit.png"/></div>

在3D编辑器界面上方，选择模型大类—小分类—模型，点击模型的图标，将模型拖动到场景中需要放置的位置。请按操作提示进行操作。

<div align=center><img src ="/images\qinghua\device-management\component-styles.png"/></div>

<div align=center><img src ="/images\qinghua\device-management\component-style-s.png"/></div>

选中场景中的模型，点击该模型，可对模型进行旋转、水平平移、垂直平移、删除模型操作。

<div align=center><img src ="/images\qinghua\device-management\model-edit.png"/></div>

**模型操作图标说明表:**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">序号</td><td>图标</td><td>图标名称/th><td width="40%">操作说明</td></tr>
<tr><td>1</td><td><img src="/images\qinghua\device-management\icon-revolve.png"></td></td><td>旋转</td><td>点击该按钮，可进行模型旋转操作。</td></tr>
<tr><td>2</td><td><img src="/images\qinghua\device-management\icon-level-translate.png"></td><td>水平平移</td><td>点击该按钮，可将模型在水平方向上平移。</td></tr>
<tr><td>3</td><td><img src="/images\qinghua\device-management\icon-vertical-translate.png"></td><td>垂直平移</td><td>点击该按钮，可将模型在垂直方向上平移。</td></tr>
<tr><td>4</td><td><img src="/images\qinghua\device-management\icon-vertical-copy.png"></td><td>垂直复制</td><td>点击该按钮，可将模型垂直复制为多个模型。</td></tr>
<tr><td>5</td><td><img src="/images\qinghua\device-management\icon-level-copy.png"></td><td>水平复制</td><td>点击该按钮，可将模型水平复制为多个模型。</td></tr>
<tr><td>6</td><td><img src="/images\qinghua\device-management\icon-delete.png"></td><td>删除</td><td>点击该按钮，将删除模型。</td></tr>
</table>

在3D编辑器场景中已经放置的模型都在右侧的“场景模型”列表中展示出来，鼠标点击列表中的模型，可完成场景中模型的选中。

<div align=center><img src ="/images\qinghua\device-management\model-select.png"/></div>

支持自定义更改模型的名称；

<div align=center><img src ="/images\qinghua\device-management\scene-model.png"/></div>

点击![](/images\qinghua\device-management\icon-view.png)，可将场景中的模型隐藏；

<div align=center><img src ="/images\qinghua\device-management\hide-model.png"/></div>

点击![](/images\qinghua\device-management\icon-focus.png)聚焦按钮，可将视角切换到所选模型的主视角；

点击![](/images\qinghua\device-management\icon-delete.png)删除按钮，可将场景中的模型删除；

除了基础的模型位置变化及复制操作之外，还可以对模型进行参数、属性、信息牌、数据这些更加详细的高级设置。

**模型设置操作说明表:**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">序号</td><td>名称</td><td width="70%">操作说明</td></tr>
<tr><td>1</td><td>参数</td><td>1、自定模型id；
2、设置模型的尺寸、旋转角度、悬空。
3、勾选“等比缩放”时，任意改变长宽高中的其中一个值，其余两个变量跟随变化的比例而等比变化；
4、点击尺寸和旋转中的“复位”按钮，将模型尺寸、旋转角度恢复到最初加载的样式；
5、“开启阴影”：勾选后，该模型可在场景中展示其本身的阴影；
6、“接收阴影”：勾选后，其他模型的阴影可投在该模型上；

**设置示例如下：**
<img src="/images\qinghua\device-management\parameter-examples.png">
</td></tr>
<tr><td>2</td><td>自定义属性</td><td>点击<img src="/images\qinghua\device-management\icon-plus.png">按钮，可自定义属性。目前支持的特殊属性包括：
（1）video 值为视频流地址；
（2）path  值为动画路径 例如：p1;p2;p3;p4。模型在预览时会从当前位置移动到自定义模型id， p1→p2→p3→p4；
（3）speed  模型移动的速度默认为1。

**设置示例如下：**
<img src="/images\qinghua\device-management\properties-example.png">
</td></tr>
</td></tr>
<tr><td>3</td><td>信息牌设置</td><td>1、样式选择，目前支持“带警告和摄像头”样式；
2、位置偏移，控制信息牌的位置移动，通过坐标X-Y<img src="/images\qinghua\device-management\icon-x-y.png">控制偏移量；
3、编辑时可见，<img src="/images\qinghua\device-management\icon-edit.png">，表示编辑模式也能显示信息牌；
4、信息牌设置/预览，可选择图标，添加标题文字和播放视频。
点摄像头<img src="/images\qinghua\device-management\icon-camera.png">，将播放序号2中定义的video属性的视频流地址。

**设置示例如下：**
<img src="/images\qinghua\device-management\information-example.png">
</td></tr>
</td></tr>
<tr><td>4</td><td>设置UI</td><td>点击该按钮，可进行2D组合组件的调用。</td></tr>
<tr><td>5</td><td>数据配置</td><td>用于进行模型数据源配置。
有该图标的模型，才能进行模型数据源配置。</td></tr>
</table>
