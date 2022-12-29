# C# Code Example








```json
private void SendTemplateSignSMS()
        {
            //实际使用时，请注意以下事项：
            //1.请将sicode填写为您申请到的sicode；
            //2.请将smsTemplateId填写为已经审核通过的模板ID；
            //3.请将smsSignId填写为已经审核通过的签名ID；
            //4.请将接收号码替换为您需要的接收人号码，注意多个号码时，请用英文的逗号分隔；
            //5.下方代码中“name”参数请替换为您的短信模板中设置的变量名称，含多个变量名称时，请按照&name1={2}&name2={3} 样式来填写；
            //6.请确保您的账户中有足够的短信余额供调用；

            //模板签名短信接口请求地址        
            string templateSmsUrl = "http://api.sms.heclouds.com/tempSignSmsSend";        

            //模板签名短信接口参数   
            string sicode = "此处请替换为您注册时得到的sicode,登录后在个人中心首页可以看到";
            string smsTemplateId = "10003";
            string smsSignId = "12345";
            string receiveMobile = "135274XXXXX";

            string paramData = string.Format("sicode={0}&mobiles={1}&tempid={2}&tempid={3}&name={4}", sicode, receiveMobile,
                                             smsTemplateId,smsSignId,"土豆");

            var sendResult = PostWebRequest(templateSmsUrl, paramData, Encoding.UTF8);
        }

        private string PostWebRequest(string postUrl, string paramData, Encoding dataEncode)
        {
            string ret = string.Empty;
            try
            {
                byte[] byteArray = dataEncode.GetBytes(paramData); //转化
                HttpWebRequest webReq = (HttpWebRequest)WebRequest.Create(new Uri(postUrl));
                webReq.Method = "POST";
                webReq.ContentType = "application/x-www-form-urlencoded";

                webReq.ContentLength = byteArray.Length;
                Stream newStream = webReq.GetRequestStream();
                newStream.Write(byteArray, 0, byteArray.Length);//写入参数
                newStream.Close();
                HttpWebResponse response = (HttpWebResponse)webReq.GetResponse();
                StreamReader sr = new StreamReader(response.GetResponseStream(), Encoding.Default);
                ret = sr.ReadToEnd();
                sr.Close();
                response.Close();
                newStream.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            return ret;
        }
```