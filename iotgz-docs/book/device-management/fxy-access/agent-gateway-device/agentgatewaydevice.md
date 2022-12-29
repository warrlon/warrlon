# **代理网关设备**  

#### **1. 泛协议实例创建**  

在物联平台菜单中找到【接入管理-泛协议接入】菜单，点击进入实例列表页，在列表页可查看到用户的服务ID、实例数量、在线实例数量及实例列表信息，如下图所示：

![inst-list](/images/device-management/fxy-gateway-device/inst-list.png)

实例列表中包含每条实例数据的实例名称、实例描述、在线状态、当前接入设备数、创建时间及一些操作按钮。选择一条实例数据，点击操作中的【查看KEY】，可以看到实例对应的KEY，该KEY可用于SDK的服务实例鉴权配置。点击【更新KEY】，按照页面提示输入短信验证码后，可以对实例KEY进行更新。点击【添加服务实例】按钮，在弹出页面填写实例名称和实例描述，再点击确定，提交后即可创建一个实例，如下图所示：

![inst-add](/images/device-management/fxy-gateway-device/inst-add.png)

#### **2. 代理网关产品创建**  

在物联平台菜单中找到【设备管理-产品管理】菜单，点击【添加产品】按钮，在弹出页面填写产品名称，选择产品类别，节点类型选择**网关设备**，接入协议选择**其他**,再点击确定，提交后即可创建一个代理网关产品，如下图所示：

![product-add](/images/device-management/fxy-gateway-device/product-add.png)

#### **3. 代理网关设备创建**  

在物联平台菜单中找到【设备管理-设备管理】菜单，点击【添加设备】按钮，在弹出页面填写设备名称，选择刚才创建的代理网关产品，再点击确定，提交后即可一个代理网关设备，如下图所示：

![dev-add](/images/device-management/fxy-gateway-device/dev-add.png)

#### **4. 代理子设备产品创建**  

在物联平台菜单中找到【设备管理-产品管理】菜单，点击【添加产品】按钮，在弹出页面填写产品名称，选择产品类别，节点类型选择**子设备**，接入协议选择**其他** （根据实际情况选择子设备协议类型）,再点击确定，提交后即可创建一个代理子设备产品，如下图所示：

![sub-product-add](/images/device-management/fxy-gateway-device/sub-product-add.png)

#### **5. 代理子设备创建**  

在物联平台菜单中找到【设备管理-设备管理】菜单，点击【添加设备】按钮，在弹出页面填写设备名称，选择刚才创建的代理子设备产品，再点击确定，提交后即可一个代理子设备，如下图所示：

![sub-dev-add](/images/device-management/fxy-gateway-device/sub-dev-add.png)

