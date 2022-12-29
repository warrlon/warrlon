# 对话结果支持内容修改

此接口支持修改对话中的语音播报,修改文本展示等功能

    DDS.getInstance().getAgent().setDMCallback(new DMCallback() {
        @Override
        public JSONObject onDMResult(JSONObject dmResult) {
            // 这里可以对dmResult做一些修改
            return dmResult;
        }
    });
