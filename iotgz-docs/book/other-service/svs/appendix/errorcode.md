# 错误码列表

10000~19999的错误码参见如下：

<table>
<tr><th width="40%">错误码</th><th width="30%">错误值</th><th>说明</th></tr>
<tr><td>MSP_SUCCESS</td><td>0</td><td>函数执行成功</td></tr>
<tr><td>MSP_ERROR_FAIL</td><td>-1</td><td>失败</td></tr>
<tr><td>MSP_ERROR_EXCEPTION</td><td>-2</td><td>异常</td></tr>
<tr><td>MSP_ERROR_GENERAL</td><td>10100</td><td>基码</td></tr>
<tr><td>MSP_ERROR_OUT_OF_MEMORY</td><td>10101</td><td>内存越界</td></tr>
<tr><td>MSP_ERROR_FILE_NOT_FOUND</td><td>10102</td><td>文件没有发现</td></tr>
<tr><td>MSP_ERROR_NOT_SUPPORT</td><td>10103</td><td>不支持</td></tr>
<tr><td>MSP_ERROR_NOT_IMPLEMENT</td><td>10104</td><td>没有实现</td></tr>
<tr><td>MSP_ERROR_ACCESS</td><td>10105</td><td>没有权限</td></tr>
<tr><td>MSP_ERROR_INVALID_PARA</td><td>10106</td><td>无效的参数</td></tr>
<tr><td>MSP_ERROR_INVALID_PARA_VALUE</td><td>10107</td><td>无效的参数值</td></tr>
<tr><td>MSP_ERROR_INVALID_HANDLE</td><td>10108</td><td>无效的句柄</td></tr>
<tr><td>MSP_ERROR_INVALID_DATA</td><td>10109</td><td>无效的数据</td></tr>
<tr><td>MSP_ERROR_NO_LICENSE</td><td>10110</td><td>没有授权许可</td></tr>
<tr><td>MSP_ERROR_NOT_INIT</td><td>10111</td><td>没有初始化</td></tr>
<tr><td>MSP_ERROR_NULL_HANDLE</td><td>10112</td><td>空句柄</td></tr>
<tr><td>MSP_ERROR_OVERFLOW</td><td>10113</td><td>溢出</td></tr>
<tr><td>MSP_ERROR_TIME_OUT</td><td>10114</td><td>超时</td></tr>
<tr><td>MSP_ERROR_OPEN_FILE</td><td>10115</td><td>打开文件出错</td></tr>
<tr><td>MSP_ERROR_NOT_FOUND</td><td>10116</td><td>没有发现</td></tr>
<tr><td>MSP_ERROR_NO_ENOUGH_BUFFER</td><td>10117</td><td>没有足够的内存</td></tr>
<tr><td>MSP_ERROR_NO_DATA</td><td>10118</td><td>没有数据</td></tr>
<tr><td>MSP_ERROR_NO_MORE_DATA</td><td>10119</td><td>没有更多的数据</td></tr>
<tr><td>MSP_ERROR_SKIPPED</td><td>10120</td><td>跳过</td></tr>
<tr><td>MSP_ERROR_ALREADY_EXIST</td><td>10121</td><td>已经存在</td></tr>
<tr><td>MSP_ERROR_LOAD_MODULE</td><td>10122</td><td>加载模块失败</td></tr>
<tr><td>MSP_ERROR_BUSY</td><td>10123</td><td>忙碌</td></tr>
<tr><td>MSP_ERROR_INVALID_CONFIG</td><td>10124</td><td>无效的配置项</td></tr>
<tr><td>MSP_ERROR_VERSION_CHECK</td><td>10125</td><td>版本错误</td></tr>
<tr><td>MSP_ERROR_CANCELED</td><td>10126</td><td>取消</td></tr>
<tr><td>MSP_ERROR_INVALID_MEDIA_TYPE</td><td>10127</td><td>无效的媒体类型</td></tr>
<tr><td>MSP_ERROR_CONFIG_INITIALIZE</td><td>10128</td><td>初始化Config实例</td></tr>
<tr><td>MSP_ERROR_CREATE_HANDLE</td><td>10129</td><td>建立句柄</td></tr>
<tr><td>MSP_ERROR_CODING_LIB_NOT_LOAD</td><td>10130</td><td>编解码库未加载</td></tr>
<tr><td>MSP_ERROR_NET_GENERAL</td><td>10200</td><td>网络一般错误</td></tr>
<tr><td>MSP_ERROR_NET_OPENSOCK</td><td>10201</td><td>打开套接字</td></tr>
<tr><td>MSP_ERROR_NET_CONNECTSOCK</td><td>10202</td><td>套接字连接</td></tr>
<tr><td>MSP_ERROR_NET_ACCEPTSOCK</td><td>10203</td><td>套接字接收</td></tr>
<tr><td>MSP_ERROR_NET_SENDSOCK</td><td>10204</td><td>发送</td></tr>
<tr><td>MSP_ERROR_NET_RECVSOCK</td><td>10205</td><td>接收</td></tr>
<tr><td>MSP_ERROR_NET_INVALIDSOCK</td><td>10206</td><td>无效的套接字</td></tr>
<tr><td>MSP_ERROR_NET_BADADDRESS</td><td>10207</td><td>无效的地址</td></tr>
<tr><td>MSP_ERROR_NET_BINDSEQUENCE</td><td>10208</td><td>绑定次序</td></tr>
<tr><td>MSP_ERROR_NET_NOTOPENSOCK</td><td>10209</td><td>套接字没有打开</td></tr>
<tr><td>MSP_ERROR_NET_NOTBIND</td><td>10210</td><td>没有绑定</td></tr>
<tr><td>MSP_ERROR_NET_NOTLISTEN</td><td>10211</td><td>没有监听</td></tr>
<tr><td>MSP_ERROR_NET_CONNECTCLOSE</td><td>10212</td><td>连接关闭</td></tr>
<tr><td>MSP_ERROR_NET_NOTDGRAMSOCK</td><td>10213</td><td>非数据报套接字</td></tr>
<tr><td>MSP_ERROR_NET_DNS</td><td>10214</td><td>DNS解析错误</td></tr>
<tr><td>MSP_ERROR_MSG_GENERAL</td><td>10300</td><td>消息一般错误</td></tr>
<tr><td>MSP_ERROR_MSG_PARSE_ERROR</td><td>10301</td><td>解析</td></tr>
<tr><td>MSP_ERROR_MSG_BUILD_ERROR</td><td>10302</td><td>构建</td></tr>
<tr><td>MSP_ERROR_MSG_PARAM_ERROR</td><td>10303</td><td>参数出错</td></tr>
<tr><td>MSP_ERROR_MSG_CONTENT_EMPTY</td><td>10304</td><td>Content为空</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_CONTENT_TYPE</td><td>10305</td><td>Content类型无效</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_CONTENT_LENGTH</td><td>10306</td><td>Content长度无效</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_CONTENT_ENCODE</td><td>10307</td><td>Content编码无效</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_KEY</td><td>10308</td><td>Key无效</td></tr>
<tr><td>MSP_ERROR_MSG_KEY_EMPTY</td><td>10309</td><td>Key为空</td></tr>
<tr><td>MSP_ERROR_MSG_SESSION_ID_EMPTY</td><td>10310</td><td>会话ID为空</td></tr>
<tr><td>MSP_ERROR_MSG_LOGIN_ID_EMPTY</td><td>10311</td><td>登录ID为空</td></tr>
<tr><td>MSP_ERROR_MSG_SYNC_ID_EMPTY</td><td>10312</td><td>同步ID为空</td></tr>
<tr><td>MSP_ERROR_MSG_APP_ID_EMPTY</td><td>10313</td><td>应用ID为空</td></tr>
<tr><td>MSP_ERROR_MSG_EXTERN_ID_EMPTY</td><td>10314</td><td>扩展ID为空</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_CMD</td><td>10315</td><td>无效的命令</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_SUBJECT</td><td>10316</td><td>无效的主题</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_VERSION</td><td>10317</td><td>无效的版本
<tr><td>MSP_ERROR_MSG_NO_CMD</td><td>10318</td><td>没有命令</td></tr>
<tr><td>MSP_ERROR_MSG_NO_SUBJECT</td><td>10319</td><td>没有主题</td></tr>
<tr><td>MSP_ERROR_MSG_NO_VERSION</td><td>10320</td><td>没有版本号</td></tr>
<tr><td>MSP_ERROR_MSG_MSSP_EMPTY</td><td>10321</td><td>消息为空</td></tr>
<tr><td>MSP_ERROR_MSG_NEW_RESPONSE</td><td>10322</td><td>新建响应消息失败</td></tr>
<tr><td>MSP_ERROR_MSG_NEW_CONTENT</td><td>10323</td><td>新建Content失败</td></tr>
<tr><td>MSP_ERROR_MSG_INVALID_SESSION_ID</td><td>10324</td><td>无效的会话ID</td></tr>
<tr><td>MSP_ERROR_DB_GENERAL</td><td>10400</td><td>数据库一般错误</td></tr>
<tr><td>MSP_ERROR_DB_EXCEPTION</td><td>10401</td><td>异常</td></tr>
<tr><td>MSP_ERROR_DB_NO_RESULT</td><td>10402</td><td>没有结果</td></tr>
<tr><td>MSP_ERROR_DB_INVALID_USER</td><td>10403</td><td>无效的用户</td></tr>
<tr><td>MSP_ERROR_DB_INVALID_PWD</td><td>10404</td><td>无效的密码</td></tr>
<tr><td>MSP_ERROR_DB_CONNECT</td><td>10405</td><td>连接出错</td></tr>
<tr><td>MSP_ERROR_DB_INVALID_SQL</td><td>10406</td><td>无效的SQL</td></tr>
<tr><td>MSP_ERROR_RES_GENERAL</td><td>10500</td><td>资源一般错误</td></tr>
<tr><td>MSP_ERROR_RES_LOAD</td><td>10501</td><td>没有加载</td></tr>
<tr><td>MSP_ERROR_RES_FREE</td><td>10502</td><td>空闲</td></tr>
<tr><td>MSP_ERROR_RES_MISSING</td><td>10503</td><td>缺失</td></tr>
<tr><td>MSP_ERROR_RES_INVALID_NAME</td><td>10504</td><td>无效的名称</td></tr>
<tr><td>MSP_ERROR_RES_INVALID_ID</td><td>10505</td><td>无效的ID</td></tr>
<tr><td>MSP_ERROR_RES_INVALID_IMG</td><td>10506</td><td>无效的映像</td></tr>
<tr><td>MSP_ERROR_RES_WRITE</td><td>10507</td><td>写操作</td></tr>
<tr><td>MSP_ERROR_RES_LEAK</td><td>10508</td><td>泄露</td></tr>
<tr><td>MSP_ERROR_RES_HEAD</td><td>10509</td><td>资源头部错误</td></tr>
<tr><td>MSP_ERROR_RES_DATA</td><td>10510</td><td>数据出错</td></tr>
<tr><td>MSP_ERROR_RES_SKIP</td><td>10511</td><td>跳过</td></tr>
<tr><td>MSP_ERROR_TTS_GENERAL</td><td>10600</td><td>合成一般错误</td></tr>
<tr><td>MSP_ERROR_TTS_TEXTEND</td><td>10601</td><td>文本结束</td></tr>
<tr><td>MSP_ERROR_TTS_TEXT_EMPTY</td><td>10602</td><td>文本为空</td></tr>
<tr><td>MSP_ERROR_REC_GENERAL</td><td>10700</td><td>一般错误</td></tr>
<tr><td>MSP_ERROR_REC_INACTIVE</td><td>10701</td><td>处于不活跃状态</td></tr>
<tr><td>MSP_ERROR_REC_GRAMMAR_ERROR</td><td>10702</td><td>语法错误</td></tr>
<tr><td>MSP_ERROR_REC_NO_ACTIVE_GRAMMARS</td><td>10703</td><td>没有活跃的语法</td></tr>
<tr><td>MSP_ERROR_REC_DUPLICATE_GRAMMAR</td><td>10704</td><td>语法重复</td></tr>
<tr><td>MSP_ERROR_REC_INVALID_MEDIA_TYPE</td><td>10705</td><td>无效的媒体类型</td></tr>
<tr><td>MSP_ERROR_REC_INVALID_LANGUAGE</td><td>10706</td><td>无效的语言</td></tr>
<tr><td>MSP_ERROR_REC_URI_NOT_FOUND</td><td>10707</td><td>没有对应的URI</td></tr>
<tr><td>MSP_ERROR_REC_URI_TIMEOUT</td><td>10708</td><td>获取URI内容超时</td></tr>
<tr><td>MSP_ERROR_REC_URI_FETCH_ERROR</td><td>10709</td><td>获取URI内容时出错</td></tr>
<tr><td>MSP_ERROR_EP_GENERAL</td><td>10800</td><td>（EP）一般错误</td></tr>
<tr><td>MSP_ERROR_EP_NO_SESSION_NAME</td><td>10801</td><td>（EP）链接没有名字</td></tr>
<tr><td>MSP_ERROR_EP_INACTIVE</td><td>10802</td><td>（EP）不活跃</td></tr>
<tr><td>MSP_ERROR_EP_INITIALIZED</td><td>10803</td><td>（EP）初始化出错</td></tr>
<tr><td>MSP_ERROR_LOGIN_SUCCESS	11000</td><td>登录成功</td></tr>
<tr><td>MSP_ERROR_LOGIN_NO_LICENSE</td><td>11001</td><td>无授权</td></tr>
<tr><td>MSP_ERROR_LOGIN_SESSIONID_INVALID</td><td>11002</td><td>无效的SessionID</td></tr>
<tr><td>MSP_ERROR_LOGIN_SESSIONID_ERROR</td><td>11003</td><td>错误的SessionID</td></tr>
<tr><td>MSP_ERROR_LOGIN_UNLOGIN</td><td>11004</td><td>未登录</td></tr>
<tr><td>MSP_ERROR_LOGIN_INVALID_USER</td><td>11005</td><td>无效的用户</td></tr>
<tr><td>MSP_ERROR_LOGIN_INVALID_PWD</td><td>11006</td><td>无效的密码</td></tr>
<tr><td>MSP_ERROR_LOGIN_SYSTEM_ERROR</td><td>11099</td><td>系统错误</td></tr>
<tr><td>MSP_ERROR_AUTH_NO_LICENSE</td><td>11200</td><td>无授权</td></tr>
<tr><td>MSP_ERROR_AUTH_NO_ENOUGH_LICENSE</td><td>11201</td><td>授权不足</td></tr>
<tr><td>MSP_ERROR_AUTH_INVALID_LICENSE</td><td>11202</td><td>无效的授权</td></tr>
<tr><td>MSP_ERROR_AUTH_LICENSE_EXPIRED</td><td>11203</td><td>授权过期</td></tr>
<tr><td>MSP_ERROR_AUTH_NEED_MORE_DATA</td><td>11204</td><td>无设置信息</td></tr>
<tr><td>MSP_ERROR_AUTH_LICENSE_TO_BE_EXPIRED</td><td>11205</td><td>授权即将过期警告</td></tr>
<tr><td>MSP_ERROR_AUTH_INVALID_MACHINE_ID</td><td>11206</td><td>无效的机器码</td></tr>
<tr><td>MSP_ERROR_AUTH_LOCAL_ASR_FORBIDDEN</td><td>11207</td><td>禁止使用本地设别</td></tr>
<tr><td>MSP_ERROR_AUTH_LOCAL_TTS_FORBIDDEN</td><td>11208</td><td>禁止使用本地合成</td></tr>
<tr><td>MSP_ERROR_AUTH_LOCAL_IVW_FORBIDDEN</td><td>11029</td><td>禁止使用本地唤醒</td></tr>
<tr><td>MSP_ERROR_AUTH_ERROR_END</td><td>11250</td><td>授权相关错误码结束标记</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_SILENCE</td><td>11401</td><td>无语音或音量太小</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_SNRATIO</td><td>11402</td><td>信噪比低或有效语音过短</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_PAPERDATA</td><td>11403</td><td>非试卷数据</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_PAPERCONTENTS</td><td>11404</td><td>试卷内容有误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_NOTMONO</td><td>11405</td><td>录音格式有误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_OTHERS</td><td>11406</td><td>其他评测数据异常，包括错读、漏读、恶意录入、试卷内容等错误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_PAPERFMT</td><td>11407</td><td>试卷格式有误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_ULISTWORD</td><td>11408</td><td>存在未登记词</td></tr>
<tr><td>MSS_ERROR_IVP_MODEL_NOT_FOUND_IN_HBASE</td><td>11610</td><td>声纹模型数据找不到</td></tr>
<tr><td>MSP_ERROR_HTTP_BASE</td><td>12000</td><td>HTTP错误基码</td></tr>
</table>

