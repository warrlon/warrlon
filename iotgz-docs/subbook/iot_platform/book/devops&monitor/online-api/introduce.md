# API调试

[1.搜索接口](#1搜索接口)

[2.接口参数](#2接口参数)

[3.调用结果](#3调用结果)

---

平台提供API调试功能，可快速检索和调用API。系统根据输入参数同步生成SDK的Demo代码，在调用结果页签下，可实时查看API请求和响应结果，同时支持历史执行记录查询及API调用地址、参数自动填充功能。

### 1.搜索接口

    (1) 登录物联网平台控制台。
    (2) 在左侧导航栏，单击监控运维 > API调试，进入API调试页签。
    (3) 输入接口搜索条件，接口搜索支持中文名称或英文名称搜索，然后单击搜索图标，在搜索的接口列表中
        选择调用的API接口。

### 2.接口参数

选择调用的API接口后，需要在接口参数页签输入参数然后执行。

<div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf; background: #f2f2f2;"
      >
        <div
          style="width: 20%; padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          操作
        </div>
        <div
          style="width: 80%; padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          说明
        </div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          仅显示必填
        </div>
        <div style="width: 80%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
            对必填参数和所有参数进行切换，默认为所有参数。
        </div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          查看API文档
        </div>
        <div style="width: 80%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          查看当前调用接口的文档。
        </div>
      </div>
      <div
        style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;"
      >
        <div
          style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;"
        >
          执行
        </div>
        <div style="width: 80%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
          对接口进行调用。
        </div>
      </div>

### 3.调用结果

填写参数点击执行后，接口调用返回的结果会显示在调用结果页签下。

调用结果支持查看API调用的真实请求URL和JSON格式的返回结果，用户可以一键复制。

调用结果页签中可以点击查看执行历史，查询当前用户调用所有接口的近100条记录，用户可以点击填用该参数操作，快速切换选中的API调用地址并自动填充参数。