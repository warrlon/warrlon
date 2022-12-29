# 下行数据调试

下行数据调试，可用于虚拟设备接入时的调试，也可用于真实设备接入时的调试，用户可在不启动虚拟设备的情况下，使用下行数据调试。

用户需要选择下行调试的目标产品与目标设备，平台展示该设备的在线状态（在线/离线/设备未激活）


### 操作步骤

1. 登录物联网平台控制台。

2. 在左侧导航栏，选择监控运维 > 在线调试。

3. 点击「下行数据调试」Tab，切换到下行数据调试页面。

4. 选择要调试的产品和设备，单击启动设备。

5. 推送调试指令。

![下行数据](/book/devops&monitor/images/downlink-debugging.png)

<div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf; background: #f2f2f2;"
      >
        <div
          style="width: 20%; padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          调试项目
        </div>
        <div
          style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          操作
        </div>
        <div
          style="width: 30%; padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          备注
        </div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          设置属性
        </div>
        <div style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          <ul>
            <li style="list-style: lower-roman;">点击「设置属性」Tab，在Tab页中按照要求填写功能点的参数值</li>
            <li style="list-style: lower-roman;">点击「发送」，在调试日志区域可以查看到相应的调试日志信息</li>
          </ul>
        </div>
        <div style="width: 30%; padding: 10px 20px;">设置属性功能只能对在线设备进行操作。下行调试支持MQTT、CoAP和其它协议的设备。</div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          设置属性期望值
        </div>
        <div style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          <ul>
            <li style="list-style: lower-roman;">点击「设置属性期望值」Tab，在Tab页中按照要求填写功能点的参数值</li>
            <li style="list-style: lower-roman;">点击「发送」，在调试日志区域可以查看到相应的调试日志信息</li>
          </ul>
        </div>
        <div style="width: 30%; padding: 10px 20px;">设置属性期望值根据设备的在线情况来执行不同的业务逻辑：当设备在线时和「设置属性」功能一致；而当设备不在线时，平台会将属性期望值缓存在平台，由设备上线后主动获取。</div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          获取属性
        </div>
        <div style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          <ul>
            <li style="list-style: lower-roman;">点击「属性获取」Tab，页面自动加载物模型中的属性，可选择多个属性，按照要求填写功能点的参数值</li>
            <li style="list-style: lower-roman;">点击「发送」，在调试日志区域可以查看到相应的调试日志信息</li>
          </ul>
        </div>
        <div style="width: 30%; padding: 10px 20px;">支持同步显示调试日志。</div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          服务调用
        </div>
        <div style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          <ul>
            <li style="list-style: lower-roman;">点击「服务调用」Tab，页面自动加载物模型中的服务，按照要求填写功能点的参数值</li>
            <li style="list-style: lower-roman;">点击「发送」，在调试日志区域可以查看到相应的调试日志信息</li>
          </ul>
        </div>
        <div style="width: 30%; padding: 10px 20px;">支持同步显示调试日志。</div>
      </div>