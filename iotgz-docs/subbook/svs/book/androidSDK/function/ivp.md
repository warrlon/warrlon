# 声纹

```javascript
    // 注册声纹监听器
    VprintEngine.getInstance().setVprintListener(new VprintListener() {
        @Override
        public void onState(String state) {
            Log.e(TAG, "onState = " + state);
        }
    
        @Override
        public void onResults(String result) {
            Log.e(TAG, "onResults = " + result);
        }
    
        @Override
        public void onError(String error) {
            Log.e(TAG, "onError = " + error);
        }
    });
    
    // 注册声纹
    VprintIntent intent = new VprintIntent.Builder()
            .setAction(VprintIntent.Action.REGISTER)
            .setTrainNum(3)
            .setOutChannelNum(2)
            .setSnrThresh(8.67f)
            .setUserId("userId")
            .setVprintWord("ni hao xiao chi")
            .create();
    DDS.getInstance().getAgent().getVprintEngine().start(intent);
    
    // 更新声纹
    VprintIntent intent = new VprintIntent.Builder()
            .setAction(VprintIntent.Action.UPDATE)
            .setTrainNum(3)
            .setOutChannelNum(2)
            .setSnrThresh(8.67f)
            .setUserId("userId")
            .setVprintWord("ni hao xiao chi")
            .create();
    DDS.getInstance().getAgent().getVprintEngine().start(intent);
    
    // 追加声纹
    VprintIntent intent = new VprintIntent.Builder()
            .setAction(VprintIntent.Action.APPEND)
            .setTrainNum(3)
            .setOutChannelNum(2)
            .setSnrThresh(8.67f)
            .setUserId("userId")
            .setVprintWord("ni hao xiao chi")
            .create();
    DDS.getInstance().getAgent().getVprintEngine().start(intent);
    
    // 删除一条声纹
    VprintIntent intent = new VprintIntent.Builder()
            .setAction(VprintIntent.Action.UNREGISTER)
            .setTrainNum(3)
            .setOutChannelNum(2)
            .setUserId("userId")
            .setVprintWord("ni hao xiao chi")
            .create();
    DDS.getInstance().getAgent().getVprintEngine().start(intent);
    
    // 删除所有声纹
    VprintIntent intent = new VprintIntent.Builder()
            .setAction(VprintIntent.Action.UNREGISTER_ALL)
            .create();
    DDS.getInstance().getAgent().getVprintEngine().start(intent);
    
    // 使用声纹
    VprintIntent intent = new VprintIntent.Builder()
            .setAction(VprintIntent.Action.TEST)
            .setOutChannelNum(2)
            .create();
    
    DDS.getInstance().getAgent().getVprintEngine().start(intent);
    
    // 获取声纹模型
    String result = VprintEngine.getInstance().getMode();
    
    // 停止使用声纹
    VprintEngine.getInstance().stop();
```