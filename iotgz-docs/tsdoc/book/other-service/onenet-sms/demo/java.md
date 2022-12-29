# JAVA Code Example






```json
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class SmsApi {

    public static void main(String[] args) throws IOException {
        //模板签名短信接口请求地址
        String templateSmsUrl="http://api.sms.heclouds.com/tempSignSmsSend";
        //模板签名短信接口请求参数
        String formParam="sicode=5b9a3fd4-817b-409f-a4db-85e751b31a62&mobiles=13812341234,13856785678&tempid=10007&signId=12345&code=2623";
        //参数名"code"需要根据模板自定义需要替换的参数名称,否则会调用失败

        HttpURLConnection connection = (HttpURLConnection) new URL(templateSmsUrl).openConnection();
        connection.setRequestMethod("POST");
        connection.setDoOutput(true);
        connection.getOutputStream().write(formParam.getBytes());
        connection.getOutputStream().close();

        int code=connection.getResponseCode();
        InputStream stream=null;

        if(code==200){
            stream=connection.getInputStream();
        } else {
            stream=connection.getErrorStream();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(stream, "utf-8"));
        String str=null;
        StringBuffer sb = new StringBuffer();
        while((str=br.readLine())!=null){
            sb.append(str);
        }
        System.out.println("调用模板签名短信接口"+(code==200 ? "成功" : "失败")+"返回结果："+sb.toString());
    }
}
```