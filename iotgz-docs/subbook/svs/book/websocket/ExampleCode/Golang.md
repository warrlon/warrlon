# golang代码示例

```golang
    package main
    
    import (
       "bufio"
       "encoding/json"
       "fmt"
       "github.com/gorilla/websocket"
       uuid "github.com/satori/go.uuid"
       "os"
       "strings"
    )
    
    type BaseRequest struct {
       Topic      string     `json:"topic"`
       RecordId   string     `json:"recordId"`
       SessionId  string     `json:"sessionId"`
       Audio      *Audio     `json:"audio"`
       RefText    string     `json:"refText"`
       WakeupWord string     `json:"wakeupWord"`
       AsrParams  *AsrParams `json:"asrParams"`
       AiType     string     `json:"aiType"`
    }
    
    type Audio struct {
       AudioType   string `json:"audioType"`
       SampleRate  int    `json:"sampleRate"`
       Channel     int    `json:"channel"`
       SampleBytes int    `json:"sampleBytes"`
    }
    
    type AsrParams struct {
       RealBack            bool        `json:"realBack"`
       EnableVAD           bool        `json:"enableVAD"`
       EnablePunctuation   bool        `json:"enablePunctuation"`
       EnableTone          bool        `json:"enableTone"`
       EnableConfidence    bool        `json:"enableConfidence"`
       EnableNumberConvert bool        `json:"enableNumberConvert"`
       PhraseHints         interface{} `json:"phraseHints"`
    }
    
    
    //发送文本请求
    func getTextParam(isAudio bool) ([]byte){
       requestId, _ := uuid.NewV1()
       requestIdStr := strings.ReplaceAll(requestId.String(), "-", "")
       var duiRequestData *BaseRequest
       if isAudio{
          duiRequestData = &BaseRequest{
             Topic:      "recorder.stream.start",
             RecordId:   requestIdStr,
             Audio:      &Audio{
                AudioType:   "mp3",    //修改为测试文件的类型
                SampleRate:  16000,    //修改为测试文件的SampleRate
                Channel:     1,       //修改为测试文件的Channel
                SampleBytes: 2,       //修改为测试文件的SampleBytes
             },
             AsrParams:  &AsrParams{
                RealBack:            true,  //实时返回asr结果
                EnableVAD: true,     //启动VAD
                EnablePunctuation: true,     //返回结果是否带拼音
                EnableTone: true,     //返回结果是否带声调
                EnableConfidence: true,     //返回结果是否带置信度
                EnableNumberConvert: true,    //返回结果是否进行数字转换
             },
             AiType:     "dm",  //可选dm/asr, dm获取对话结果，asr只获取asr结果
          }
       }else {
          duiRequestData = &BaseRequest{
             Topic:      "nlu.input.text",
             RecordId:   requestIdStr,
             RefText:    "测试", //修改文本请求的输入
             AiType:     "dm",
          }
       }
       data, _ := json.Marshal(duiRequestData)
       return data
    }
    
    
    func textRequest(c *websocket.Conn){
       duiAsrParam := getTextParam(false)
       go func() {
          err := c.WriteMessage(websocket.TextMessage, duiAsrParam)
          if err != nil {
             fmt.Println("write:", err)
             return
          }
       }()
    }
    
    //发送音频请求
    func audioRequest(c *websocket.Conn){
       // 测试音频文件路径。
       path := "test.mp3"
       duiAsrParam := getTextParam(true)
       go func() {
          err := c.WriteMessage(websocket.TextMessage, duiAsrParam)
          if err != nil {
             fmt.Println("write:", err)
             return
          }
          f, _ := os.Open(path)
          defer f.Close()
          buf := make([]byte, 400) // wav buffsize=3200 其他的400
          bfRd := bufio.NewReader(f)
          for {
             n, err := bfRd.Read(buf)
             if err != nil {
                //fmt.Println(err)
                break
             }
             err = c.WriteMessage(websocket.BinaryMessage, buf[:n])
             if err != nil {
                fmt.Println(err)
                break
             }
          }
          err = c.WriteMessage(websocket.BinaryMessage, []byte(""))
          if err != nil {
             fmt.Println("write close:", err)
             return
          }
       }()
    }
    
    func main() {
    
       //使用自己产品Id和apikey替换下列参数。
       productId := "x"
       apikey := "x"
       url := fmt.Sprintf("ws://botai-dsg.and-home.cn:4443/dsg/v1/prod?productId=%s&apikey=%s", productId, apikey)
    
       c, _, err := websocket.DefaultDialer.Dial(url, nil)
       if err != nil {
          fmt.Println("dial:", err)
       }
       defer c.Close()
    
       //audioRequest(c)   //发送音频请求
       textRequest(c)   //发送文本请求
    
       for {
          _, message, err := c.ReadMessage()
          if err != nil {
             fmt.Println("read err:", err)
             return
          }
          fmt.Println("recv: ", string(message))
          if strings.Contains(string(message), "dm"){
             return
          }
       }
    }
```