# SDK说明
本页目录

<a href="#20">1. SDK特性及函数说明</a> 
 
<a href="#21">2. SDK下载</a> 
 
<a href="#22">3. 资源配置表</a>  
 
<a href="#23">4. 本地默认配置</a>
 
<a href="#24">5. 开发说明</a>

---
行业开发平台应用SDK，用户通过添加配置具体产品的资源及实现即可实现产品开发，[下载《OneNET行业开发平台设备SDK用户手册》](/doc/OneNET行业开发平台设备SDK用户手册V1.4.pdf)以了解SDK详细说明。


<h3 id="20"><font color=#CD6839> 1. SDK特性及函数说明 </font></h3>

平台提供的SDK支持OpenCPU和外接MCU两种产品模式。具有以下特性：

&#10146; <font color="#7D9EC0">**可配置性：**</font>资源及操作在平台可灵活配置并自动生成。应用SDK严格采用代码和数据分离的设计思路，应用SDK只实现设备资源的抽象逻辑，一切与具体产品相关的用户数据均放置在资源配置表中，由用户根据产品需求自行配置。资源配置表核心功能是配置产品资源以及资源句柄。

&#10146; <font color="#7D9EC0">**可适配性：**</font>兼容多款模组或者芯片。提供 OneNet 接入的统一API，统一封装各模组/芯片的南向对接协议，以适配不同的硬件平台。对于不同的模组及南向协议，对用户都是透明的。

&#10146; <font color="#7D9EC0">**可嵌入性：**</font>提供Hook函数以植入用户逻辑。针对用户需要植入产品特色逻辑的需求，如硬件自检，硬件初始化等，在系统运行过程的不同环节，提供若干 Hook 函数指针。用户可根据自己的需求将具体逻辑实现注册到应用 SDK 的 Hook 函数指针中。

![1](/images/流程图.png)

如上图所示，用户只需要实现 Hook 函数，资源回调函数以及用户私有事件句柄即可实现产品的开发。

除了基本的资源处理外，SDK为方便用户的产品开发，采用 HooK 点的方式允许用户在主体逻辑中加入自己的处理逻辑；提供了私有事件配置表，允许用户根据产品需求主动触发产品私有事件逻辑，整个过程参数透明传输，类似用户进行了 RPC 调用。

&#10147; <font color="#CD8C95">**Hook 函数：**</font>应用 SDK 共提供了 5 个 Hook 点，分别在 OneNet 上线前，OneNet 上线后，休眠前，唤醒后以及系统级错误调用。
 
&#10147; <font color="#CD8C95">**资源句柄：**</font>平台会根据用户的资源选择，自动渲染资源句柄空函数，用户进行填充。

&#10147; <font color="#CD8C95">**用户私有事件函数：**</font>平台会生成私有事件配置表，用户可根据产品需求添加用户事件 ID（范围 301~400）及实现函数，然后选择事件触发点进行参数传递和触发，实现基于线程的 RPC 调用。

<h3 id="21"><font color=#CD6839> 2. SDK下载 </font></h3>

在**产品开发**页面中完成功能定义后,点击页面底部**下一步**，进入**设备开发**环节。

首先需要下载编译环境和设备SDK，每次功能点变更时都需要重新下载设备SDK，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备测试.png">
    <br>
    图 1 SDK下载
    <br>
</center>

**&#9758; SOC-SDK**是根据用户所定义的功能点以及产品信息平台自动生成特有SDK文件。

**&#9758; SDK-BASE**文件是基于M5311模组的OPENCPU SDK开发环境。

用户需将SOC-SDK中cmiot_user.c和cmiot_user.h复制到SDK-BASE文件夹中的user文件夹下替换即可。如图2和图3所示。

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/SOC_SDK.png">
    <br>
    图 2 SOC-SDK中cmiot_user.c和cmiot_user.h文件
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/SDK_BASE.png">
    <br>
    图 3 SDK-BASE文件夹
    <br>
</center>