其它错误码参见下表：

<table>
<tr><th width="40%">错误码</th><th width="30%">错误值</th><th>说明</th></tr>
<tr><td>ERROR_NO_NETWORK</td><td>20001</td><td>无有效的网络连接</td></tr>
<tr><td>ERROR_NETWORK_TIMEOUT</td><td>20002</td><td>网络连接超时</td></tr>
<tr><td>ERROR_NET_EXPECTION</td><td>20003</td><td>网络连接发生异常</td></tr>
<tr><td>ERROR_INVALID_RESULT</td><td>20004</td><td>无有效的结果</td></tr>
<tr><td>ERROR_NO_MATCH</td><td>20005</td><td>无匹配结果</td></tr>
<tr><td>ERROR_AUDIO_RECORD</td><td>20006</td><td>录音失败</td></tr>
<tr><td>ERROR_NO_SPPECH</td><td>20007</td><td>未检测到语音</td></tr>
<tr><td>ERROR_SPEECH_TIMEOUT</td><td>20008</td><td>音频输入超时</td></tr>
<tr><td>ERROR_EMPTY_UTTERANCE</td><td>20009</td><td>无效的文本输入</td></tr>
<tr><td>ERROR_FILE_ACCESS</td><td>20010</td><td>文件读写失败</td></tr>
<tr><td>ERROR_PLAY_MEDIA</td><td>20011</td><td>音频播放失败</td></tr>
<tr><td>ERROR_INVALID_PARAM</td><td>20012</td><td>无效的参数</td></tr>
<tr><td>ERROR_TEXT_OVERFLOW</td><td>20013</td><td>文本溢出</td></tr>
<tr><td>ERROR_INVALID_DATA</td><td>20014</td><td>无效数据</td></tr>
<tr><td>ERROR_LOGIN</td><td>20015</td><td>用户未登陆</td></tr>
<tr><td>ERROR_PERMISSION_DENIED</td><td>20016</td><td>无效授权</td></tr>
<tr><td>ERROR_INTERRUPT</td><td>20017</td><td>被异常打断</td></tr>
<tr><td>ERROR_VERSION_LOWER</td><td>20018</td><td>版本过低</td></tr>
<tr><td>ERROR_COMPONENT_NOT_INSTALLED</td><td>21001</td><td>没有安装语音组件</td></tr>
<tr><td>ERROR_ENGINE_NOT_SUPPORTED</td><td>21002</td><td>引擎不支持</td></tr>
<tr><td>ERROR_ENGINE_INIT_FAIL</td><td>21003</td><td>初始化失败</td></tr>
<tr><td>ERROR_ENGINE_CALL_FAIL</td><td>21004</td><td>调用失败</td></tr>
<tr><td>ERROR_ENGINE_BUSY</td><td>21005</td><td>引擎繁忙</td></tr>
<tr><td>ERROR_LOCAL_NO_INIT</td><td>22001</td><td>本地引擎未初始化</td></tr>
<tr><td>ERROR_LOCAL_RESOURCE</td><td>22002</td><td>本地引擎无资源</td></tr>
<tr><td>ERROR_LOCAL_ENGINE</td><td>22003</td><td>本地引擎内部错误</td></tr>
<tr><td>ERROR_IVW_INTERRUPT</td><td>22004</td><td>本地唤醒引擎被异常打断</td></tr>
<tr><td>ERROR_UNKNOWN</td><td>20999</td><td>未知错误</td></tr>
</table>
