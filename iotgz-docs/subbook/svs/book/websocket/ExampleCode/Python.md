# python代码示例

```python
    import json
    import asyncio
    import websockets
    from uuid import uuid4
    
    # 音频文件测试路径。
    audioFile = "test.mp3"
    
    # 使用自己产品Id和apikey替换下列参数。
    productId = "x"
    apikey = "x"
    
    
    #发送文本请求
    async def textRequest(ws):
        content = {
            "aiType":"dm",
            "topic": 'nlu.input.text',
            "recordId": uuid4().hex,
            "refText": "测试"   #修改文本请求的输入
        }
        try:
            await ws.send(json.dumps(content))
            resp = await ws.recv()
            print(resp)
        except websockets.exceptions.ConnectionClosed as exp:
            print(exp)
    
    #发送音频请求
    async def audioRequest(ws):
        content = {
            "aiType": "dm",   #可选dm/asr, dm获取对话结果，asr只获取asr结果
            "topic": "recorder.stream.start",
            "recordId": uuid4().hex,
            "audio": {
                "audioType": "mp3",   #修改为测试文件的类型
                "sampleRate": 16000, #修改为测试文件的sampleRate
                "channel": 1,        #修改为测试文件的channel
                "sampleBytes": 2     #修改为测试文件的sampleBytes
            },
            "asrParams": {
                "realBack": True,      #实时返回asr结果
                "enableVAD": True,     #启动VAD
                "enablePunctuation": True,     #返回结果是否带拼音
                "enableTone": True,     #返回结果是否带声调
                "enableConfidence": True,     #返回结果是否带置信度
                "enableNumberConvert": True,    #返回结果是否进行数字转换
            },
        }
    
        try:
            #发送文本消息
            await ws.send(json.dumps(content))
            # 发送音频消息
            with open(audioFile, 'rb') as f:
                while True:
                    chunk = f.read(400) #wav buffsize=3200 其他的400
                    if not chunk:
                        await ws.send(bytes("", encoding="utf-8"))
                        break
                    print(len(chunk))
                    await ws.send(chunk)
            async for message in ws:
                print(message)
                resp = json.loads(message)
                if 'dm' in resp:
                    break
        except websockets.exceptions.ConnectionClosed as exp:
            print(exp)
            ws.close()
    
    async def dds_demo():
        url = f"ws://botai-dsg.and-home.cn:4443/dsg/v1/prod?productId={productId}&apikey={apikey}"
        print(url)
        async with websockets.connect(url) as websocket:
            #await textRequest(websocket)    #发送文本请求
            await audioRequest(websocket)    #发送音频请求
    
    asyncio.get_event_loop().run_until_complete(dds_demo())
```

