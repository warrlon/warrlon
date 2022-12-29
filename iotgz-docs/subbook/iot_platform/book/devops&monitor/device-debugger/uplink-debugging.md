# 上行数据调试

上行数据调试，可通过控制台模拟设备进行上报属性、上报事件的操作，过程中可查看相关模拟过程的日志内容。

用户需要选择上行调试的目标产品与目标设备，平台展示该设备的在线状态（在线/离线/设备未激活）

### 操作步骤

1. 登录物联网平台控制台。

2. 在左侧导航栏，选择监控运维 > 在线调试。

3. 点击「上行数据调试」Tab，切换到上行数据调试页面。

4. 选择要调试的产品和设备，单击启动设备。

5. 推送调试指令。

![上行数据](/book/devops&monitor/images/uplink-debugging.png)

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
          属性上报
        </div>
        <div style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          <ul>
            <li style="list-style: lower-roman;">点击「属性上报」Tab，页面自动加载该设备对应产品的最新物模型属性功能点</li>
            <li style="list-style: lower-roman;">在Tab页中按照要求填写功能点的参数值后点击「发送」</li>
            <li style="list-style: lower-roman;">在调试日志区域可以查看到相应的调试日志信息。</li>
          </ul>
        </div>
        <div style="width: 30%; padding: 10px 20px;">仅支持MQTT协议和CoAP协议的设备模拟，其它协议的设备不支持模拟。</div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          事件上报
        </div>
        <div style="width: 50%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          <ul>
            <li style="list-style: lower-roman;">点击「事件上报」Tab，页面自动加载该设备对应产品的最新物模型事件功能点</li>
            <li style="list-style: lower-roman;">在Tab页中按照要求填写功能点的参数值后点击「发送」</li>
            <li style="list-style: lower-roman;">在调试日志区域可以查看到相应的调试日志信息。</li>
          </ul>
        </div>
        <div style="width: 30%; padding: 10px 20px;">仅支持MQTT协议和CoAP协议的设备模拟，其它协议的设备不支持模拟。</div>
      </div>

