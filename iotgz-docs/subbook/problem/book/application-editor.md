# 应用编辑器

#### 1.能否将多个设备的数据流放在同一应用中？

独立应用可以，一个独立应用中可以有多个应用元件，不同元件可以对应不同的设备数据流。

#### 2.独立应用和模板应用的区别，如何使用模板应用？

独立应用中包含的数据信息可以同时取自多个设备。应用是唯一的，无法复用在其他设备上；模板应用（已下线）中包含的数据信息仅能来自单一设备，每个设备都能够套用该模板，通过设备来启用模板应用时，模板应用里显示的数据均来自该设备，而要套用该模板的设备必须拥有模板中所要求的所有数据流。

#### 3.应用管理的应用的审核状态为什么是草稿？

可能是你没有点击发布提交审核，或者你的应用是私有应用。应用分为公开、公开-不推广、私有三种。   
应用阅览权限：设置应用是否公开发布至互联网。选择公开，发布后能够在网站“物联工厂”中查看到发布的应用，也可生成链接分享；选择公开-不推广，发布后仅生成链接供外部查看，不会推广至“物联工厂”；选择私有，只有在登录平台账号状态下才可查看，链接不能对外分享。    
应用审核：公开和公开-不推广应用在保存后，为草稿状态，需要在编辑页面右上方点击“发布”按钮提交审核，此时状态为待审核。审核通过后即可对外分享链接。私有应用不需要审核，所有没有发布按钮，应用状态一直为草稿。

#### 4.在应用编辑器里如何能够根据数据流改变显示的图片？

将图片进行上传后，在图片下方填入相应数据流的值，当有对应数据值进行上传，就会切换到对应的图片。

#### 5.在应用里，一个地图可以显示多个设备位置么？

不可以，不支持多个坐标显示，地图控件只能选择一个数据流，也就是一个点坐标。

#### 6.OneNET可以在应用管理里面滑动查看历史的数据曲线吗？

不可以，数据曲线目前只能展示最新的数据点的值。

#### 7.有人用过应用里的轨迹控件么？怎么在应用中显示GPS轨迹？

只支持显示经纬度数据流，不支持基站定位。

#### 8.应用编辑器里的button控件是怎么去控制单片机的引脚的？

通过命令下发的方式。每一个button都需要绑定一条数据流，当你在操作界面点击button的时候，控制信息会通过网络模组下发到单片机的串口，然后你需要用单片机进行串口数据解析，再根据解析出来的控制信息，做出相应的引脚控制。

#### 9.OneNET应用编辑器的应用发布了是不是别人的手机也可以用？

只能查看，要登录创建者的账号才能操作。

#### 10.应用编辑器提示设备ID为空？

你没对接到数据流。
