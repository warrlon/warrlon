# Batch export equipment

Platform provides batch export tools for scenarios where batch export equipment is required

The steps are as follows.

### Step 1 

To download the export toolkit, click on the download link (https://codeload.github.com/cm-heclouds/onenet_device_export/zip/master)

    Support Windows Operating System Only

### Step 2 

Modify the configuration file by editing the api-key in app.conf to the user's api-key

    Note that the brackets of "(your api-key)" should not be retained

 Examples of configuration file modifications are as follows:



```
[onenet]
url=http://api.heclouds.com
apiKey=T14Rq2Ovjs9d12bc30aplyeLeU=

[search]
key_words=my
auth_info=203x1
tag=mobile
online=ture
private=false
begin=
end=
[app]
goroutine=20
```

Description of parameters:

| Name of parameter | Description | Is it mandatory to fill in|
|:-|:-|:-|
| APiKey | Master-APIkey of the product, the product profile page can be seen, such as T14Rq2Ovjs9d12bc30aplyeLeU= | must fill in|
| Key_words | Matches keywords, such as key_words = my, matches keywords, matches left from the ID and title fields | Select and fill in|
| auth_info | Authentication information, such as auth_info=203x1, corresponds to the SN parameter at the time of registration, unique device number | select fill in|
| tag | Device tags added through interfaces or pages, such as tag = mobile | Fill in|
| online | online state, Boolean value, such as online = true / false | optional fill|
| Private | Private or not, Boolean value, as private = true / false /| Optional fill|
| Start | Start time, as begin = 2016-06-20// Start time, including the day | Selected Fill|
| End | end = end time, such as 2016-06-20// end time, including the day | fill in|

### Step 3

Double-click exe program, will automatically generate batch export equipment Excel file, according to the amount of equipment different time-consuming, please wait;