文件复制完成后，用户可在**cmiot_user.c**里进行设备逻辑功能开发。

<h3 id="22"><font color=#CD6839> 3. 资源配置表 </font></h3>

资源配置表需要平台根据资源功能，组合功能以及固定功能生成单独生成。具体规则如下：

#### &#128456; 资源功能配置表：

平台配置生成资源名，FuncID以及数据类型，如下数组

```json
 static device_func_handle_t dev_func_list[] =
    {
 	FUNC_HANDLE_BOTH(switch1, 1, BOOL) 
    };
```

#### &#128458; 组合功能配置表：

平台配置生成资源名，FuncID以及数据类型，并根据FuncID（十进制）生成数组名字，并生成注释，如下：

```json

#define GROUP_FUNC_NAME(x)    (group_func_##x)
/*心跳组合功能点*/
static device_func_handle_t  GROUP_FUNC_NAME(1280)[] = {
    FUNC_HANDLE_UP(switch1, 1, BOOL) 
};
```

> 注意：如果资源功能配置表有相同的资源句柄，则不再重复生成相同句柄

#### &#128438; 固定功能配置表：

平台配置生成资源名，FuncID以及数据类型，如下数组。任何消息上报，都会在结尾附带该数据资源值。

```json

static device_func_handle_t  dev_tail_list[] = {
    FUNC_HANDLE_UP(timeStamp, 1792, BOOL) 
};
```

> 注意：固定功能配置隐藏协议版本号，不由用户配置，程序隐藏自带，以便平台根据不同协议版本进行解析。

#### &#128456; 用户私有事件配置表：

平台生成资源配置表，由用户根据产品需求在本地添加。

```json

/*本地状态机用户私有事件处理函数，注：只有在登录onenet后可用*/
static usr_event_handle_t usr_event_handle[] = 
{
    USR_EVENT_HANDLE(CMIOT_EVENT_USER_NOTIFY_RESULT, notify_result)
};
```
<h3 id="23"><font color=#CD6839> 4. 本地默认配置 </font></h3>

cmiot_user.h文件中包含了一些本地默认配置参数，如有需要，用户可以自行配置。

```json

/* 调试串口默认为uart0 */
#define CMIOT_HAL_UART_DBG     HAL_UART_0

/* 注册和物重试次数限制 */
#define HEWU_REGIST_CNT_MAX     5

/*注册和物一次超时时间(ms) */
#define HEWU_REGIST_TIMEOUT_MS  5000

/* 和物服务器IP地址 */
#define HEWU_COAP_SERVER_HOST    "183.230.40.10"
#define HEWU_COAP_SERVER_PORT    26009

/* 驻网失败重试次数限制 */
#define CMIOT_CELL_REG_RETRY_MAX      3

/* 上线OneNet失败重试次数限制 */
#define CMIOT_ONENET_ONLINE_RETRY_MAX    3

/* 连接OneNET平台的保活时间(单位s) */
#define CMIOT_ONENET_OPEN_LIFETIME       (60 * 60 * 25)

/* UPDATE的保活时间(单位s) */
#define CMIOT_ONENET_UPDATE_LIFETIME     (200)

/* UPDATE的发送间隔时间(单位ms) */
#define CMIOT_ONENET_UPDATE_PERIOD       (60*1000)

/* 上报最大重传次数 */
#define REPORT_MAX_RETRANS               3
```
<h3 id="24"><font color=#CD6839> 5. 开发说明 </font></h3>

#### （1） Hook开发

OneNET行业中心设备SDK共包含5个Hook函数（cmiot_user.c），供用户实现相关业务逻辑。

