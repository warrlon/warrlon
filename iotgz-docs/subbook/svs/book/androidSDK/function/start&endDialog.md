# 开启/终止对话

您可以在任何时刻主动开启/终止对话，通过以下接口实现。

    // 开启对话。如果当前已经在对话中，则重新开启新一轮对话。
    DDS.getInstance().getAgent().startDialog();
    
    // 关闭对话
    DDS.getInstance().getAgent().stopDialog();
    
    // 支持在开启对话时传入一个播报文本, 先播报文本,后开启对话
    Agent.startDialog(JSONObject jsonObject)
    
    // 支持在关闭对话时传入一个播报文本, 文本播报结束后自动结束对话
    Agent.stopDialog(JSONObject jsonObject)
    
    使用示例:
    JSONObject jsonObject = new JSONObject();
    jsonObject.put("speakText", "播报文本");
    DDS.getInstance().getAgent().startDialog(jsonObject);
    
    // 在多轮对话中强制设置为首轮
    DDS.getInstance().getAgent().endSkillInDialog()
    
    // 多模态事件同步,该接口用于客户端给对话中控发送一个事件(可替代endSkillInDialog接口)
    DDS.getInstance().getAgent().updateDispatchEvent(JSONObject obj)
    使用示例:
    JSONObject obj = new JSONObject();
    obj.put("endSkill", "true");
    DDS.getInstance().getAgent().updateDispatchEvent(obj);
