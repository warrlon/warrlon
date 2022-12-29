# Create a single device
After the product is created, it will be prompted to add devices immediately, that is, to enter the product and switch to the device list page.

![Device List](/images/dj/设备列表.png)

Click to create the device, fill in the device information, confirm that the addition of a device will be completed after adding. The required equipment information is as follows:

![Single Creation Device](/images/dj/单个创建设备.png)

### Description of parameters

| parameter name | description | restriction|
|:-|:-|:-|
| Device Name | Custom Device Name, Repeatable | Limit 1-64 Words|
| Authentication Information | Unique in the product, recommend the use of product serial number, can be used as one of the device login parameters, different protocol devices may have different parameters of authentication information | Limit 1-512 English, digital|
| Data Confidentiality | Private: You can't share the device's data with other users through a lightweight application editor, but you can show it publicly | Mandatory, default to private|
| Device Description | Custom Device Description Information | Select Fill-in|
| Device Label | Can be used as a classification parameter in API queries | 1-8 words, up to 5 tags|
| Device Location | Determine a device location by clicking or searching the page, and the platform stores static information | Select Fill-in|

Click Add to complete device creation.