<table>
<tr><th width="25%">函数</th><th width="20%">函数名称</th><th>使用说明</th></tr>
<tr><td>func_hook_online_ahead</td><td>OneNET上线前</td><td>该Hook函数在系统初始化后、OneNET上线流程前调用，用户可在该函数中进行外围设备以及其他业务相关资源的初始化等工作</td></tr>
<tr><td>func_hook_online_after</td><td>OneNET上线后</td><td>该Hook函数在OneNET上线成功后调用，用户可在该函数中实现功能点上报等业务</td></tr>
<tr><td>func_hook_sleep_ahead</td><td>系统休眠前</td><td>该Hook函数在系统进入深度休眠（PSM模式）前调用，用户可在该函数中完成休眠前的清场等工作</td></tr>
<tr><td>func_hook_wakeup_extin</td><td>系统被外部引脚唤醒后</td><td>系统在深度休眠（PSM模式）中若被外部引脚唤醒，将调用该Hook函数。该函数为中断回调函数，不能在其中执行耗时操作</td></tr>
<tr><td>func_hook_sys_err</td><td>发生系统级错误</td><td>系统在驻网重试次数、上线重试次数达到cmiot_def.h中定义的最大重试次数时（即CMIOT_CELL_REG_RETRY_MAX和CMIOT_ONENET_ONLINE_RETRY_MAX，该值可由用户配置），以及FOTA发生异常时，将调用该Hook函数。<br>用户可根据不同错误类型（即SYS_ERR_CREG_ERR、SYS_ERR_ONLINE_ERR、SYS_ERR_FOTA_ERR）进行相应处理</td></tr>
</table>

#### （2） 资源句柄开发

平台会根据用户的资源配置，自动渲染出资源句柄的空函数，由用户进行填充。资源句柄可分为两类，**读资源句柄和写资源句柄**。

#### &#128366; 读资源句柄

读资源句柄的原型如下，val为读取缓存的起始地址，buf_len为读取的数据长度。

```json
int (*device_func_get)(uint8_t *val, uint16_t buf_len);
```

对于**字符型和透传型功能点**，渲染出的读资源句柄空函数如下：

```json
int func_strtype_and_buftype_get(uint8_t *val, uint16_t buf_len)
{
    char *value = (char *)val;
    /* 将获取的字符串或透传型数据写入value指向的地址，并返回字符串或透传型数据长度，长度不能超过buf_len，否则返回0 */
    return len;
}
```

对于**其他数据类型的功能点**，渲染出的读资源句柄空函数如下：

```json
int func_othertype_get(uint8_t *val, uint16_t buf_len)
{
    type value;
    /* 请填入功能点值的获取逻辑，并将值赋给变量value */
	
    return set_by_binary(&value, val, buf_len, sizeof(type));
}
```

#### &#128398; 写资源句柄

写资源句柄的原型如下，val为写入数据的起始地址，val_len为写入的数据长度。

```json
returnCode_e (*device_func_set)(uint8_t *val, uint16_t val_len);
```

对于**字符型功能点**，渲染出的写资源句柄空函数如下：

```json
returnCode_e func_strtype_set(uint8_t *val, uint16_t val_len)
{
    val[val_len] = '\0';
    /** 根据变量val的值，填入下发控制逻辑 */

    /** 成功返回RETURN_CODE_OK，失败返回RETURN_CODE_FAILED */
    return RETURN_CODE_OK;
}
```

对于**透传型功能点**，渲染出的写资源句柄空函数如下：

```json
returnCode_e func_buftype_set(uint8_t *val, uint16_t val_len)
{
    /* 根据变量val与val_len的值，填入下发控制逻辑 */

    /* 成功返回RETURN_CODE_OK，失败返回RETURN_CODE_FAILED */
    return RETURN_CODE_OK;
}
```

对于**其他功能点**，渲染出的写资源句柄空函数如下：

```json
returnCode_e func_othertype_set(uint8_t *val, uint16_t val_len)
{
    type value = *(type *)(val);
    /* 根据变量val与val_len的值，填入下发控制逻辑 */

    /* 成功返回RETURN_CODE_OK，失败返回RETURN_CODE_FAILED */
    return RETURN_CODE_OK;
}
```
#### （3） 用户RPC开发

用户可根据产品需求，在私有事件配置表中添加用户事件ID（范围301~400）及相应实现函数，然后选择事件触发点进行参数传递和触发，实现基于线程的RPC调用。

