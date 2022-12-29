# 开发流程

**Step1 创建产品，选择TCP透传**

首先您需要在平台完成账号注册，并创建一个**TCP透传**的产品

**Step2 创建设备，记录设备ID等信息**

通过页面点击**添加设备**，输入**设备名称**和**鉴权信息**（即设备编号），并记录下该**设备编号**.

**Step3 上传Lua脚本**

通过页面上传解析脚本到产品下，如下图所示：
![pic](/images/TCP/上传脚本.png)

![pic](/images/TCP/确认上传.png)

脚本示例：
> 脚本实现了如下功能：
> - 设备连接后每5秒下发一次 "hello"
> - 用户上传数据后，平台回复 "received"
> - 将用户上传的数据转换为HEX字符串并作为数据点存储至 *ds_test* 数据流

```lua
-----------------------------------------------------------------------
-- 使用说明：                                                        --
-- V1.3                                                              --
-- 用户需要自行完成一下2个函数的实现                                 --
-- 1、定时下发数据任务初始化函数：device_timer_init(dev)【可选】     --
-- 2、对设备上传数据进行解析（包括心跳等）：device_data_analyze(dev) --
-----------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 注册C函数                                                                 --
-- u2f 将32位整型内存数据转换为浮点数（不同于值转换）                        --
-- 类似C代码 *(float*)(&u)                                                   --
-- function u2f(u)                                                           --
-- @param   u   number   整数值                                              --
-- @return  成功返回浮点数值，否则返回nil                                    --
-- @example local u = 123                                                    --
--          local f = u2f( 123 )                                             --
--                                                                           --
-- time 获取时间戳，距离（00:00:00 UTC, January 1, 1970）的毫秒数            --
-- function time()                                                           --
-- @return  返回当前时间戳                                                   --
-- @example local t = time()                                                 --
--                                                                           --
-- year 获取年（year-1900）                                                  --
-- function year(t)                                                          --
-- @param   t   number   时间戳，距离（00:00:00 UTC, January 1, 1970）的秒数 --
-- @return  返回年                                                           --
-- @example local y = year( t )                                              --
--                                                                           --
-- month 获取月（0-11）                                                      --
-- function month(t)                                                         --
-- @param   t   number   时间戳，距离（00:00:00 UTC, January 1, 1970）的秒数 --
-- @return  返回月                                                           --
-- @example local m = month( t )                                             --
--                                                                           --
-- day 获取日（1-31）                                                        --
-- function day(t)                                                           --
-- @param   t   number   时间戳，距离（00:00:00 UTC, January 1, 1970）的秒数 --
-- @return  返回月                                                           --
-- @example local d = day( t )                                               --
--                                                                           --
-- hour 获取时（0-23）                                                       --
-- function hour(t)                                                          --
-- @param   t   number   时间戳，距离（00:00:00 UTC, January 1, 1970）的秒数 --
-- @return  返回时                                                           --
-- @example local h = hour( t )                                              --
--                                                                           --
-- minute 获取分（0-59）                                                     --
-- function minute(t)                                                        --
-- @param   t   number   时间戳，距离（00:00:00 UTC, January 1, 1970）的秒数 --
-- @return  返回分                                                           --
-- @example local m = minute( t )                                            --
--                                                                           --
-- second 获取秒（0-59）                                                     --
-- function second(t)                                                        --
-- @param   t   number   时间戳，距离（00:00:00 UTC, January 1, 1970）的秒数 --
-- @return  返回秒                                                           --
-- @example local m = second( t )                                            --
-------------------------------------------------------------------------------

--------------------------------------------------------
-- 将bytes string转换hex string                       --
-- @param   s   string   bytes string                 --
-- @return  返回hex string，类似"0A0B0C0D..."         --
-- @example local hex = to_hex("\2\2\0\150\0\37\206") --
--------------------------------------------------------
function to_hex(s)
        local i
        local t

        t={s:byte(1,s:len())}
        for i=1,#t do
                t[i]=string.format('%02X',t[i])
        end

        return table.concat(t)
end

-----------------------------------------------
-- 将object序列化成字符串                    --
-- @param   o   boolean|number|string|table  --
-- @return  返回序列化string                 --
-- @example local str = to_str({x=100})      --
-----------------------------------------------
function to_str(o)
        local i=1
        local t={}
        local f

        f=function(x)
                local y=type(x)
                if y=="number" then
                        t[i]=x
                        i=i+1
                elseif y=="boolean" then
                        t[i]=tostring(x)
                        i=i+1
                elseif y=="string" then
                        t[i]="\""
                        t[i+1]=x
                        t[i+2]="\""
                        i=i+3
                elseif y=="table" then
                        t[i]="{"
                        i=i+1

                        local z=true
                        for k,v in pairs(x) do
                                if z then
                                        z=false
                                        t[i]="\""
                                        t[i+1]=k
                                        t[i+2]="\""
                                        t[i+3]=":"
                                        i=i+4
                                        f(v)
                                else
                                        t[i]=","
                                        t[i+1]="\""
                                        t[i+2]=k
                                        t[i+3]="\""
                                        t[i+4]=":"
                                        i=i+5
                                        f(v)
                                end
                        end

                        t[i]="}"
                        i=i+1
                else
                        t[i]="nil"
                        i=i+1
                end
        end
        f(o)

        return table.concat(t)
end

----------------------------------------------------------------------------------------------------------
-- 添加值数据点到table中                                                                                --
-- @param   t   table                                                                                   --
--          i   string                      数据流或数据流模板名称                                      --
--          a   number                      毫秒级时间戳，距离（00:00:00 UTC, January 1, 1970）的毫秒； --
--                                          如果值为0，表示使用当前时间                                 --
--          v   boolean|number|string|table 布尔值、数值、字符串、json                                  --
--          c   string                      用于标识数据点归属(设备AuthCode,可选)                       --
--                                          如果值为“”或nil，表示数据点归属建立TCP连接的设备            --
-- @return  成功返回true，否则返回false                                                                 --
-- @example local ok = add_val(t,"dsname",0,100)                                                        --
----------------------------------------------------------------------------------------------------------
function add_val(t, i, a, v, c)
        if type(t)~="table" then
                return false
        elseif type(i)~="string" then
                return false
        elseif type(a)~="number" then
                return false
        else
                local o = type(v)
                if o~="boolean" and o~="number" and o~="string" and o~="table" then
                        return false
                end

                local n = {i=i,v=to_hex(v)}
--                n.v = n.v .. "("..o..")"
                if a~=0 and a~=nil then
                        n["a"]=a
                end
                if c~=nil then
                        n["c"]=c
                end

                -- list push_back --
                if t.h==nil then
                        t.h={nil,n}
                        t.t=t.h
                else
                        t.t[1]={nil,n}
                        t.t=t.t[1]
                end
        end

        return true
end

--------------------------------------------------------------
-- 将table序列化成json字符串                                --
-- @param   t   table   通过add_val、add_bin构建起来的table --
-- @return  返回序列化json字符串                            --
-- @example local json = to_json(t)                         --
--------------------------------------------------------------
function to_json(t)
        local i=1
        local o={}
        local n

        o[i]="["
        i=i+1
        n=t.h
        while n~=nil do
                if n[2]~=nil then
                        o[i]=to_str(n[2])
                        i=i+1
                end

                n=n[1]
                if n~=nil then
                        o[i]=","
                        i=i+1
                end
        end
        o[i]="]"

        return table.concat(o)
end

------------------------------------
-- begin-添加用户自定义值或函数等 --

-- end-添加用户自定义值或函数等   --
------------------------------------

------------------------------------------------------------------------------------------
-- 设置定时下发设备的数据（可选）                                                       --
-- @param  dev    user_data   设备管理器                                                --
-- @return 无                                                                           --
-- @notice 此函数为回调函数，不可在脚本内调用                                           --
-- @readme dev提供一下几个函数：                                                        --
--         dev:add(interval,name,data)添加定时下发数据                                  --
--           @param   interval   number   数据下发的时间间隔（秒）                      --
--                    name       string   名称（须保证唯一性）                          --
--                    data       string   数据（二进制数据），使用lua转义字符串         --
--           @return  成功返回true，否则返回false                                       --
--           @notice  定时数据下发的平均频率不超过1，及1/interval_1+...+1/interval_n<=1 --
--           @example local ok = dev:add(10,"test","\1\1\0\150\0\37\253\29")            --
--         dev:timeout(sec)设置下发数据的设备响应超时时间（秒）                         --
--           @param   sec        int      响应超时时间（秒）                            --
--                                        如果值为0，表示不检测设备响应超时             --
--           @return  无                                                                --
--           @example dev:timeout(3)                                                    --
--         dev:response()设备响应成功                                                   --
--           @param   无                                                                --
--           @return  无                                                                --
--           @example dev:response()                                                    --
--         dev:send(data)下发数据到设备                                                 --
--           @param   data   string   数据（二进制数据），使用lua转义字符串             --
--           @return  无                                                                --
--           @example dev:send("\2\2\0\150\0\37\206\89")                                --
------------------------------------------------------------------------------------------
function device_timer_init(dev)
        -- 添加用户自定义代码 --
        -- 例如： --
        dev:timeout(3)
        dev:add(10,"dev1","hello")    --每10秒下发一包数据，内容为hello
end

-----------------------------------------------------------------------------------------------------------
-- 解析设备上传数据                                                                                      --
-- @param  dev    user_data   设备管理器                                                                 --
-- @return size表示已解析设备上传数据的字节数，json表示解析后的数据点集合，格式如下：                    --
--         [                                                                                             --
--           {                                                                                           --
--             "i" : "dsname1",          // 数据流或数据流模板名称1                                      --
--             "a" : 1234567890,         // 毫秒级时间戳，距离（00:00:00 UTC, January 1, 1970）的毫秒    --
--                                       // 如果值为0，表示使用当前时间                                  --
--             "v" : 123 | "123" | {...} // 布尔值、数值、字符串、json                                   --
--             "b" : "0A0B0C0D..."       // 二进制数据（16进制字符串），与v互斥，不同时存在              --
--             "d" : xxx | "xxx" | {...} // 用于描述b（可选）；布尔值、数值、字符串、json                --
--             "c" : "authcode1"         // 用于标识数据点归属(设备AuthCode,可选)                        --
--                                       // 如果为“”或不存在，表示数据点归属建立TCP连接的设备            --
--           }                                                                                           --
--           ...                                                                                         --
--           {                                                                                           --
--             "i" : "dsnamen",          // 数据流或数据流模板名称1                                      --
--             "a" : 1234567890,         // 毫秒级时间戳，距离（00:00:00 UTC, January 1, 1970）的毫秒    --
--                                       // 如果值为0，表示使用当前时间                                  --
--             "v" : 123 | "123" | {...} // 布尔值、数值、字符串、json                                   --
--             "b" : "0A0B0C0D..."       // 二进制数据（16进制字符串），与v互斥，不同时存在              --
--             "d" : xxx | "xxx" | {...} // 用于描述b（可选）；布尔值、数值、字符串、json                --
--             "c" : "authcoden"         // 用于标识数据点归属(设备AuthCode,可选)                        --
--                                       // 如果为“”或不存在，表示数据点归属建立TCP连接的设备            --
--           }                                                                                           --
--         ]                                                                                             --
-- @notice 此函数为回调函数，不可在脚本内调用                                                            --
-- @readme dev提供一下几个函数：                                                                         --
--         dev:add(interval,name,data)添加定时下发数据                                                   --
--           @param   interval number   数据下发的时间间隔（秒）                                         --
--                    name     string   名称（须保证唯一性）                                             --
--                    data     string   数据（二进制数据），使用lua转义字符串                            --
--           @return  成功返回true，否则返回false                                                        --
--           @notice  定时数据下发的平均频率不超过1，及1/interval_1+...+1/interval_n<=1                  --
--           @example local ok = dev:add(10,"test","\1\1\0\150\0\37\253\29")                             --
--         dev:timeout(sec)设置下发数据的设备响应超时时间（秒）                                          --
--           @param   sec      int      响应超时时间（秒）                                               --
--                                      如果值为0，表示不检测设备响应超时                                --
--           @return  无                                                                                 --
--           @example dev:timeout(3)                                                                     --
--         dev:response()设备响应成功                                                                    --
--           @param   无                                                                                 --
--           @return  无                                                                                 --
--           @example dev:response()                                                                     --
--         dev:send(data)下发数据到设备                                                                  --
--           @param   data   string   数据（二进制数据），使用lua转义字符串                              --
--           @return  无                                                                                 --
--           @example dev:send("\2\2\0\150\0\37\206\89")                                                 --
--         dev:size()获取设备数据大小（字节数）                                                          --
--           @param   无                                                                                 --
--           @return  返回设备数据大小（字节数）                                                         --
--           @example local sz = dev:size()                                                              --
--         dev:byte(pos)获取pos对应位置的设备数据（字节）                                                --
--           @param   pos   number   指定的获取位置，取值范围[1,dev:size()+1)                            --
--           @return  成功返回设备数据（int），否则返回nil                                               --
--           @example local data = dev:byte(1)                                                           --
--         dev:bytes(pos,count)获取从pos开始，count个设备数据                                            --
--           @param   pos   number   指定的获取起始位置，取值范围[1,dev:size()+1)                        --
--                    count number   指定的获取数据总数，取值范围[0,dev:size()+1-pos]                    --
--           @return  成功返回设备数据（string），否则返回nil                                            --
--           @example local datas = dev:bytes(1,dev:size())                                              --
-----------------------------------------------------------------------------------------------------------
function device_data_analyze(dev)
        local t = {}
        local a = 0

        -- 添加用户自定义代码 --
        -- 例如： --
        local s = dev:size()    --获取上行数据长度
        add_val(t,"ds_test",0,dev:bytes(1,s))

        dev:response()
        dev:send("received")  --发送应答

        -- return $1,$2 --
        -- 例如： --
        return s,to_json(t)    --保存该数据
end
```

其中：
device_data_analyze(dev)  为终端上行数据解析函数，每一包数据都会经过其处理；
device_timer_init(dev)  为定时器初始化函数，用于指定周期性的数据下发操作；

**Step4 建立连接**

设备上电，与OneNET接入服务（域名为：**dtu.heclouds.com**）建立TCP连接，发送登录报文，格式如下：

    *$PID#$AUTH_INFO#$PARSER_NAME*

示例：
    
    *12346#sn823mdn#testlua*

其中，参数解释如下：
- PID：产品ID，创建产品时OneNET生成的产品唯一性数字标识
- AUTH_INFO：设备鉴权信息，在设备注册时，用户创建设备时指定的唯一字符串标识
- PARSER_NAME：用户自定义解析脚本的名称，用户上传脚本时指定的唯一字符串标识

若建立连接成功，可以看到设备在线标记：

![pic](/images/MQTT/在线.png)

**Step5数据流展示，查看数据点**

在OneNET上的设备管理下点击数据展示，进入数据展示页面，点击下拉菜单，查看近期上传的数据点；也可以选择时间区间来查看历史时间