平台生成的私有事件配置表如下：

```json
/* 用户私有事件配置表，注：只有在登录onenet后可用 */
static usr_event_handle_t usr_event_handle[] = {
    USR_EVENT_HANDLE(CMIOT_EVENT_USER_NOTIFY_RESULT, notify_result),
    USR_EVENT_HANDLE(302, example)
};
```

其中，CMIOT_EVENT_USER_NOTIFY_RESULT为固定事件（事件ID为301），用来通知用户功能点上报的结果。该事件的处理函数如下，用户可在该函数中填入功能点上报成功或失败后的处理逻辑。

```json

returnCode_e func_notify_result_exec(void *val, uint16_t buf_len)
{
    notifyPara_t notifyRes = *(notifyPara_t *)val;
    LOG_PRINT(MODULE_TYPE_USER, LOG_LEVEL_INFO, "func %d notify %s, respId: %d\r\n", notifyRes.funcId, notifyRes.result ? "succ" : "failed", notifyRes.respId);
/* 请填入上报结果事件的具体处理逻辑 */

    return RETURN_CODE_OK;
}
```

302为RPC调用示例，用户可调用以下接口发送用户事件。其中，cmiot_user_event_send_from_isr可以在中断服务程序中调用。

```json

/**
 *  \brief 发送用户事件
 *  
 *  \param [in] eventType 用户事件ID
 *  \param [in] data      要发送的数据
 *  \param [in] len       要发送的数据长度
 *  \param [in] waitTime  队列满时的等待时长（单位ms）
 *  \return RETURN_CODE_OK：成功 其他：失败
 */
returnCode_e cmiot_user_event_send(cmiotEventType_e eventType, void *data, uint32_t len, uint32_t waitTime);

/**
 *  \brief 在中断中发送用户事件
 *  
 *  \param [in] eventType 用户事件ID
 *  \param [in] data      要发送的数据
 *  \param [in] len       要发送的数据长度
 *  \return RETURN_CODE_OK：成功 其他：失败
 */
returnCode_e cmiot_user_event_send_from_isr(cmiotEventType_e eventType, void *data, uint32_t len);
```

队列接收到302事件时，将调用func_example_exec，该函数需由用户实现，完成该事件的RPC调用。

```json
returnCode_e func_example_exec(void *val, uint16_t buf_len)
{
    /* 请填入用户事件的具体处理逻辑 */
	
    return RETURN_CODE_OK;
}
```
#### （4） 主动上报

用户可调用以下接口发起notify，将功能点上报到OneNET平台。该接口需传入两个参数，**功能点ID（普通功能点或组合功能点）和响应ID**。

>  注意：OneNET平台要求，在247秒内，每次调用该接口传入的响应ID应不重复，否则OneNET将视为重复消息丢弃。

功能点上报结果将通过CMIOT_EVENT_USER_NOTIFY_RESULT事件通知用户，用户可在该事件RPC函数中进行后续逻辑处理。

```json
/**
 *  \brief 上报功能点
 *  
 *  \param [in] funcId 功能点ID
 *  \param [in] respId 响应ID
 *  \return RETURN_CODE_OK：成功 其他：失败
 */
returnCode_e cmiot_onenet_notify(uint16_t funcId, uint16_t respId);

/**
 *  \brief 在中断服务程序中上报功能点
 *  
 *  \param [in] funcId 功能点ID
 *  \param [in] respId 响应ID
 *  \return RETURN_CODE_OK：成功 其他：失败
 */
returnCode_e cmiot_onenet_notify_fromisr(uint16_t funcId, uint16_t respId);
```
<div>
    <a href="/book/equipment_manufacturer/device_connect_platform.md">
        <span> &#171; 上一篇：设备生产商_设备接入平台</span>
    </a>
</div>
<div>
    <a href="/book/equipment_manufacturer/device_manage.md">
        <span> &#187; 下一篇：设备生产商_设备管理</span>
    </a>
</div>