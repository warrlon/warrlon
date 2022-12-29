# 对象和属性

OneNET针对LwM2M协议提供丰富的对象（object）和属性（resource），对象和属性的定义基于[OMA规范](http://www.openmobilealliance.org/wp/OMNA/LwM2M/LwM2MRegistry.html)做了部分修改，您可以查看[OneNET与OMA规范差异](#2)。

您可以下载OneNET [LwM2M对象和属性](/book/doc/oma-objects-spec.docx)。
 <h2 id="2"> OneNET与OMA规范差异</h2>
<table>
<tr><th width="17%">object id</th><th width="20%">resource id</th><th width="17%">OneNET_resourceType</th><th width="17%">OMA_resourceType</th><th>说明</th></tr>
<tr><td>3</td><td>26261</td><td>Integer</td><td></td><td>对象增加平台自定义属性</td></tr>
<tr><td>5</td><td>26500<br>26501</td><td>Integer<br>Integer</td><td></td><td>对象增加平台自定义属性</td></tr>
<tr><td>3200</td><td>5505</td><td>Opaque</td><td>String</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3202</td><td>5605</td><td>Opaque</td><td>String</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3203</td><td>5605</td><td>Opaque</td><td>String</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3204</td><td>5605</td><td>Opaque</td><td>String</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3310</td><td>5824<br>5825<br>5826<br>5827<br>5828</td><td>String<br>String<br>String<br>String<br>String<br></td><td>Time<br>Integer<br>Integer<br>Integer<br>Integer</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3311</td><td>5750</td><td>Opaque</td><td>String</td><td>平台暂未定义该属性，默认为Opaque</td></tr>
<tr><td>3316</td><td>5821</td><td>String</td><td>Float</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3322</td><td>5605<br>5821</td><td>Opaque<br>String</td><td>String<br>Float</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3330</td><td>5605</td><td>Opaque</td><td>String</td><td>对象定义的属性数据类型变化</td></tr>
<tr><td>3331</td><td>5805</td><td>Float</td><td></td><td>对象定义的属性数据类型变化，OMA已删除该资源</td></tr>
<tr><td>3338</td><td>5548</td><td>Opaque</td><td>Float</td><td>平台暂未定义该属性，默认为opaque</td></tr>
<tr><td>10290</td><td></td><td></td><td></td><td>平台内部使用对象，禁止使用</td></tr>
<tr><td>22001</td><td>21001<br>21002<br>21003</td><td>Boolean<br>Boolean<br>Boolean</td><td></td><td>对象增加平台自定义属性</td></tr>
<tr><td>22002</td><td>5700<br>5701</td><td>Float<br>String</td><td></td><td>对象增加平台自定义属性</td></tr>
</tr>
</table>


<table>
<tr><th width="17%">object id</th><th width="20%">resource id</th><th width="17%">OneNET_resourceName</th><th width="17%">OMA_resourceName</th><th>说明</th></tr>
<tr><td>3336</td><td>5513<br>5514<br>5515</td><td>Latitude<br>Longitude<br>Alititude</td><td><br>Latitude<br>Longititude</td><td>对象定义的属性名称变化，OMA已删除5513资源</td></tr>
</table>

## LwM2M对象和属性
```json
[
  {
    "name": "LwM2M Security",
    "id": 0,
    "instancetype": "multiple",
    "mandatory": true,
    "description": "This LwM2M Object provides the keying material of a LwM2M Client appropriate to access a specified LwM2M Server. One Object Instance SHOULD address a LwM2M Bootstrap-Server.\nThese LwM2M Object Resources MUST only be changed by a LwM2M Bootstrap-Server or Bootstrap from Smartcard and MUST NOT be accessible by any other LwM2M Server.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "LwM2M  Server URI",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Uniquely identifies the LwM2M Server or LwM2M Bootstrap-Server. The format of the CoAP URI is defined in Section 6 of RFC 7252."
      },
      {
        "id": 1,
        "name": "Bootstrap-Server",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Determines if the current instance concerns a LwM2M Bootstrap-Server (true) or a standard LwM2M Server (false)"
      },
      {
        "id": 2,
        "name": "Security Mode",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-4",
        "units": "",
        "description": "Determines which UDP payload security mode is used\n0: Pre-Shared Key mode\n1: Raw Public Key mode\n2: Certificate mode\n3: NoSec mode\n4: Certificate mode with EST"
      },
      {
        "id": 3,
        "name": "Public Key or Identity",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Stores the LwM2M Client’s Certificate (Certificate mode), public key (RPK mode) or PSK Identity (PSK mode). The format is defined in Section E.1.1 of the LwM2M version 1.0 specification."
      },
      {
        "id": 4,
        "name": "Server Public Key",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Stores the LwM2M Server’s or LwM2M Bootstrap-Server’s Certificate (Certificate mode), public key (RPK mode). The format is defined in Section E.1.1 of the LwM2M version 1.0 specification."
      },
      {
        "id": 5,
        "name": "Secret Key",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Stores the secret key or private key of the security mode. The format of the keying material is defined by the security mode in Section E.1.1 of the LwM2M version 1.0 specification. This Resource MUST only be changed by a bootstrap-server and MUST NOT be readable by any server."
      },
      {
        "id": 6,
        "name": "SMS Security Mode",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-255",
        "units": "",
        "description": "Determines which SMS security mode is used (see section 7.2 of the LwM2M version 1.0 specification)\n0: Reserved for future use\n1: DTLS mode (Device terminated) PSK mode assumed\n2: Secure Packet Structure mode (Smartcard terminated)\n3: NoSec mode\n4: Reserved mode (DTLS mode with multiplexing Security Association support)\n5-203 : Reserved for future use\n204-255: Proprietary modes"
      },
      {
        "id": 7,
        "name": "SMS Binding Key Parameters",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "6 bytes",
        "units": "",
        "description": "Stores the KIc, KID, SPI and TAR. The format is defined in Section E.1.2 of the LwM2M version 1.0 specification."
      },
      {
        "id": 8,
        "name": "SMS Binding Secret Key(s)",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "16-32-48 bytes",
        "units": "",
        "description": "Stores the values of the key(s) for the SMS binding. \nThis resource MUST only be changed by a bootstrap-server and MUST NOT be readable by any server."
      },
      {
        "id": 9,
        "name": "LwM2M Server SMS Number",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "MSISDN used by the LwM2M Client to send messages to the LwM2M Server via the SMS binding. \nThe LwM2M Client SHALL silently ignore any SMS originated from unknown MSISDN"
      },
      {
        "id": 10,
        "name": "Short Server ID",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "1-65534",
        "units": "",
        "description": "This identifier uniquely identifies each LwM2M Server configured for the LwM2M Client.\nThis Resource MUST be set when the Bootstrap-Server Resource has false value.\nSpecific ID:0 and ID:65535 values MUST NOT be used for identifying the LwM2M Server (Section 6.3 of the LwM2M version 1.0 specification)."
      },
      {
        "id": 11,
        "name": "Client Hold Off Time",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "Relevant information for a Bootstrap-Server only.\nThe number of seconds to wait before initiating a Client Initiated Bootstrap once the LwM2M Client has determined it should initiate this bootstrap mode.\nIn case client initiated bootstrap is supported by the LwM2M Client, this resource MUST be supported."
      },
      {
        "id": 12,
        "name": "Bootstrap-Server Account Timeout",
        "operations": "NONE",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The LwM2M Client MUST purge the LwM2M Bootstrap-Server Account after the timeout value given by this resource. The lowest timeout value is 1.\nIf the value is set to 0, or if this resource is not instantiated, the Bootstrap-Server Account lifetime is infinite."
      }
    ]
  },
  {
    "name": "LwM2M Server",
    "id": 1,
    "instancetype": "multiple",
    "mandatory": true,
    "description": "This LwM2M Objects provides the data related to a LwM2M Server. A Bootstrap-Server has no such an Object Instance associated to it.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Short Server ID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "1-65535",
        "units": "",
        "description": "Used as link to associate server Object Instance."
      },
      {
        "id": 1,
        "name": "Lifetime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "Specify the lifetime of the registration in seconds (see Section 5.3 Registration)."
      },
      {
        "id": 2,
        "name": "Default Minimum Period",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The default value the LwM2M Client should use for the Minimum Period of an Observation in the absence of this parameter being included in an Observation.\nIf this Resource doesn’t exist, the default value is 0."
      },
      {
        "id": 3,
        "name": "Default Maximum Period",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The default value the LwM2M Client should use for the Maximum Period of an Observation in the absence of this parameter being included in an Observation."
      },
      {
        "id": 4,
        "name": "Disable",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If this Resource is executed, this LwM2M Server Object is disabled for a certain period defined in the Disabled Timeout Resource. After receiving “Execute” operation, LwM2M Client MUST send response of the operation and perform de-registration process, and underlying network connection between the Client and Server MUST be disconnected to disable the LwM2M Server account.\nAfter the above process, the LwM2M Client MUST NOT send any message to the Server and ignore all the messages from the LwM2M Server for the period."
      },
      {
        "id": 5,
        "name": "Disable Timeout",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "A period to disable the Server. After this period, the LwM2M Client MUST perform registration process to the Server. If this Resource is not set, a default timeout value is 86400 (1 day)."
      },
      {
        "id": 6,
        "name": "Notification Storing When Disabled or Offline",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "If true, the LwM2M Client stores “Notify” operations to the LwM2M Server while the LwM2M Server account is disabled or the LwM2M Client is offline. After the LwM2M Server account is enabled or the LwM2M Client is online, the LwM2M Client reports the stored “Notify” operations to the Server.\nIf false, the LwM2M Client discards all the “Notify” operations or temporarily disables the Observe function while the LwM2M Server is disabled or the LwM2M Client is offline.\nThe default value is true.\nThe maximum number of storing Notifications per Server is up to the implementation."
      },
      {
        "id": 7,
        "name": "Binding",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "The possible values of Resource are listed in 5.3.1.1",
        "units": "",
        "description": "This Resource defines the transport binding configured for the LwM2M Client.\nIf the LwM2M Client supports the binding specified in this Resource, the LwM2M Client MUST use that transport for the Current Binding Mode."
      },
      {
        "id": 8,
        "name": "Registration Update Trigger",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If this Resource is executed the LwM2M Client MUST perform an “Update” operation with this LwM2M Server using that transport for the Current Binding Mode."
      }
    ]
  },
  {
    "name": "LwM2M Access Control",
    "id": 2,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Access Control Object is used to check whether the LwM2M Server has access right for performing an operation.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Object ID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "1-65534",
        "units": "",
        "description": "Resources 0 and 1 point to the Object Instance for which the Instances of the ACL Resource of that Access Control Object Instance are applicable."
      },
      {
        "id": 1,
        "name": "Object Instance ID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-65535",
        "units": "",
        "description": "See above"
      },
      {
        "id": 2,
        "name": "ACL",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "16-bit",
        "units": "",
        "description": "The Resource Instance ID MUST be the Short Server ID of a certain LwM2M Server for which associated access rights are contained in the Resource Instance value.\nThe Resource Instance ID 0 is a specific ID, determining the ACL Instance which contains the default access rights.\nEach bit set in the Resource Instance value, grants an access right to the LwM2M Server to the corresponding operation.\nThe bit order is specified as below.\n1st LSB: R(Read, Observe, Write-Attributes)\n2nd LSB: W(Write)\n3rd LSB: E(Execute)\n4th LSB: D(Delete)\n5th LSB: C(Create)\nOther bits are reserved for future use."
      },
      {
        "id": 3,
        "name": "Access Control Owner",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-65535",
        "units": "",
        "description": "Short Server ID of a certain LwM2M Server; only such an LwM2M Server can manage the Resources of this Object Instance. \nThe specific value MAX_ID\u003d65535 means this Access Control Object Instance is created and modified during a Bootstrap phase only."
      }
    ]
  },
  {
    "name": "Device",
    "id": 3,
    "instancetype": "single",
    "mandatory": true,
    "description": "This LwM2M Object provides a range of device related information which can be queried by the LwM2M Server, and a device reboot and factory reset function.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Manufacturer",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Human readable manufacturer name"
      },
      {
        "id": 1,
        "name": "Model Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A model identifier (manufacturer specified string)"
      },
      {
        "id": 2,
        "name": "Serial Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Serial Number"
      },
      {
        "id": 3,
        "name": "Firmware Version",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Current firmware version of the Device.The Firmware Management function could rely on this resource."
      },
      {
        "id": 4,
        "name": "Reboot",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Reboot the LwM2M Device to restore the Device from unexpected firmware failure."
      },
      {
        "id": 5,
        "name": "Factory Reset",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Perform factory reset of the LwM2M Device to make the LwM2M Device to go through initial deployment sequence where provisioning and bootstrap sequence is performed. This requires client ensuring post factory reset to have minimal information to allow it to carry out one of the bootstrap methods specified in section 5.2.3. \nWhen this Resource is executed, “De-register” operation MAY be sent to the LwM2M Server(s) before factory reset of the LwM2M Device."
      },
      {
        "id": 6,
        "name": "Available Power Sources",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "0-7",
        "units": "",
        "description": "0 – DC power\n1 – Internal Battery\n2 – External Battery\n4 – Power over Ethernet\n5 – USB\n6 – AC (Mains) power\n7 – Solar\nThe same Resource Instance ID MUST be used to associate a given Power Source (Resource ID:6) with its Present Voltage (Resource ID:7) and its Present Current (Resource ID:8)"
      },
      {
        "id": 7,
        "name": "Power Source Voltage",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "mV",
        "description": "Present voltage for each Available Power Sources Resource Instance."
      },
      {
        "id": 8,
        "name": "Power Source Current",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "mA",
        "description": "Present current for each Available Power Source."
      },
      {
        "id": 9,
        "name": "Battery Level",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "Contains the current battery level as a percentage (with a range from 0 to 100). This value is only valid for the Device internal Battery if present (one Available Power Sources Resource Instance is 1)."
      },
      {
        "id": 10,
        "name": "Memory Free",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "KB",
        "description": "Estimated current available amount of storage space which can store data and software in the LwM2M Device (expressed in kilobytes)."
      },
      {
        "id": 11,
        "name": "Error Code",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "0-8",
        "units": "",
        "description": "0\u003dNo error\n1\u003dLow battery power\n2\u003dExternal power supply off\n3\u003dGPS module failure\n4\u003dLow received signal strength\n5\u003dOut of memory\n6\u003dSMS failure\n7\u003dIP connectivity failure\n8\u003dPeripheral malfunction\n\nWhen the single Device Object Instance is initiated, there is only one error code Resource Instance whose value is equal to 0 that means no error. When the first error happens, the LwM2M Client changes error code Resource Instance to any non-zero value to indicate the error type. When any other error happens, a new error code Resource Instance is created. When an error associated with a Resource Instance is no longer present, that Resource Instance is deleted. When the single existing error is no longer present, the LwM2M Client returns to the original no error state where Instance 0 has value 0.\nThis error code Resource MAY be observed by the LwM2M Server. How to deal with LwM2M Client’s error report depends on the policy of the LwM2M Server."
      },
      {
        "id": 12,
        "name": "Reset Error Code",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Delete all error code Resource Instances and create only one zero-value error code that implies no error, then re-evaluate all error conditions and update and create Resources Instances to capture all current error conditions."
      },
      {
        "id": 13,
        "name": "Current Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "time",
        "range": "",
        "units": "",
        "description": "Current UNIX time of the LwM2M Client.\nThe LwM2M Client should be responsible to increase this time value as every second elapses.\nThe LwM2M Server is able to write this Resource to make the LwM2M Client synchronized with the LwM2M Server."
      },
      {
        "id": 14,
        "name": "UTC Offset",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Indicates the UTC offset currently in effect for this LwM2M Device. UTC+X [ISO 8601]."
      },
      {
        "id": 15,
        "name": "Timezone",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Indicates in which time zone the LwM2M Device is located, in IANA Timezone (TZ) database format."
      },
      {
        "id": 16,
        "name": "Supported Binding and Modes",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Indicates which bindings and modes are supported in the LwM2M Client. The possible values of Resource are combination of \"U\" or \"UQ\" and \"S\" or \"SQ\"."
      },
      {
        "id": 17,
        "name": "Device Type",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Type of the device (manufacturer specified string: e.g., smart meters / dev Class…)"
      },
      {
        "id": 18,
        "name": "Hardware Version",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Current hardware version of the device"
      },
      {
        "id": 19,
        "name": "Software Version",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Current software version of the device (manufacturer specified string). On elaborated LwM2M device, SW could be split in 2 parts: a firmware one and a higher level software on top.\nBoth pieces of Software are together managed by LwM2M Firmware Update Object (Object ID 5)"
      },
      {
        "id": 20,
        "name": "Battery Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-6",
        "units": "",
        "description": "This value is only valid for the Device Internal Battery if present (one Available Power Sources Resource Instance value is 1).\nBattery\nStatus\tMeaning\tDescription\n0\tNormal\tThe battery is operating normally and not on power.\n1\tCharging\tThe battery is currently charging.\n2\tCharge Complete\tThe battery is fully charged and still on power.\n3\tDamaged\tThe battery has some problem.\n4\tLow Battery\tThe battery is low on charge.\n5\tNot Installed\tThe battery is not installed.\n6\tUnknown\tThe battery information is not available."
      },
      {
        "id": 21,
        "name": "Memory Total",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total amount of storage space which can store data and software in the LwM2M Device (expressed in kilobytes)."
      },
      {
        "id": 22,
        "name": "ExtDevInfo",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Reference to external “Device” object instance containing information. For example, such an external device can be a Host Device, which is a device into which the Device containing the LwM2M client is embedded. This Resource may be used to retrieve information about the Host Device."
      },
      {
        "id": 26261,
        "name": "MCU Memory Free",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "Integer",
        "range": "",
        "units": "",
        "description": ""
      }
    ]
  },
  {
    "name": "Connectivity Monitoring",
    "id": 4,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M Object enables monitoring of parameters related to network connectivity.\nIn this general connectivity Object, the Resources are limited to the most general cases common to most network bearers. It is recommended to read the description, which refers to relevant standard development organizations (e.g., 3GPP, IEEE).\nThe goal of the Connectivity Monitoring Object is to carry information reflecting the more up to date values of the current connection for monitoring purposes. Resources such as Link Quality, Radio Signal Strength, Cell ID are retrieved during connected mode at least for cellular networks.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Network Bearer",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Indicates the network bearer used for the current LwM2M communication session from the below network bearer list.\n0~20 are Cellular Bearers\n0: GSM cellular network\n1: TD-SCDMA cellular network\n2: WCDMA cellular network\n3: CDMA2000 cellular network\n4: WiMAX cellular network\n5: LTE-TDD cellular network\n6: LTE-FDD cellular network\n7: NB-IoT\n8~20: Reserved for other type cellular network\n21~40 are Wireless Bearers\n21: WLAN network\n22: Bluetooth network\n23: IEEE 802.15.4 network\n24~40: Reserved for other type local wireless network\n41~50 are Wireline Bearers\n41: Ethernet\n42: DSL\n43: PLC\n44~50: reserved for others type wireline networks."
      },
      {
        "id": 1,
        "name": "Available Network Bearer",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Indicates list of current available network bearer. Each Resource Instance has a value from the network bearer list."
      },
      {
        "id": 2,
        "name": "Radio Signal Strength",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "dBm",
        "description": "This node contains the average value of the\nreceived signal strength indication used in the\ncurrent network bearer (as indicated by\nResource 0 of this Object). For the following network bearers the signal strength parameters indicated below are represented by this resource:\nGSM:    RSSI\nUMTS:  RSCP\nLTE:      RSRP\nNB-IoT: NRSRP\nFor more details\non Network Measurement Report, refer to the\nappropriate Cellular or Wireless Network\nstandards. (e.g., for LTE Cellular Network\nrefer to ETSI TS 36.133 specification)."
      },
      {
        "id": 3,
        "name": "Link Quality",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "This contains received link quality  e.g. LQI for IEEE 802.15.4 (range 0..255), RxQual Downlink for GSM (range 0…7, refer to [3GPP 44.018] for more details on Network Measurement Report encoding), RSRQ for LTE, (refer to [3GPP 36.214]), NRSRQ for NB-IoT (refer to [3GPP 36.214])."
      },
      {
        "id": 4,
        "name": "IP Addresses",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The IP addresses assigned to the connectivity interface. (e.g., IPv4, IPv6, etc.)"
      },
      {
        "id": 5,
        "name": "Router IP Addresses",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The IP address of the next-hop IP router, on each of the interfaces specified in resource 4 (IP Addresses).\nNote: This IP Address doesn’t indicate the Server IP address."
      },
      {
        "id": 6,
        "name": "Link Utilization",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "The average utilization of the link to the next-hop IP router in %."
      },
      {
        "id": 7,
        "name": "APN",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Access Point Name in case Network Bearer Resource is a Cellular Network."
      },
      {
        "id": 8,
        "name": "Cell ID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Serving Cell ID in case Network Bearer Resource is a Cellular Network.\nAs specified in TS [3GPP 23.003] and in [3GPP. 24.008]. Range (0…65535) in GSM/EDGE\nUTRAN Cell ID has a length of 28 bits.\nCell Identity in WCDMA/TD-SCDMA. Range: (0..268435455).\nLTE Cell ID has a length of 28 bits.\nParameter definitions in [3GPP 25.331]."
      },
      {
        "id": 9,
        "name": "SMNC",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "%",
        "description": "Serving Mobile Network Code. In case Network Bearer Resource has 0(cellular network). Range (0…999).\nAs specified in TS [3GPP 23.003]."
      },
      {
        "id": 10,
        "name": "SMCC",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Serving Mobile Country Code. In case Network Bearer Resource has 0 (cellular network). Range (0…999).\nAs specified in TS [3GPP 23.003]."
      }
    ]
  },
  {
    "name": "Firmware Update",
    "id": 5,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M Object enables management of firmware which is to be updated. This Object includes installing firmware package, updating firmware, and performing actions after updating firmware. The firmware update MAY require to reboot the device; it will depend on a number of factors, such as the operating system architecture and the extent of the updated software.\nThe envisioned functionality with LwM2M version 1.0 is to allow a LwM2M Client to connect to any LwM2M version 1.0 compliant Server to obtain a firmware imagine using the object and resource structure defined in this section experiencing communication security protection using DTLS. There are, however, other design decisions that need to be taken into account to allow a manufacturer of a device to securely install firmware on a device. Examples for such design decisions are how to manage the firmware update repository at the server side (which may include user interface considerations), the techniques to provide additional application layer security protection of the firmware image, how many versions of firmware imagines to store on the device, and how to execute the firmware update process considering the hardware specific details of a given IoT hardware product. These aspects are considered to be outside the scope of the LwM2M version 1.0 specification.\nA LwM2M Server may also instruct a LwM2M Client to fetch a firmware image from a dedicated server (instead of pushing firmware imagines to the LwM2M Client). The Package URI resource is contained in the Firmware object and can be used for this purpose.\nA LwM2M Client MUST support block-wise transfer [CoAP_Blockwise] if it implements the Firmware Update object.\nA LwM2M Server MUST support block-wise transfer. Other protocols, such as HTTP/HTTPs, MAY also be used for downloading firmware updates (via the Package URI resource). For constrained devices it is, however, RECOMMENDED to use CoAP for firmware downloads to avoid the need for additional protocol implementations.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Package",
        "operations": "W",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Firmware package"
      },
      {
        "id": 1,
        "name": "Package URI",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "URI from where the device can download the firmware package by an alternative mechanism. As soon the device has received the Package URI it performs the download at the next practical opportunity. \nThe URI format is defined in RFC 3986. For example, coaps://example.org/firmware is a syntactically valid URI. The URI scheme determines the protocol to be used. For CoAP this endpoint MAY be a LwM2M Server but does not necessarily need to be. A CoAP server implementing block-wise transfer is sufficient as a server hosting a firmware repository and the expectation is that this server merely serves as a separate file server making firmware images available to LwM2M Clients."
      },
      {
        "id": 2,
        "name": "Update",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Updates firmware by using the firmware package stored in Package, or, by using the firmware downloaded from the Package URI.\nThis Resource is only executable when the value of the State Resource is Downloaded."
      },
      {
        "id": 3,
        "name": "State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-3",
        "units": "",
        "description": "Indicates current state with respect to this firmware update. This value is set by the LwM2M Client.\n0: Idle (before downloading or after successful updating)\n1: Downloading (The data sequence is on the way)\n2: Downloaded\n3: Updating\nIf writing the firmware package to Package Resource is done, or, if the device has downloaded the firmware package from the Package URI the state changes to Downloaded.\nWriting an empty string to Package URI Resource or setting the Package Resource to NULL (‘\\0’), resets the Firmware Update State Machine: the State Resource value is set to Idle and the Update Result Resource value is set to 0.\nWhen in Downloaded state, and the executable Resource Update is triggered, the state changes to Updating.\nIf the Update Resource failed, the state returns at Downloaded.\nIf performing the Update Resource was successful, the state changes from Updating to Idle. \nFirmware Update mechanisms are illustrated below in Figure 29 of the LwM2M version 1.0 specification."
      },
      {
        "id": 5,
        "name": "Update Result",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-9",
        "units": "",
        "description": "Contains the result of downloading or updating the firmware\n0: Initial value. Once the updating process is initiated (Download /Update), this Resource MUST be reset to Initial value.\n1: Firmware updated successfully,\n2: Not enough flash memory for the new firmware package.\n3. Out of RAM during downloading process.\n4: Connection lost during downloading process.\n5: Integrity check failure for new downloaded package.\n6: Unsupported package type.\n7: Invalid URI\n8: Firmware update failed\n9: Unsupported protocol. A LwM2M client indicates the failure to retrieve the firmware image using the URI provided in the Package URI resource by writing the value 9 to the /5/0/5 (Update Result resource) when the URI contained a URI scheme unsupported by the client. Consequently, the LwM2M Client is unable to retrieve the firmware image using the URI provided by the LwM2M Server in the Package URI when it refers to an unsupported protocol."
      },
      {
        "id": 6,
        "name": "PkgName",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Name of the Firmware Package"
      },
      {
        "id": 7,
        "name": "PkgVersion",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",

        "units": "",
        "description": "Version of the Firmware package"
      },
      {
        "id": 8,
        "name": "Firmware Update Protocol Support",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "This resource indicates what protocols the LwM2M Client implements to retrieve firmware images. The LwM2M server uses this information to decide what URI to include in the Package URI. A LwM2M Server MUST NOT include a URI in the Package URI object that uses a protocol that is unsupported by the LwM2M client.\nFor example, if a LwM2M client indicates that it supports CoAP and CoAPS then a LwM2M Server must not provide an HTTP URI in the Packet URI.\nThe following values are defined by this version of the specification:\n0 – CoAP (as defined in RFC 7252) with the additional support for block-wise transfer. CoAP is the default setting.\n1 – CoAPS (as defined in RFC 7252) with the additional support for block-wise transfer\n2 – HTTP 1.1 (as defined in RFC 7230)\n3 – HTTPS 1.1 (as defined in RFC 7230)\nAdditional values MAY be defined in the future. Any value not understood by the LwM2M Server MUST be ignored."
      },
      {
        "id": 9,
        "name": "Firmware Update Delivery Method",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The LwM2M Client uses this resource to indicate its support for transferring firmware images to the client either via the Package Resource (\u003dpush) or via the Package URI Resource (\u003dpull) mechanism.\n0 – Pull only\n1 – Push only\n2 – Both. In this case the LwM2M Server MAY choose the preferred mechanism for conveying the firmware image to the LwM2M Client."
      },
      {
        "id": 26500,
        "name": "Transferred Bytes",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "How many bytes the LwM2M server has transferred to the client by write package resource (0)"
      },
      {
        "id": 26501,
        "name": "Switch System Status",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The client switch its system status so that it could receive the firmware package from the LwM2M server"
      }
    ]
  },
  {
    "name": "Location",
    "id": 6,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M Objects provide a range of device related information which can be queried by the LwM2M Server, and a device reboot and factory reset function.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Latitude",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Deg",
        "description": "The decimal notation of latitude, e.g., -43.5723 [World Geodetic System 1984]."
      },
      {
        "id": 1,
        "name": "Longitude",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Deg",
        "description": "The decimal notation of longitude, e.g., 153.21760 [World Geodetic System 1984]."
      },
      {
        "id": 2,
        "name": "Altitude",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "m",
        "description": "The decimal notation of altitude in meters above sea level."
      },
      {
        "id": 3,
        "name": "Radius",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "m",
        "description": "The value in the Radius Resource indicates the size in meters of a circular area around a point of geometry."
      },
      {
        "id": 4,
        "name": "Velocity",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "The velocity in the LwM2M Client is defined in [3GPP-TS_23.032]."
      },
      {
        "id": 5,
        "name": "Timestamp",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "time",
        "range": "",
        "units": "",
        "description": "The timestamp of when the location measurement was performed."
      },
      {
        "id": 6,
        "name": "Speed",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Meters per second",
        "description": "Speed is the time rate of change in position of a LwM2M Client without regard for direction: the scalar component of velocity."
      }
    ]
  },
  {
    "name": "Connectivity Statistics",
    "id": 7,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M Objects enables client to collect statistical information and enables the LwM2M Server to retrieve these information, set the collection duration and reset the statistical parameters.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "SMS Tx Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Indicate the total number of SMS successfully transmitted during the collection period."
      },
      {
        "id": 1,
        "name": "SMS Rx Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Indicate the total number of SMS successfully received during the collection period."
      },
      {
        "id": 2,
        "name": "Tx Data",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "Kilo-Bytes",
        "description": "Indicate the total amount of IP data transmitted during the collection period."
      },
      {
        "id": 3,
        "name": "Rx Data",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "Kilo-Bytes",
        "description": "Indicate the total amount of IP data received during the collection period."
      },
      {
        "id": 4,
        "name": "Max Message Size",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "Byte",
        "description": "The maximum IP message size that is used during the collection period."
      },
      {
        "id": 5,
        "name": "Average Message Size",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "Byte",
        "description": "The average IP message size that is used during the collection period."
      },
      {
        "id": 6,
        "name": "Start",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Reset resources 0-5 to 0 and start to collect information, If resource 8 (Collection Period) value is 0, the client will keep collecting information until resource 7 (Stop) is executed, otherwise the client will stop collecting information after specified period ended.\n        Note:When reporting the Tx Data or Rx Data, the LwM2M Client reports the total KB transmitted/received over IP bearer(s), including all protocol header bytes up to and including the IP header. This does not include lower level retransmissions/optimizations (e.g. RAN, header compression) or SMS messages."
      },
      {
        "id": 7,
        "name": "Stop",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Stop collecting information, but do not reset resources 0-5."
      },
      {
        "id": 8,
        "name": "Collection Period",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "Seconds",
        "description": "The default collection period in seconds. The value 0 indicates that the collection period is not set."
      }
    ]
  },
  {
    "name": "Lock and Wipe",
    "id": 8,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M objects provides the resources needed to perform the lock and wipe operations.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "State",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-2",
        "units": "",
        "description": "State of the device:\n0: unlocked state Normal operation.\n1: partially locked state\nTo render the device inoperable the device has been partially locked. The “lock target” resource allows specifying the target(s) for this operation.\n2: fully locked state\nTo render the device fully inoperable the device has been fully locked."
      },
      {
        "id": 1,
        "name": "Lock target",
        "operations": "W",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "To specify one or several targets for the lock operation. This allows partially locking the device by selecting specific components or interfaces to be locked."
      },
      {
        "id": 2,
        "name": "Wipe item",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Indicates which data can be wiped from the device. This resource could be e.g. representing a directory."
      },
      {
        "id": 3,
        "name": "Wipe",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "To permanently erase data from the device."
      },
      {
        "id": 4,
        "name": "Wipe target",
        "operations": "W",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "To specify one or several targets for the wipe operation. This allows selecting specific data, or, memory areas for the wipe operation."
      },
      {
        "id": 5,
        "name": "Lock or Wipe Operation Result",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-8",
        "units": "",
        "description": "Contains the result of a lock and wipe operation\n0: Default\n1: Partially Lock operation successful\n2: Fully Lock operation successful\n3: Unlock operation successful\n4: Wipe operation successful\n5: Partially Lock operation failed\n6: Fully Lock operation failed\n7: Unlock operation failed 8: Wipe operation failed\nThis Resource MAY be reported by sending Observe operation."
      }
    ]
  },
  {
    "name": "LwM2M Software Management",
    "id": 9,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This LwM2M objects provides the resources needed to perform software management on the device. Each software component is managed via a dedicated Software Management Object instance.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "PkgName",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Name of the software package"
      },
      {
        "id": 1,
        "name": "PkgVersion",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Version of the software package"
      },
      {
        "id": 2,
        "name": "Package",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Software package\nThe package can be in one single software component, or any delivery material used by the Device to determine the software component(s) and proceed to their installation.\nCan be archive file, executable, manifest. This resource to be used when it is single block of delivery.\n"
      },
      {
        "id": 3,
        "name": "Package URI",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "URI from where the device can download the software package by an alternative mechanism. As soon the device has received the Package URI it performs the download at the next practical opportunity.\nCan be direct link to a single software component or link to archive file, executable, or manifest, used by the Device to determine, then access to the software component(s). This resource to be used when it is single block of delivery.\n"
      },
      {
        "id": 4,
        "name": "Install",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Installs software from the package either stored in Package resource, or, downloaded from the Package URI. This Resource is only executable when the value of the State Resource is DELIVERED."
      },
      {
        "id": 5,
        "name": "Checkpoint",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Link to a Checkpoint“ object which allows to specify conditions/dependencies for a software update. E.g. power connected, sufficient memory, target system."
      },
      {
        "id": 6,
        "name": "Uninstall",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Uninstalls the software package.\nThis executable resource may have one argument.\nIf used with no argument or argument is 0, the Package is removed i from the Device. If the argument is 1 (“ForUpdate”), the Client MUST prepare itself for receiving a Package used to upgrade the Software already in place. Update State is set back to INITIAL state.\n"
      },
      {
        "id": 7,
        "name": "Update State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-4",
        "units": "",
        "description": "Indicates current state with respect to this software update. This value is set by the LwM2M Client.\n0: INITIAL\nBefore downloading.\n(see 5.1.2.1)\n1: DOWNLOAD STARTED\nThe downloading process has started and is on-going.\n(see 5.1.2.2)\n2: DOWNLOADED\nThe package has been completely downloaded \n(see 5.1.2.3)\n3: DELIVERED\nIn that state, the package has been correctly downloaded and is ready to be installed. \n(see 5.1.2.4)\nIf executing the Install Resource failed, the state remains at DELIVERED.\nIf executing the Install Resource was successful, the state changes from DELIVERED to INSTALLED.\nAfter executing the UnInstall Resource, the state changes to INITIAL.\n4: INSTALLED\nIn that state the software is correctly installed and can be activated or deactivated according to the Activation State Machine.\n(see 5.1.2.5)\n"
      },
      {
        "id": 8,
        "name": "Update Supported Objects",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "If this value is true, the LwM2M Client MUST inform the registered LwM2M Servers of Objects and Object Instances parameter by sending an Update or Registration message after the software update operation at the next practical opportunity if supported Objects in the LwM2M Client have changed, in order for the LwM2M Servers to promptly manage newly installed Objects. \nIf false, Objects and Object Instances parameter MUST be reported at the next periodic Update message.\nThe default value is false.\n"
      },
      {
        "id": 9,
        "name": "Update Result",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-200",
        "units": "",
        "description": "Contains the result of downloading or installing/uninstalling the software\n0: Initial value. Prior to download any new package in the Device, Update Result MUST be reset to this initial value. One side effect of executing the Uninstall resource is to reset Update Result to this initial value “0”.\n1: Downloading. The package downloading process is on-going.\n2: Software successfully installed.\n3: Successfully Downloaded and package integrity verified\n(( 4-49, for expansion, of other scenarios))\n50: Not enough storage for the new software package.\n51: Out of memory during downloading process.\n52: Connection lost during downloading process.\n53: Package integrity check failure.\n54: Unsupported package type.\n56: Invalid URI\n57: Device defined update error\n58: Software installation failure\n59: Uninstallation Failure during forUpdate(arg\u003d0)\n60-200 : (for expansion, selection to be in blocks depending on new introduction of features)\nThis Resource MAY be reported by sending Observe operation.\n"
      },
      {
        "id": 10,
        "name": "Activate",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "This action activates the software previously successfully installed (the Package Installation State Machine is currently in the INSTALLED state)"
      },
      {
        "id": 11,
        "name": "Deactivate",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "This action deactivates softwareif the Package Installation State Machine is currently in the INSTALLED state."
      },
      {
        "id": 12,
        "name": "Activation State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates the current activation state of this software:\n0: DISABLED\nActivation State is DISABLED if the Software Activation State Machine is in the INACTIVE state or not alive.\n1: ENABLED\nActivation State is ENABLED only if the Software Activation State Machine is in the ACTIVE state\n"
      },
      {
        "id": 13,
        "name": "Package Settings",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Link to “Package Settings” object which allows to modify at any time software configuration settings. This is an application specific object. \nNote: OMA might provide a template for a Package Settings object in a future release of this specification.\n"
      },
      {
        "id": 14,
        "name": "User Name",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "User Name for access to SW Update Package in pull mode.\nKey based mechanism can alternatively use for talking to the component server instead of user name and password combination.\n"
      },
      {
        "id": 15,
        "name": "Password",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Password for access to SW Update Package in pull mode."
      }
    ]
  },
  {
    "name": "Cellular connectivity",
    "id": 10,
    "instancetype": "single",
    "mandatory": false,
    "description": "This object specifies resources to enable a device to connect to a 3GPP or 3GPP2 bearer, including GPRS/EDGE, UMTS, LTE, NB-IoT, SMS. For cellular connectivity, this object focuses on Packet Switched (PS) connectivity and doesn’t aim to provide comprehensive Circuit Switched (CS) connectivity management.\n",
    "resourcedefs": [
      {
        "id": 0,
        "name": "SMSC address",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "E.164 address of SMSC.   \nApplicable for 3GPP2 networks where SMSC is not available from a smart card, or for 3GPP/3GPP2 networks to provide the application with a customer specific SMSC.  The application decides how to use this parameter, e.g. precedence over UICC based SMSC address."
      },
      {
        "id": 1,
        "name": "Disable radio period",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-65535",
        "units": "minutes",
        "description": "Time period for which the device shall disconnect from cellular radio (PS detach, CS detach if applicable).\nCan be used to handle network overload situations. \nThe value is a positive integer (0 to 65535), duration can be from 1 minute to 65535 minutes (approximately 45 days).\nAs soon the server writes a value which is \u003e0 the device SHALL disconnect. When the period has elapsed the device MAY reconnect."
      },
      {
        "id": 2,
        "name": "Module activation code",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Configurable in case the application needs to issue a code (e.g. via AT command) to activate the module. e.g. “*98”."
      },
      {
        "id": 3,
        "name": "Vendor specific extensions",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Links to a vendor specific object."
      },
      {
        "id": 4,
        "name": "PSM Timer (1)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "10min-992 days",
        "units": "s",
        "description": "Power saving mode (PSM) timer as defined in [3GPP-TS_23.682].\nPSM Timer \u003d Extended T3412.\nMax interval between periodic TAU if there is no other transmission from the device. During most of this time the device is considered as unreachable and can therefore go into a deep sleep mode while keeping the PDN connection(s) active."
      },
      {
        "id": 5,
        "name": "Active Timer (1)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "2sec-31 min",
        "units": "s",
        "description": "Active timer \u003d T3324 as defined in [3GPP-TS_24.008].\nThe time the UE has to remain reachable after transitioning to idle state in case there is pending data from the NW to send out. At the end of T3324 UE can go into a deep sleep mode while keeping the PDN connection(s) active."
      },
      {
        "id": 6,
        "name": "Serving PLMN Rate control",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Only for when using Signalling Radio Bearers (c.f. Data over NAS), it indicates the maximum the number of allowed uplink PDU transmissions per 6 minute interval aggregated across all PDN connections. See [3GPP-TS_23.401], octet 3 to 4 of the Serving PLMN rate control IE."
      },
      {
        "id": 7,
        "name": "eDRX parameters for Iu mode (1)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "8 bits",
        "units": "",
        "description": "Extended DRX parameters (Paging Time Window and eDRX value) for Iu mode which the UE can request from the network. This resource is encoded as octet 3 in [3GPP-TS_24.008, clause 10.5.5.32]."
      },
      {
        "id": 8,
        "name": "eDRX parameters for WB-S1 mode (1)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "8 bits",
        "units": "",
        "description": "Extended DRX parameters (Paging Time Window and eDRX value) for WB-S1 mode which the UE can request from the network. This resource is encoded as octet 3 in [3GPP-TS_24.008, clause 10.5.5.32]."
      },
      {
        "id": 9,
        "name": "eDRX parameters for NB-S1 mode (1)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "8 bits",
        "units": "",
        "description": "Extended DRX parameters (Paging Time Window and eDRX value) for NB-S1 mode which the UE can request from the network. This resource is encoded as octet 3 in [3GPP-TS_24.008, clause 10.5.5.32]."
      },
      {
        "id": 10,
        "name": "eDRX parameters for A/Gb mode (1)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "8 bits",
        "units": "",
        "description": "Extended DRX parameters (Paging Time Window and eDRX value) for A/Gb mode which the UE can request from the network. This resource is encoded as octet 3 in [3GPP-TS_24.008, clause 10.5.5.32]."
      },
      {
        "id": 11,
        "name": "Activated Profile Names",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Links to instances of the “APN connection profile” object representing every APN connection profile that has an activated connection to a PDN."
      }
    ]
  },
  {
    "name": "APN connection profile",
    "id": 11,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This object specifies resources to enable a device to connect to an APN.\n",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Profile name",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Human-readable identifier. Multiple connection profiles can share the same APN value but e.g. have different credentials."
      },
      {
        "id": 1,
        "name": "APN",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Presented to network during connection to PDN e.g. ‘internet.15.234’.\nThis resource is not included in case ‘Auto select APN by device’ resource has the value TRUE.\nIf the APN resource is present but contains an empty string, then the device shall not provide an APN in the connection request (invoking default APN procedures in the network)."
      },
      {
        "id": 2,
        "name": "Auto select APN by device",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "If this resource is present for a connection profile, it enables the device to choose an APN according to a device specific algorithm. It provides a fall-back mechanism e.g. for some MVNO SIMs the configured APN may not work.  Resource not included in case the ‘APN’ resource is specified."
      },
      {
        "id": 3,
        "name": "Enable status",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "True: connection is activated\nFalse: connection is de-activated.\nAllows the profile to be remotely activated or deactivated."
      },
      {
        "id": 4,
        "name": "Authentication Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Enumerated type:\n0: PAP\n1: CHAP\n2: PAP or CHAP\n3: None"
      },
      {
        "id": 5,
        "name": "User Name",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Used with e.g. PAP."
      },
      {
        "id": 6,
        "name": "Secret",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Used with e.g. PAP."
      },
      {
        "id": 7,
        "name": "Reconnect Schedule",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Comma separated list of retry delay values in seconds to be used in case of unsuccessful connection establishment attempts. e.g. “10,60,600,3600,86400”"
      },
      {
        "id": 8,
        "name": "Validity (MCC, MNC)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Coma separated mobile country code, then mobile network code – for which this APN is valid."
      },
      {
        "id": 9,
        "name": "Connection establishment time (1)",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "time",
        "range": "",
        "units": "",
        "description": "UTC time of connection request. See note (1)"
      },
      {
        "id": 10,
        "name": "Connection establishment result (1)",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0 \u003d accepted\n1 \u003d rejected\n"
      },
      {
        "id": 11,
        "name": "Connection establishment reject cause (1)",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "0-111",
        "units": "",
        "description": "Reject cause, see [3GPP-TS_24.008, 3GPP-TS_24.301]"
      },
      {
        "id": 12,
        "name": "Connection end time (1)",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "time",
        "range": "",
        "units": "",
        "description": "UTC time of connection end."
      },
      {
        "id": 13,
        "name": "TotalBytesSent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Rolling counter for total number of bytes sent via this interface since last device reset."
      },
      {
        "id": 14,
        "name": "TotalBytesReceived",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Rolling counter for total number of bytes received via this interface since last device reset."
      },
      {
        "id": 15,
        "name": "IP address (2)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "May be IPv4 or IPv6 address."
      },
      {
        "id": 16,
        "name": "Prefix length(2)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Associated with IPv6 address."
      },
      {
        "id": 17,
        "name": "Subnet mask (2)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Subnet mask."
      },
      {
        "id": 18,
        "name": "Gateway (2)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Gateway."
      },
      {
        "id": 19,
        "name": "Primary DNS address (2)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Primary DNS address."
      },
      {
        "id": 20,
        "name": "Secondary DNS address (2)",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Secondary DNS address."
      },
      {
        "id": 21,
        "name": "QCI (3)",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "1-9",
        "units": "",
        "description": "For LTE and NB-IoT only\nQCI\u003dQuality of service Class Identifier\nThis resource enables the LwM2M server to signal the LwM2M client which QCI it shall request from the network.\nSee [3GPP-TS_23.203, and 3GPP-TS_24.301] for a description of QCI values. See note (3)."
      },
      {
        "id": 22,
        "name": "Vendor specific extensions",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Links to a vendor specific object."
      },
      {
        "id": 23,
        "name": "TotalPacketsSent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Rolling counter for total number of packets sent via this interface since last device reset."
      },
      {
        "id": 24,
        "name": "PDN Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0\u003dNon-IP\n1\u003dIPv4\n2\u003dIPv6\n3\u003dIPv4v6"
      },
      {
        "id": 25,
        "name": "APN Rate Control",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Determines the number of allowed uplink PDU transmissions per time interval per APN.\nRate Control information is part of the Protocol Configuration Options (PCO) according to [3GPP-TS_24.008 and 3GPP-TS_27.060]\n"
      }
    ]
  },
  {
    "name": "WLAN connectivity",
    "id": 12,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This object specifies resources to enable a device to connect to a WLAN bearer.\n",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Interface name",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Human-readable identifier\neg. wlan0"
      },
      {
        "id": 1,
        "name": "Enable",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: Disabled\n1: Enabled\nEnable / Disable interface\nWhen disabled radio must also be disabled"
      },
      {
        "id": 2,
        "name": "Radio Enabled",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0: Disabled\n1: 2.4 GHz\n2: 5 GHz\n3: 0.9 GHz\n4: 3.7 GHz\n5: 45 GHz\n6: 60 GHz"
      },
      {
        "id": 3,
        "name": "Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0: Disabled\n1: UP (OK)\n2: Error"
      },
      {
        "id": 4,
        "name": "BSSID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "12 bytes ",
        "units": "",
        "description": "The MAC address of the interface, in hexadecimal form."
      },
      {
        "id": 5,
        "name": "SSID",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "1-32 Bytes",
        "units": "",
        "description": "The Service Set Identifier for this interface."
      },
      {
        "id": 6,
        "name": "Broadcast SSID",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: Do not broadcast SSID\n1: Broadcast SSID\n"
      },
      {
        "id": 7,
        "name": "Beacon Enabled",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: Do not broadcast beacons\n1: Broadcast beacons"
      },
      {
        "id": 8,
        "name": "Mode",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0: Access Point\n1: Client (Station)\n2: Bridge\n3: Repeater"
      },
      {
        "id": 9,
        "name": "Channel",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-255",
        "units": "",
        "description": "The current radio channel in use by this interface.\n0: Disabled\n1: Enabled\n"
      },
      {
        "id": 10,
        "name": "Auto Channel",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: Disabled\n1: Enabled"
      },
      {
        "id": 11,
        "name": "Supported Channels",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Array of supported radio channels."
      },
      {
        "id": 12,
        "name": "Channels In Use",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Array of channels which the access point has determined are ‘in use’.\nIncluding any channels in-use by access point itself."
      },
      {
        "id": 13,
        "name": "Regulatory Domain",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "3 Bytes",
        "units": "",
        "description": "802.11d Regulatory Domain String. \nFirst two octets are ISO/IEC 3166-1 two-character country code. \nThe third octet is either “ ” (all environments), “O” (outside) or “I” (inside)."
      },
      {
        "id": 14,
        "name": "Standard",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0: 802.11a\n1: 802.11b\n2: 802.11bg \n3: 802.11g\n4: 802.11n\n5: 802.11bgn\n6: 802.11ac\n7: 802.11ah"
      },
      {
        "id": 15,
        "name": "Authentication Mode",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0: None (Open)\n1: PSK\n2: EAP\n3: EAP+PSK\n4: EAPSIM"
      },
      {
        "id": 16,
        "name": "Encryption Mode",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "0: AES (WPA2)\n1: TKIP (WPA)\n2: WEP (1)"
      },
      {
        "id": 17,
        "name": "WPA Pre Shared Key",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "64 Bytes",
        "units": "",
        "description": "WPA/WPA2 Key expressed as a hex string.\nWrite – Only."
      },
      {
        "id": 18,
        "name": "WPA Key Phrase",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "1-64 Bytes",
        "units": "",
        "description": "WPA/WPA2 Key Phrase.\nWrite Only."
      },
      {
        "id": 19,
        "name": "WEP Encryption Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Description.0: None\n1: 40-bit\n2: 104-bit"
      },
      {
        "id": 20,
        "name": "WEP Key Index",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "[1:4]",
        "units": "",
        "description": "Index of the default WEP key."
      },
      {
        "id": 21,
        "name": "WEP Key Phrase",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "1-64 Bytes",
        "units": "",
        "description": "WPA/WPA2 Key Phrase.\nWrite Only."
      },
      {
        "id": 22,
        "name": "WEP Key 1",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0 or 26 Bytes",
        "units": "",
        "description": "WEP Key 1 expressed as a hexadecimal string.\n10 Bytes for a 40 Bit key\n26 Bytes for a 104 Bit key"
      },
      {
        "id": 23,
        "name": "WEP Key 2",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0 or 26 Bytes",
        "units": "",
        "description": "WEP Key 2 expressed as a hexadecimal string.\n10 Bytes for a 40 Bit key\n26 Bytes for a 104 Bit key"
      },
      {
        "id": 24,
        "name": "WEP Key 3",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "10 or 26 Bytes",
        "units": "",
        "description": "WEP Key 3 expressed as a hexadecimal string.\n10 Bytes for a 40 Bit key\n26 Bytes for a 104 Bit key"
      },
      {
        "id": 25,
        "name": "WEP Key 4",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "10 or 26 Bytes",
        "units": "",
        "description": "WEP Key 4 expressed as a hexadecimal string.\n10 Bytes for a 40 Bit key\n26 Bytes for a 104 Bit key"
      },
      {
        "id": 26,
        "name": "RADIUS Server",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "1-256 Bytes",
        "units": "",
        "description": "RADIUS Authentication Server Address"
      },
      {
        "id": 27,
        "name": "RADIUS Server Port",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "RADIUS Authentication Server Port Number"
      },
      {
        "id": 28,
        "name": "RADIUS Secret",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "1-256 Bytes",
        "units": "",
        "description": "RADIUS Shared Secret"
      },
      {
        "id": 29,
        "name": "WMM Supported",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: WMM NOT Supported\n1: WMM Wupported"
      },
      {
        "id": 30,
        "name": "WMM Enabled",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: Disabled\n1: Enabled"
      },
      {
        "id": 31,
        "name": "MAC Control Enabled",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0: Any Client MAC Address accepted\n1: Client MAC address must exist in MACAddressList"
      },
      {
        "id": 32,
        "name": "MAC Address List",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "12 Bytes ",
        "units": "",
        "description": "Array of allowed client MAC addresses, in hexadecimal form."
      },
      {
        "id": 33,
        "name": "Total Bytes Sent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total number of bytes sent via this interface"
      },
      {
        "id": 34,
        "name": "Total Bytes Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total number of bytes received via this interface"
      },
      {
        "id": 35,
        "name": "Total Packets Sent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total packets sent via this interface"
      },
      {
        "id": 36,
        "name": "Total Packets Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total packets received via this interface"
      },
      {
        "id": 37,
        "name": "Transmit Errors",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total number of packets which could not be transmitted because of errors."
      },
      {
        "id": 38,
        "name": "Receive Errors",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Total number of packets received with errors which prevented those packets from being delivered."
      },
      {
        "id": 39,
        "name": "Unicast Packets Sent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Unicast Packets Sent"
      },
      {
        "id": 40,
        "name": "Unicast Packets Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Unicast Packets Received"
      },
      {
        "id": 41,
        "name": "Multicast Packets  Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Multicast Packets Sent"
      },
      {
        "id": 42,
        "name": "Multicast Packets  Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Multicast Packets Received"
      },
      {
        "id": 43,
        "name": "Broadcast Packets Sent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Broadcast Packets Sent"
      },
      {
        "id": 44,
        "name": "44 Broadcast Packets Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Broadcast Packets Received"
      },
      {
        "id": 45,
        "name": "Discard Packets Sent",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of valid outbound packets intentionally discarded without transmission, for example a packet may be discarded to manage buffer space."
      },
      {
        "id": 46,
        "name": "Discard Packets Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of valid packets received and intentionally discarded without delivery to the system, for example a packet may be discarded to manage buffer space."
      },
      {
        "id": 47,
        "name": "Unknown Packets Received",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Count of Unknown Packets Received"
      },
      {
        "id": 48,
        "name": "Vendor specific extensions",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Links to a vendor specific object."
      }
    ]
  },
  {
    "name": "Bearer selection",
    "id": 13,
    "instancetype": "single",
    "mandatory": false,
    "description": "This object specifies resources to enable a device to choose a PLMN/network on which to attach/register and what type of bearer to then connect. \nThis object allows via remote bearer and network configuration to overwrite automatic network and bearer selection e.g. as supported by the UICC. An equivalent example for overwriting automatic selection is a user doing manual network and bearer selection on a smart phone.\n",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Preferred Communications Bearer",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "8-bit",
        "units": "",
        "description": "Used in network selection and, if applicable, in subsequent mobility management procedures:\n0: auto connect\n1: 3GPP PS preferred\n2: 3GPP PS GSM (GPRS) preferred (including EC-GSM-IoT)\n3: 3GPP PS UMTS preferred\n4: 3GPP PS LTE preferred\n5: 1xEV-DO preferred (1)\n6: 3GPP CS preferred (1)\n7: WLAN preferred\n8: Ethernet preferred (1)\n9: DSL preferred (1)\n10: Bluetooth preferred (1)\n11: WIMAX preferred (1)\n12: 3GPP PS LTE with CIoT EPS optimisations, User Plane preferred (2)\n13: 3GPP PS LTE with CIoT EPS optimisations, Control Plane preferred (2)14: 3GPP PS NB-IoT Control Plane optimisations preferred (2)\n15: 3GPP PS NB-IoT User Plane optimisations preferred (2) \n16-100: Reserved for future use\nThe Preferred Communications Bearer resource specifies the preferred communications bearer that the LwM2M Client is requested to use for connecting to the LwM2M Server. If multiple preferred communications bearers are specified, the priority order is reflected by the resource instance order. E.g. the bearer which appears first in the list of resource instances is to have higher priority over the rest of available bearers. The LwM2M Client SHOULD use the preferred bearers with higher priority first if they are available. If none of indicated preferred bearers is available, the LwM2M Client SHOULD wait until one of them becomes available. "
      },
      {
        "id": 1,
        "name": "Acceptable RSSI (GSM)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Provides guide to the application when performing manual network selection."
      },
      {
        "id": 2,
        "name": "Acceptable RSCP (UMTS)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Provides guide to the application when performing manual network selection."
      },
      {
        "id": 3,
        "name": "Acceptable RSRP (LTE)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Provides guide to the application when performing manual network selection."
      },
      {
        "id": 4,
        "name": "Acceptable RSSI (1xEV-DO)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Provides guide to the application when performing manual network selection."
      },
      {
        "id": 5,
        "name": "Cell lock list",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Comma separated list of allowed Global Cell Identities."
      },
      {
        "id": 6,
        "name": "Operator list",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Comma separated list of MCC+MNC of operators, in priority order.\nResource “operator list mode” indicates how to process this list."
      },
      {
        "id": 7,
        "name": "Operator list mode",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether resource “operator list” represents the allowed operator list (white list), or, the preferred operator list.\n0\u003dpreferred\n1\u003dallowed"
      },
      {
        "id": 8,
        "name": "List of available PLMNs",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Allows server to see results of network scan (e.g. result of AT+COPS\u003d?)"
      },
      {
        "id": 9,
        "name": "Vendor specific extensions",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Links to a vendor specific object."
      },
      {
        "id": 10,
        "name": "Acceptable RSRP (NB-IoT)",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Provides guide to the application when performing manual network selection."
      },
      {
        "id": 11,
        "name": "Higher Priority PLMN Search Timer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Interval between periodic searches for higher priority PLMNs of the same country when camped on a visited PLMN, i.e. roaming scenario; based on SIM configuration, EFHPPLMN [3GPP-TS_31.102, section 4.2.6]"
      },
      {
        "id": 12,
        "name": "Attach without PDN connection",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "0\u003dattach with PDN connection\n1\u003dattach without PDN connection\n"
      }
    ]
  },
  {
    "name": "LwM2M Software Component",
    "id": 14,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "If some Objects are not supported after software update, the LwM2M Client MUST delete all the Object Instances of the Objects that are not supported.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Component Identity",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Name or identifier of the software component"
      },
      {
        "id": 1,
        "name": "Component Pack",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Software components is stored in this resource"
      },
      {
        "id": 2,
        "name": "Component Version",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-255 bytes",
        "units": "",
        "description": "Version of the software component."
      },
      {
        "id": 3,
        "name": "Activate",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "This action activates the software previously successfully installed (the SW Update Package Installation State Machine is currently in the INSTALLED state)."
      },
      {
        "id": 4,
        "name": "Deactivate",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "This action deactivates software if the SW Update Package Installation State Machine is currently in the INSTALLED state."
      },
      {
        "id": 5,
        "name": "Activation State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates the current activation state of this software component:\n0: DISABLED\nActivation State is DISABLED if the Software Component Activation State Machine is in the INACTIVE state or not alive.\n1: ENABLED\nActivation State is ENABLED only if the Software Component Activation State Machine is in the ACTIVE state.\n"
      }
    ]
  },
  {
    "name": "DevCapMgmt",
    "id": 15,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This LwM2M Object is dedicated to manage the device capabilities of a device e.g. sensors, communication, etc.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Property",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "List of Device Capabilities inside a given Group.\nThe format is a free list ASCII-represented integers separated by a semi colon. (e.g. 0;1;10)\nThe list of capabilities per Group is given in Appendix B: Device Capabilities Vocabulary\nexecutable Resource can work with.\n"
      },
      {
        "id": 1,
        "name": "Group",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-15",
        "units": "",
        "description": "Group name of Device Capabilities\n0: SENSOR: luminosity, presence,temp,humidity\n1: CONTROL: Light, Power, Sound\n2: CONNECTIVITY: Bluetooth, wifi, …\n3: NAVIGATION: gps, galieo\n4: STORAGE: external memory,\n5: VISION: cam, video-cam, night_cam.\n6: SOUND: speaker, buzzer\n7: ANALOG_INPUT: generic input\n8: ANALOG_OUTPUT: generic output\n9-15: reserved\n\n"
      },
      {
        "id": 2,
        "name": "Description",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Device Capability Description\n(manufacturer specified string)\n"
      },
      {
        "id": 3,
        "name": "Attached",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "When the resource doesn’t exist, it means the associated Device Capability is not removable.\nWhen this resource is “False”, it means the associated Device Capability is removable and is currently not attached to the device.\nWhen this resource is “True”, it means the associated Device Capability – if removable – is currently attached to the Device.\nWhen a Device Capability is not removable, and the “Attached” Resource is present, the “Attached” value but be set to “True”.\n"
      },
      {
        "id": 4,
        "name": "Enabled",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "This resource indicates whether the Device Capability is enabled regardless whether the Device Capability is attached or not. If the value of this resource is “True” the Device Capability is in Enabled State. If the value is “False” the Device Capability is in Disabled State;\nThe ‘Attached’ and ‘Enabled’ resources are independent. A Device Capability MAY have ‘True’ as value for ‘Enabled’ Resource while having ‘False’ as value for the ‘Attached’ Resource. That means the Device Capability is still not available and can’t be used until it is attached to the Device, but will be useable once the Device Capability is attached.\n"
      },
      {
        "id": 5,
        "name": "opEnable",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "This command is used to enable the Device Capability to transfer the Device Capability from Disabled State to Enabled state.\nIn Enabled State, the Device Capability is allowed to work when it is attached to the Device.\n"
      },
      {
        "id": 6,
        "name": "opDisable",
        "operations": "E",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "This command is used to disable the Device Capability to transfer the Device Capability from Enabled State to Disabled State.\nIn Disabled state the Device Capability is not allowed to work.\n"
      },
      {
        "id": 7,
        "name": "NotifyEn",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "When the Resources “Enabled” or “Attached” are under “Observation”, this resource specifies whether the LwM2M Server MUST be notified when the value of the Resource on “Observation” changed. If the Resource “NotifyEn” is not present or the value is ‘False’, the LwM2M Server will be not notified about this change. If the “NotifyEn” Resource is present and the value is ‘True’, the LwM2M Server will be notified."
      }
    ]
  },
  {
    "name": "Communication Characteristics",
    "id": 17,
    "instancetype": "single",
    "mandatory": false,
    "description": "This object enables configuration of various generic communications parameters.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Maximum uplink packet size",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "octets",
        "description": "Maximum uplink packet size supported by the communications channel.\n\nIn case of 3GPP NB-IoT this applies to the maximum uplink packet size supported via the Non Access Stratum (NAS). This information can be retrieved via the Protocol Configuration Options as defined in 3GPP TS 24.008. \n"
      },
      {
        "id": 1,
        "name": "Maximum downlink packet size",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "octets",
        "description": "Maximum downlink packet size supported by the communications channel, and supported by the device buffer."
      },
      {
        "id": 2,
        "name": "CoAP ACK_TIMEOUT",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "See [RFC 7252 CoAP]"
      },
      {
        "id": 3,
        "name": "CoAP ACK_RANDOM_FACTOR",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "See [RFC 7252 CoAP]"
      },
      {
        "id": 4,
        "name": "CoAP MAX_RETRANSMIT",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "See [RFC 7252 CoAP]"
      },
      {
        "id": 5,
        "name": "CoAP NSTART",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "See [RFC 7252 CoAP]"
      },
      {
        "id": 6,
        "name": "CoAP DEFAULT_LEISURE",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "See [RFC 7252 CoAP]"
      },
      {
        "id": 7,
        "name": "CoAP PROBING_RATE",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "See [RFC 7252 CoAP]"
      }
    ]
  },
  {
    "name": "Non-Access Stratum (NAS) configuration ",
    "id": 18,
    "instancetype": "single",
    "mandatory": false,
    "description": "This object provides Non-Access Stratum (NAS) configuration and is derived from 3GPP TS 24.368.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "NAS_SignallingPriority",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-255",
        "units": "",
        "description": "Indicates a NAS signalling priority which is used to determine the setting of the low priority indicator to be included in NAS messages as specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5].\n\n0\u003dreserved\n1\u003dNAS signalling low priority\n2-255\u003dreserved"
      },
      {
        "id": 1,
        "name": "AttachWithIMSI",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether attach with IMSI is performed when moving to a non-equivalent PLMN as specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5].\n0\tIndicates that normal behaviour is applied.\n1\tIndicates that attach with IMSI is performed when moving to a non-equivalent PLMN.\n\n"
      },
      {
        "id": 2,
        "name": "MinimumPeriodicSearchTimer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-255",
        "units": "",
        "description": "Gives a minimum value in minutes for the timer T controlling the periodic search for higher prioritized PLMNs as specified in 3GPP TS 23.122 [3].\n"
      },
      {
        "id": 3,
        "name": "NMO_I_Behaviour",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the \"NMO I, Network Mode of Operation I\" indication as specified in 3GPP TS 24.008 [4] is applied by the UE.\n0\tIndicates that the \"NMO I, Network Mode of Operation I\" indication is not used.\n1\tIndicates that the \"NMO I, Network Mode of Operation I\" indication is used, if available.\n"
      },
      {
        "id": 4,
        "name": "Timer_T3245_Behaviour",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the timer T3245 and the related functionality as specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5] is used by the UE.\n0\tIndicates that the timer T3245 is not used.\n1\tIndicates that the timer T3245 is used.\n"
      },
      {
        "id": 5,
        "name": "ExtendedAccessBarring",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the extended access barring is applicable for the UE as specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5].\n0\tIndicates that the extended access barring is not applied for the UE.\n1\tIndicates that the extended access barring is applied for the UE.\n"
      },
      {
        "id": 6,
        "name": "Override_NAS_SignallingLowPriority",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the UE can override the NAS_SignallingPriority leaf node configured to NAS signalling low priority.\nThe setting of the low priority indicator included in NAS messages when this resource exists is specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5].\n0\tIndicates that the UE cannot override the NAS signalling low priority indicator\n1\tIndicates that the UE can override the NAS signalling low priority indicator\nThe default value 0 applies if this leaf is not provisioned.\nIf provisioned, this resource is set to the same value as that provisioned for the Override_ExtendedAccessBarring leaf, e.g., if the UE is configured to override the NAS signalling low access priority indicator, then UE is also configured to override extended access class barring (see 3GPP TS 23.401 [5A])."
      },
      {
        "id": 7,
        "name": "Override_ExtendedAccessBarring",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the UE can override ExtendedAccessBarring resource configured to extended access barring.\nThe handling of extended access barring for the UE when this resource exists is specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5].\n0\tIndicates that the UE cannot override extended access barring\n1\tIndicates that the UE can override extended access barring\nThe default value 0 applies if this resource is not provisioned.\nIf provisioned, this resource is set to the same value as that provisioned for the Override_NAS_SignallingLowPriority leaf, e.g., if the UE is configured to override the NAS signalling low access priority indicator, then UE is also configured to override extended access class barring (see 3GPP TS 23.401 [5A]).\n"
      },
      {
        "id": 8,
        "name": "FastFirstHigherPriorityPLMNSearch",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the UE performs the first search for a higher priority PLMN after at least 2 minutes and at most T minutes upon entering a VPLMN as specified in 3GPP TS 23.122 [3].\n0\tIndicates that the Fast First Higher Priority PLMN Search is disabled, see 3GPP TS 23.122 [3]\n1\tIndicates that the Fast First Higher Priority PLMN Search is enabled, see 3GPP TS 23.122 [3]\nThe default value 0 applies if this resource is not provisioned.\n"
      },
      {
        "id": 9,
        "name": "EUTRADisablingAllowedForEMMCause15",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates whether the UE is allowed to disable the E-UTRA capability when it receives the Extended EMM cause IE with value \"E-UTRAN not allowed\" as described in 3GPP TS 24.301 [5].\n0\tIndicates that \"E-UTRA Disabling for EMM cause #15\" is disabled, see 3GPP TS 24.301 [5]\n1\tIndicates that \"E-UTRA Disabling for EMM cause #15\" is enabled, see 3GPP TS 24.301 [5]\nThe default value 0 applies if this resource is not provisioned.\n"
      },
      {
        "id": 10,
        "name": "SM_RetryWaitTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-255",
        "units": "",
        "description": "Indicates a configured UE retry wait time value applicable when in HPLMN or EHPLMN (see 3GPP TS 23.122 [3]) for controlling the UE session management retry behaviour when prior session management request was rejected by the network with cause value #8, #27, #32, #33 as specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5]. \nThe default value of 12 minutes applies if this resource is not provisioned.\nThis resource shall be coded in the same format as the value part of GPRS Timer 3 IE as specified in Table 10.5.163a/3GPP TS 24.008 [4] converted into a decimal value.\n"
      },
      {
        "id": 11,
        "name": "SM_RetryAtRATChange",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates the UE\u0027s retry behaviour when in HPLMN or EHPLMN (see 3GPP TS 23.122 [3]) after inter-system change between S1 mode and A/Gb or Iu mode as specified in 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5]. \n0\tIndicates that the UE is allowed to retry the corresponding ESM procedure in S1 mode if an SM procedure was rejected in A/Gb or Iu mode, and to retry the corresponding SM procedure in A/Gb or Iu mode if an ESM procedure was rejected in S1 mode, see 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5]\n1\tIndicates that the UE is not allowed to retry an SM procedure or the corresponding ESM procedure in any of the modes: A/Gb, Iu and S1 mode, see 3GPP TS 24.008 [4] and 3GPP TS 24.301 [5]\nThe default value 0 applies if this resource is not provisioned.\n"
      },
      {
        "id": 12,
        "name": "ExceptionDataReportingAllowed",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "For the UE in NB-S1 mode, this resource indicates whether the UE is allowed to use the RRC establishment cause mo-ExceptionData, as specified in 3GPP TS 24.301 [5].\n0\tIndicates that the UE is not allowed to use the RRC establishment cause mo-ExceptionData.\n1\tIndicates that the UE is allowed to use the RRC establishment cause mo-ExceptionData.\nIf this resource is not provisioned, the value of 0 is used.\n"
      }
    ]
  },
  {
    "name": "CmdhPolicy",
    "id": 2048,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object provides links to a set of rules associated with a specific CSE that governs the behavior of that CSE regarding rejecting, buffering and sending request or response messages via the Mcc reference point.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Name",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Contains the name of a CmdhPolicy Object Instance "
      },
      {
        "id": 1,
        "name": "DefaultRule",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "1 reference to CmdhDefaults Object  Instance"
      },
      {
        "id": 2,
        "name": "LimiRules",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "1 or more references to CmdhLimits Object Instances"
      },
      {
        "id": 3,
        "name": "NetworkAccessECRules",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "1 or more references to CmdhNetworkAccessRules Object Instances"
      },
      {
        "id": 4,
        "name": "BufferRules",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "1 or more references to CmdhBuffer Object Instances"
      }
    ]
  },
  {
    "name": "ActiveCmdhPolicy",
    "id": 2049,
    "instancetype": "single",
    "mandatory": false,
    "description": "This Object provides a link to the currently active set of CMDH policies",
    "resourcedefs": [
      {
        "id": 0,
        "name": "ActiveLink",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Contains the reference to the CMDH policies (CmdhPolicy Object Instance) currently active for the associated CSE."
      }
    ]
  },
  {
    "name": "CmdhDefaults",
    "id": 2050,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Defines which CMDH related parameters will be used by default. ",
    "resourcedefs": [
      {
        "id": 0,
        "name": "DefaultEcRules",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "1 or more references to  CmdhDefEcValue Object Instances containing default values for the ec (event category) parameter of an incoming request or response when this parameter is not indicated in the message itself "
      },
      {
        "id": 1,
        "name": "DefaultEcParamRules",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "1 or more references to CmdhEcDefParamValues Object Instances "
      }
    ]
  },
  {
    "name": "CmdhDefEcValues",
    "id": 2051,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object represents default set of values for the Event Category parameter of an incoming request or response message.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Order",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Contains an index defining the order of processing this CmdhDefEcValue Object Instance will be handled"
      },
      {
        "id": 1,
        "name": "DefEcValue",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Represents the default Event category value to be applied when the conditions given in this Object Instance are matched"
      },
      {
        "id": 2,
        "name": "RequestOrigin",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "List of zero or more Local AE-IDs, App-IDs, or the strings “localAE” or “thisCSE”"
      },
      {
        "id": 3,
        "name": "RequestContext",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Contains the requestContext information of this Object Instance which needs to be matched  "
      },
      {
        "id": 4,
        "name": "RequestContextNotification",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Contains true/false flag indicating whether or not notification procedures apply."
      },
      {
        "id": 5,
        "name": "RequestCharacteristics",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Represents conditions pertaining to the request itself, (e.g. the requested Response Type  ) than needs to be matched"
      }
    ]
  },
  {
    "name": "CmdhEcDefParamValues",
    "id": 2052,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object represents a specific set of default values for the CMDH related parameters Request Expiration Timestamp, Result Expiration Timestamp, Operational Execution Time, Result Persistence and Delivery Aggregation that are applicable for a given Event Category if these parameters are not specified in the message.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "ApplicableEventCategory ",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Contains  list of Event Category values"
      },
      {
        "id": 1,
        "name": "DefaultRequestExpTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Contains the default value for the Request Expiration Timestamp parameter when such a parameter is not set in the request"
      },
      {
        "id": 2,
        "name": "DefaultResultExpTime ",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Contains the default value of the Result  Expiration Timestamp parameter when such a parameter is not set in the request  "
      },
      {
        "id": 3,
        "name": "DefaultOpExecTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Contains the default value of the Operation Execution Time parameter when such a parameter is not set in the request"
      },
      {
        "id": 4,
        "name": "DefaultRespPersistence ",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Contains the default value of the Result  Persistence parameter when such a parameter is not set in the request  "
      },
      {
        "id": 5,
        "name": "DefaultDelAggregation ",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Contains the default value of the Delivery Aggregation  parameter when such a parameter is not set in the request  "
      }
    ]
  },
  {
    "name": "CmdhLimits",
    "id": 2053,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object represents limits for CMDH related parameter values. ",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Order",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Contains index indicating in which order the concerned CmdhLimits Object Instance will be treated by the CSE to determine a value for the limit parameters."
      },
      {
        "id": 1,
        "name": "RequestOrigin",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "List of zero or more Local AE-IDs, App-IDs, or the strings “localAE” or “thisCSE”"
      },
      {
        "id": 2,
        "name": "RequestContext",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Represents the Dynamic Context condition under which CMDH parameter limits defined inside the concerned CmdhLimits Object Instance is applicable."
      },
      {
        "id": 3,
        "name": "RequestContextNotificatio",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Contains true/false flag indicating whether or not notification procedures apply."
      },
      {
        "id": 4,
        "name": "RequestCharacteristics",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Represents conditions pertaining to the request itself, (e.g. the requested Response Type  ) than needs to be matched"
      },
      {
        "id": 5,
        "name": "LimitsEventCategory",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Allowed values for the Event Category parameter in a request of any of the Originators indicated in the requestOrigin attribute."
      },
      {
        "id": 6,
        "name": "LimitsRequestExpTime ",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "2 Instances",
        "units": "ms",
        "description": "Defines a range of values for the Request Expiration Time parameter for a request of any Originator indicated in the requestOrigin Resource\nInst 0 : minTime\nInst 1:  maxTime\n "
      },
      {
        "id": 7,
        "name": "LimitsResultExpTime",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "2 Instances",
        "units": "ms",
        "description": "Defines a range of values for the Result Expiration Time parameter for a request of any Originator indicated in the requestOrigin Resource\nInst 0 : minTime\nInst 1:  maxTime\n"
      },
      {
        "id": 8,
        "name": "LimitsOptExpTime",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "2 Instances",
        "units": "ms",
        "description": "Defines a range of values for the Operation Expiration Time parameter for a request of any Originator indicated in the requestOrigin Resource\nInst 0 : minTime\nInst 1:  maxTime\n"
      },
      {
        "id": 9,
        "name": "LimitsRespPersistence",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "2 Instances",
        "units": "ms",
        "description": "Defines a range of values for the Result Persistence parameter for a request of any Originator indicated in the requestOrigin Resource\nInst 0 : minTime\nInst 1:  maxTime\n"
      },
      {
        "id": 10,
        "name": "LimitsDelAggregation",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Contains the permitted settings of the DeliveryAggregation parameter of request primitives. \n\u00270\u0027 means \u0027False\u0027 \u00271\u0027 means \u0027True\u0027 \u00270 1\u0027 means \u0027False\u0027 or \u0027True\u0027\n"
      }
    ]
  },
  {
    "name": "CmdhNetworkAccessRules",
    "id": 2054,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object defines the usage of underlying networks for forwarding information to other CSEs during processing of CMDH-related requests in a CSE.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "ApplicableEventCategories",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Contains  a list of Event Category values"
      },
      {
        "id": 1,
        "name": "NetworkAccessRule",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Contains 0 or more references to CmdhNwAccessRule Object Instances "
      }
    ]
  },
  {
    "name": "CmdhNwAccessRule",
    "id": 2055,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object defines limits in usage of specific underlying networks for forwarding information to other CSEs during processing of CMDH-related requests in a CSE.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "TargetNetwork",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Contains identifiers of Underlying networks"
      },
      {
        "id": 1,
        "name": "SpreadingWaitTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Contains a value in ms such that before accessing the underlying network (typically to forward an incoming request), the CSE will wait for an additional amount of time randomly chosen between 0 and this value"
      },
      {
        "id": 2,
        "name": "MinReqVolume",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Byte",
        "description": "Minimum amount of data that needs to be aggregated before any of the Underlying Networks matching with the targetNetwork Resource of the current Instance of the  CmdhNwAccessRule Object can be used for forwarding information to other CSEs."
      },
      {
        "id": 3,
        "name": "BackOffParameters",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Reference to an Instance of BackOffParameterSet Object defining parameters that define how usage of any of the Underlying Networks matching with the targetNetwork Resource  of that Object Instance, shall be handled when attempts to use such networks have failed.\n"
      },
      {
        "id": 4,
        "name": "OtherConditions",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "List of additional conditions that need to be fulfilled before any of the Underlying Networks matching with the TargetNetwork Resource of this CmdhNwAccessRule Object Instance can be used for forwarding information to other CSEs. "
      },
      {
        "id": 5,
        "name": "AllowedSchedule",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Contains time schedules in form of extended crontab syntax defined in oneM2M Protocol TS-0004 "
      }
    ]
  },
  {
    "name": "CmdhBuffer",
    "id": 2056,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object defines limits in usage of buffers for temporarily storing information that needs to be forwarded to other CSEs during processing of CMDH-related requests in a CSE.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "ApplicableEventCategory",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Contains a list of event category values"
      },
      {
        "id": 1,
        "name": "MaxBufferSize",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Byte",
        "description": "Contains the max Buffer size of the CmdhBuffer Object Instance "
      },
      {
        "id": 2,
        "name": "StoragePriority",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "1..10",
        "units": "",
        "description": "Storage priority for the buffered data associated to that CmdhBuffer Object Instance. t \nBuffered requests associated with a lower storage priority shall be purged before buffered requests with a higher storage priority.\n"
      }
    ]
  },
  {
    "name": "CmdhBackOffParametersSet",
    "id": 2057,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This Object defines set of parameters which can be referenced by a specific Instance of the CmdhNwAccessRule Object (ID: 2055)",
    "resourcedefs": [
      {
        "id": 0,
        "name": "NetworkAction",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "1..5",
        "units": "",
        "description": "Contains specific action actually  attempted on the network (e.g. cellular-registration)"
      },
      {
        "id": 1,
        "name": "InitialBackoffTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Regarding the BackOffParameters of a certain CmdhNwAccessRule  Object Instance, this Resource contains the value for the Initial wait time. "
      },
      {
        "id": 2,
        "name": "AdditionalBackoffTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Regarding the BackOffParameters of a certain CmdhNwAccessRule  Object Instance, this Resource contains the value for an additional wait tme."
      },
      {
        "id": 3,
        "name": "MaximumBackoffTime",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Regarding the BackOffParameters of a certain CmdhNwAccessRule  Object Instance, this Resource contains the value for the maximum wait time"
      },
      {
        "id": 4,
        "name": "OptionalRandomBackoffTime",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Regarding the BackOffParameters of a certain CmdhNwAccessRule  Object Instance, this Resource contains the value for an optional random wait time."
      }
    ]
  },
  {
    "name": "Digital Input",
    "id": 3200,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Generic digital input for non-specific sensors",
    "resourcedefs": [
      {
        "id": 5500,
        "name": "Digital Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of a digital input."
      },
      {
        "id": 5501,
        "name": "Digital Input Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The cumulative value of active state detected."
      },
      {
        "id": 5502,
        "name": "Digital Input Polarity",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The polarity of the digital input as a Boolean (0 \u003d Normal, 1\u003d Reversed)"
      },
      {
        "id": 5503,
        "name": "Digital Input Debounce",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "The debounce period in ms. ."
      },
      {
        "id": 5504,
        "name": "Digital Input Edge Selection",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "1-3",
        "units": "",
        "description": "The edge selection as an integer (1 \u003d Falling edge, 2 \u003d Rising edge, 3 \u003d Both Rising and Falling edge)."
      },
      {
        "id": 5505,
        "name": "Digital Input Counter Reset",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Counter value."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string, for instance, “Air Pressure”"
      },
      {
        "id": 5751,
        "name": "Sensor Type",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The type of the sensor (for instance PIR type)"
      }
    ]
  },
  {
    "name": "Digital Output",
    "id": 3201,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Generic digital output for non-specific actuators",
    "resourcedefs": [
      {
        "id": 5550,
        "name": "Digital Output State",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of a digital output."
      },
      {
        "id": 5551,
        "name": "Digital Output Polarity",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The polarity of a digital ouput as a Boolean (0 \u003d Normal, 1\u003d Reversed)."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the output as a string, for instance, “LED”"
      }
    ]
  },
  {
    "name": "Analog Input",
    "id": 3202,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Generic analog input for non-specific sensors",
    "resourcedefs": [
      {
        "id": 5600,
        "name": "Analog Input Current Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "0-1",
        "units": "",
        "description": "The current value of the analog input."
      },
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string, for instance, “Air Pressure”"
      },
      {
        "id": 5751,
        "name": "Sensor Type",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The type of the sensor, for instance PIR type"
      }
    ]
  },
  {
    "name": "Analog Output",
    "id": 3203,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is a generic object that can be used with any kind of analog output interface.",
    "resourcedefs": [
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5650,
        "name": "Analog Output Current Value",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "0-1",
        "units": "",
        "description": "The current state of the analogue output."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the application type of the actuator as a string, for instance, “Thermostat”"
      }
    ]
  },
  {
    "name": "Generic Sensor",
    "id": 3300,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object allow the description of a generic sensor. It is based on the description of a value and a unit according to the UCUM specification. Thus, any type of value defined within this specification can be reporting using this object.\nSpecific object for a given range of sensors is described later in the document, enabling to identify the type of sensors directly from its Object ID. This object may be used as a generic object if a dedicated one does not exist.",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the application type of the sensor as a string, for instance, “CO2”"
      },
      {
        "id": 5751,
        "name": "Sensor Type",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The type of the sensor (for instance PIR type)"
      }
    ]
  },
  {
    "name": "Illuminance",
    "id": 3301,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Illuminance sensor, example units \u003d lx",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The current value of the luminosity sensor."
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the type of sensor defined as the UCUM Unit Definition e.g. “Cel” for Temperature in Celcius."
      }
    ]
  },
  {
    "name": "Presence",
    "id": 3302,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Presence sensor with digital sensing, optional delay parameters",
    "resourcedefs": [
      {
        "id": 5500,
        "name": "Digital Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of the presence sensor"
      },
      {
        "id": 5501,
        "name": "Digital Input Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The cumulative value of active state detected."
      },
      {
        "id": 5505,
        "name": "Digital Input Counter Reset",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Counter value"
      },
      {
        "id": 5751,
        "name": "Sensor Type",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The type of the sensor (for instance PIR type)"
      },
      {
        "id": 5903,
        "name": "Busy to Clear delay",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Delay from the detection state to the clear state in ms"
      },
      {
        "id": 5904,
        "name": "Clear to Busy delay",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "ms",
        "description": "Delay from the clear state to the busy state in ms"
      }
    ]
  },
  {
    "name": "Temperature",
    "id": 3303,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This IPSO object should be used with a temperature sensor to report a temperature measurement.  It also provides resources for minimum/maximum measured values and the minimum/maximum range that can be measured by the temperature sensor. An example measurement unit is degrees Celsius (ucum:Cel).",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      }
    ]
  },
  {
    "name": "Humidity",
    "id": 3304,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This IPSO object should be used with a humidity sensor to report a humidity measurement.  It also provides resources for minimum/maximum measured values and the minimum/maximum range that can be measured by the humidity sensor. An example measurement unit is relative humidity as a percentage (ucum:%).",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      }
    ]
  },
  {
    "name": "Power Measurement",
    "id": 3305,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used over a power measurement sensor to report a remote power measurement.  It also provides resources for minimum/maximum measured values and the minimum/maximum range for both active and reactive power. Il also provides resources for cumulative energy, calibration, and the power factor.",
    "resourcedefs": [
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5800,
        "name": "Instantaneous active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "W",
        "description": "The current active power"
      },
      {
        "id": 5801,
        "name": "Min Measured active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "W",
        "description": "The minimum active power measured by the sensor since it is ON"
      },
      {
        "id": 5802,
        "name": "Max Measured  active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "W",
        "description": "The maximum active power measured by the sensor since it is ON"
      },
      {
        "id": 5803,
        "name": "Min Range active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "W",
        "description": "The minimum active power that can be measured by the sensor"
      },
      {
        "id": 5804,
        "name": "Max Range active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "W",
        "description": "The maximum active power that can be measured by the sensor"
      },
      {
        "id": 5805,
        "name": "Cumulative active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Wh",
        "description": "The cumulative active power since the last cumulative energy reset or device start"
      },
      {
        "id": 5806,
        "name": "Active Power Calibration",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "W",
        "description": "Request an active power calibration by writing the value of a calibrated load."
      },
      {
        "id": 5810,
        "name": "Instantaneous reactive power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VAR",
        "description": "The current reactive power"
      },
      {
        "id": 5811,
        "name": "Min Measured reactive power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VAR",
        "description": "The minimum reactive power measured by the sensor since it is ON"
      },
      {
        "id": 5812,
        "name": "Max Measured reactive power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VAR",
        "description": "The maximum reactive power measured by the sensor since it is ON"
      },
      {
        "id": 5813,
        "name": "Min Range reactive power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VAR",
        "description": "The minimum active power that can be measured by the sensor"
      },
      {
        "id": 5814,
        "name": "Max Range reactive power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VAR",
        "description": "The maximum reactive power that can be measured by the sensor"
      },
      {
        "id": 5815,
        "name": "Cumulative reactive power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VARh",
        "description": "The cumulative reactive power since the last cumulative energy reset or device start"
      },
      {
        "id": 5816,
        "name": "Reactive Power Calibration",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "VAR",
        "description": "Request a reactive power calibration by writing the value of a calibrated load."
      },
      {
        "id": 5820,
        "name": "Power Factor",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "If applicable, the power factor of the current consumption."
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      },
      {
        "id": 5822,
        "name": "Reset Cumulative energy",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset both cumulative active/reactive power"
      }
    ]
  },
  {
    "name": "Actuation",
    "id": 3306,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is dedicated to remote actuation such as ON/OFF action or dimming. A multi-state output can also be described as a string. This is useful to send pilot wire orders for instance. It also provides a resource to reflect the time that the device has been switched on.",
    "resourcedefs": [
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The Application type of the device, for example “Motion Closure”."
      },
      {
        "id": 5850,
        "name": "On/Off",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "On/Off"
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "This resource represents a light dimmer setting, which has an Integer value between 0 and 100 as a percentage."
      },
      {
        "id": 5852,
        "name": "On Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "sec",
        "description": "The time in seconds that the device has been on. Writing a value of 0 resets the counter."
      },
      {
        "id": 5853,
        "name": "Muti-state Output",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A string describing a state for multiple level output such as Pilot Wire"
      }
    ]
  },
  {
    "name": "Set Point",
    "id": 3308,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This IPSO object should be used to set a desired value to a controller, such as a thermostat. This object enables a setpoint to be expressed units defined in the UCUM specification, to match an associated sensor or measurement value. A special resource is added to set the colour of an object.",
    "resourcedefs": [
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the type of sensor defined as the UCUM Unit Definition e.g. “Cel” for Temperature in Celcius."
      },
      {
        "id": 5706,
        "name": "Colour",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A string representing a value in some color space"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The Application type of the device, for example “Motion Closure”."
      },
      {
        "id": 5900,
        "name": "Set Point Value",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The setpoint value."
      }
    ]
  },
  {
    "name": "Load Control",
    "id": 3310,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This Object is used for demand-response load control and other load control in automation application (not limited to power).",
    "resourcedefs": [
      {
        "id": 5823,
        "name": "Event Identifier",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The event identifier as a string."
      },
      {
        "id": 5824,
        "name": "Start Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Time when the load control event will start started."
      },
      {
        "id": 5825,
        "name": "Duration In Min",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "Min",
        "description": "The duration of the load control event."
      },
      {
        "id": 5826,
        "name": "Criticality Level",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The criticality of the event.  The device receiving the event will react in an appropriate fashion for the device."
      },
      {
        "id": 5827,
        "name": "Avg Load Adj Pct",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-100",
        "units": "%",
        "description": "Defines the maximum energy usage of the receivng device, as a percentage of the device\u0027s normal maximum energy usage."
      },
      {
        "id": 5828,
        "name": "Duty Cycle",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "0-100",
        "units": "%",
        "description": "Defines the duty cycle for the load control event, i.e, what percentage of time the receiving device is allowed to be on."
      }
    ]
  },
  {
    "name": "Light Control",
    "id": 3311,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This Object is used to control a light source, such as a LED or other light.  It allows a light to be turned on or off and its dimmer setting to be control as a % between 0 and 100. An optional colour setting enables a string to be used to indicate the desired colour.",
    "resourcedefs": [
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the type of sensor defined as the UCUM Unit Definition e.g. “Cel” for Temperature in Celcius."
      },
      {
        "id": 5706,
        "name": "Colour",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A string representing a value in some color space"
      },
      {
        "id": 5805,
        "name": "Cumulative active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Wh",
        "description": "The total power in Wh that the light has used."
      },
      {
        "id": 5820,
        "name": "Power Factor",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The power factor of the light."
      },
      {
        "id": 5850,
        "name": "On/Off",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "This resource represents a light, which can be controlled, the setting of which is a Boolean value (1,0) where 1 is on and 0 is off."
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "This resource represents a light dimmer setting, which has an Integer value between 0 and 100 as a percentage."
      },
      {
        "id": 5852,
        "name": "On Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "sec",
        "description": "The time in seconds that the light has been on. Writing a value of 0 resets the counter."
      }
    ]
  },
  {
    "name": "Power Control",
    "id": 3312,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This Object is used to control a power source, such as a Smart Plug.  It allows a power relay to be turned on or off and its dimmer setting to be control as a % between 0 and 100.",
    "resourcedefs": [
      {
        "id": 5805,
        "name": "Cumulative active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Wh",
        "description": "The total power in Wh that has been used by the load."
      },
      {
        "id": 5820,
        "name": "Power Factor",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The power factor of the load."
      },
      {
        "id": 5850,
        "name": "On/Off",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "This resource represents a power relay, which can be controlled, the setting of which is a Boolean value (1,0) where 1 is on and 0 is off."
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "W",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "This resource represents a power dimmer setting, which has an Integer value between 0 and 100 as a percentage."
      },
      {
        "id": 5852,
        "name": "On Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "sec",
        "description": "The time in seconds that the power relay has been on. Writing a value of 0 resets the counter."
      }
    ]
  },
  {
    "name": "Accelerometer",
    "id": 3313,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This IPSO object can be used to represent a 1-3 axis accelerometer.",
    "resourcedefs": [
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5702,
        "name": "X Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the X axis."
      },
      {
        "id": 5703,
        "name": "Y Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Y axis."
      },
      {
        "id": 5704,
        "name": "Z Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Z axis."
      }
    ]
  },
  {
    "name": "Magnetometer",
    "id": 3314,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This IPSO object can be used to represent a 1-3 axis magnetometer with optional compass direction.",
    "resourcedefs": [
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5702,
        "name": "X Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the X axis."
      },
      {
        "id": 5703,
        "name": "Y Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Y axis."
      },
      {
        "id": 5704,
        "name": "Z Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Z axis."
      },
      {
        "id": 5705,
        "name": "Compass Direction",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "0-360",
        "units": "Deg",
        "description": "The compass direction"
      }
    ]
  },
  {
    "name": "Barometer",
    "id": 3315,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Description: This IPSO object should be used with an air pressure sensor to report a barometer measurement.  It also provides resources for minimum/maximum measured values and the minimum/maximum range that can be measured by the barometer sensor. An example measurement unit is kPa (ucum:kPa).",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the type of sensor defined as the UCUM Unit Definition e.g. “Cel” for Temperature in Celcius."
      }
    ]
  },
  {
    "name": "Voltage",
    "id": 3316,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with voltmeter sensor to report measured voltage between two points.  It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is volts (ucum: V).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Current",
    "id": 3317,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with an ammeter to report measured electric current in amperes. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is volts (ucum: A).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Frequency",
    "id": 3318,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report frequency measurements. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is volts (ucum: Hz).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Depth",
    "id": 3319,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report depth measurements. It can, for example, be used to describe a generic rain gauge that measures the accumulated rainfall in millimetres (mm) or in fathoms (fth).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Percentage",
    "id": 3320,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should can be used to report measurements relative to a 0-100% scale. For example it could be used to measure the level of a liquid in a vessel or container in units of %.\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Altitude",
    "id": 3321,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with an altitude sensor to report altitude above sea level in meters. Note that Altitude can be calculated from the measured pressure given the local sea level pressure.  It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is meters (ucum: m).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Load",
    "id": 3322,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with a load sensor (as in a scale) to report the applied weight or force. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is kilograms (ucum: Kg).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Pressure",
    "id": 3323,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report pressure measurements. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is pascals (ucum: Pa).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Loudness",
    "id": 3324,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report loudness or noise level measurements. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is decibels (ucum: dB).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Concentration",
    "id": 3325,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to the particle concentration measurement of a medium. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is parts per million  (ucum: ppm).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Acidity",
    "id": 3326,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report an acidity measurement of a liquid. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is pH.\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Conductivity",
    "id": 3327,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report a measurement of the electric conductivity of a medium or sample. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is Siemens (ucum: S).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Power",
    "id": 3328,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report power measurements. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is Watts (ucum: W). This resource may be used for either real power or apparent power (units\u003d ucum:VA) measurements. The Application type can be use for reactive power or active power for example.\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Power Factor",
    "id": 3329,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report a measurement or calculation of the power factor of a reactive electrical load. Power Factor is normally the ratio of non-reactive power to total power. This object also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor.\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Distance",
    "id": 3330,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report a distance measurement. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor. An example measurement unit is Meters (ucum: m).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Energy",
    "id": 3331,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report energy consumption (Cumulative Power) of an electrical load. An example measurement unit is Watt Hours (ucum:W*h).\n        ",
    "resourcedefs": [
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5805,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor."
      },
      {
        "id": 5822,
        "name": "Reset Cumulative Energy",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Reset both cumulative active/reactive power."
      }
    ]
  },
  {
    "name": "Direction",
    "id": 3332,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to report the direction indicated by a compass, wind vane, or other directional indicator. The units of measure is plane angle degrees (ucum:deg).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The minimum value measured by the sensor since power ON or reset."
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "",
        "description": "The maximum value measured by the sensor since power ON or reset."
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value."
      },
      {
        "id": 5705,
        "name": "Compass Direction",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "0-360",
        "units": "deg",
        "description": "This indicates the compass direction of some phenomenon (i.e. direction of travel, wind direction…)."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Time",
    "id": 3333,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to report the current time in seconds since January 1, 1970 UTC. There is also a fractional time counter that has a range of less than one second.\n        ",
    "resourcedefs": [
      {
        "id": 5506,
        "name": "Current Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "time",
        "range": "",
        "units": "s",
        "description": "Unix Time. A signed integer representing the number of seconds since Jan 1st, 1970 in the UTC time zone."
      },
      {
        "id": 5507,
        "name": "Fractional Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "0-1",
        "units": "seconds",
        "description": "For shorter times of a fraction of a second (i.e. 0.23)."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Gyrometer",
    "id": 3334,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO Object is used to report the current reading of a gyrometer sensor in 3 axes. It provides tracking of the minimum and maximum angular rate in all 3 axes. An example unit of measure is radians per second (ucum:rad/s).\n        ",
    "resourcedefs": [
      {
        "id": 5508,
        "name": "Min X Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum measured value along the X axis"
      },
      {
        "id": 5509,
        "name": "Max X Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum measured value along the X axis"
      },
      {
        "id": 5510,
        "name": "Min Y Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum measured value along the Y axis"
      },
      {
        "id": 5511,
        "name": "Max Y Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum measured value along the Y axis"
      },
      {
        "id": 5512,
        "name": "Min Z Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum measured value along the Z axis"
      },
      {
        "id": 5513,
        "name": "Max Z Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum measured value along the Z axis"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value."
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5702,
        "name": "X Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the X axis."
      },
      {
        "id": 5703,
        "name": "Y Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Y axis."
      },
      {
        "id": 5704,
        "name": "Z Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Z axis."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Colour",
    "id": 3335,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to report the measured value of a colour sensor in some colour space described by the units resource.\n        ",
    "resourcedefs": [
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5706,
        "name": "Colour",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A string representing a value in some colour space."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Location",
    "id": 3336,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object represents GPS coordinates. This object is compatible with the LwM2M management object for location, but uses reusable resources.\n        ",
    "resourcedefs": [
      {
        "id": 5513,
        "name": "Latitude",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The decimal notation of latitude, e.g. -43.5723 (World Geodetic System 1984)."
      },
      {
        "id": 5514,
        "name": "Longitude",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The decimal notation of longitude, e.g. 153.21760 (World Geodetic System 1984)."
      },
      {
        "id": 5515,
        "name": "Altitude",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The decimal notation of altitude in meters above sea level."
      },
      {
        "id": 5516,
        "name": "Uncertainty",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The accuracy of the position in meters."
      },
      {
        "id": 5517,
        "name": "Velocity",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "The velocity of the device as defined in 3GPP 23.032 GAD specification. This set of values may not be available if the device is static."
      },
      {
        "id": 5518,
        "name": "Timestamp",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "time",
        "range": "",
        "units": "",
        "description": "The timestamp of when the location measurement was performed."
      },
      {
        "id": 5705,
        "name": "Compass Direction",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "0-360",
        "units": "Degrees",
        "description": "Measured Direction."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Positioner",
    "id": 3337,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with a generic position actuator from 0 to 100%. This resource optionally allows setting the transition time for an operation that changes the position of the actuator, and for reading the remaining time of the currently active transition.\n        ",
    "resourcedefs": [
      {
        "id": 5519,
        "name": "Min Limit",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "Same as Measured Value",
        "units": "Same as Measured Value",
        "description": "The minimum value that can be measured by the sensor."
      },
      {
        "id": 5520,
        "name": "Max Limit",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "Same as Measured Value",
        "units": "Same as Measured Value",
        "description": "The maximum value that can be measured by the sensor."
      },
      {
        "id": 5536,
        "name": "Current Position",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "0-100",
        "units": "%",
        "description": "Current position or desired position of a positioner actuator."
      },
      {
        "id": 5537,
        "name": "Transition Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The time expected to move the actuator to the new position."
      },
      {
        "id": 5538,
        "name": "Remaining Time",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The time remaining in an operation."
      },
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "Same as Measured Value",
        "units": "Same as Measured Value",
        "description": "The minimum value set on the actuator since power ON or reset."
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "Same as Measured Value",
        "units": "Same as Measured Value",
        "description": "The maximum value set on the actuator since power ON or reset."
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Value",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Buzzer",
    "id": 3338,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used to actuate an audible alarm such as a buzzer, beeper, or vibration alarm. There is a dimmer control for setting the relative loudness of the alarm, and an optional duration control to limit the length of time the alarm sounds when turned on. Each time a “1” is written to the On/Off resource, the alarm will sound again for the configured duration. If no duration is programmed or the setting is zero, writing a “1” to the On/Off resource will result in the alarm sounding continuously until a “0” is written to the On/Off resource.\n        ",
    "resourcedefs": [
      {
        "id": 5521,
        "name": "Delay Duration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The duration of the time delay."
      },
      {
        "id": 5525,
        "name": "Minimum Off-time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The off time when On/Off control remains on."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5850,
        "name": "On/Off",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "On/Off control, 0\u003dOFF, 1\u003dON."
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "Proportional control, integer value between 0 and 100 as a percentage."
      }
    ]
  },
  {
    "name": "Audio Clip",
    "id": 3339,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used for a speaker that plays a pre-recorded audio clip or an audio output that is sent elsewhere. For example, an elevator which announces the floor of the building. A resource is provided to store the clip, a dimmer resource controls the relative sound level of the playback, and a duration resource limits the maximum playback time. After the duration time is reached, any remaining samples in the clip are ignored, and the clip player will be ready to play another clip.",
    "resourcedefs": [
      {
        "id": 5522,
        "name": "Clip",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Audio Clip that is playable (i.e. short audio recording indicating the floor in an elevator)."
      },
      {
        "id": 5523,
        "name": "Trigger",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Trigger initiating actuation."
      },
      {
        "id": 5524,
        "name": "Duration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "seconds",
        "description": "The duration of the sound once trigger."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "Proportional control, integer value between 0 and 100 as a percentage."
      }
    ]
  },
  {
    "name": "Timer",
    "id": 3340,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to time events and actions, using patterns common to industrial timers. A POST to the trigger resource or On/Off input state change starts the timing operation, and the timer remaining time shows zero when the operation is complete. The patterns supported are One-Shot (mode 1), On-Time or Interval (mode 2), Time delay on pick-up or TDPU (tmode 3), and Time Delay on Drop-Out or TDDO (mode 4). Mode 0 disables the timer, so the output follows the input with no delay. A counter is provided to count occurrences of the timer output changing from 0 to 1. Writing a value of zero resets the counter. The Digital Input State resource reports the state of the timer output.\n        ",
    "resourcedefs": [
      {
        "id": 5501,
        "name": "Digital Input Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The number of times the input."
      },
      {
        "id": 5521,
        "name": "Duration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The duration of the time delay."
      },
      {
        "id": 5523,
        "name": "Trigger",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Trigger initiating actuation."
      },
      {
        "id": 5525,
        "name": "Minimum Off-time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The duration of the rearm delay (i.e. the delay from the end of one cycle until the beginning of the next, the inhibit time)."
      },
      {
        "id": 5526,
        "name": "Mode",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-4",
        "units": "",
        "description": "Type of timer pattern used by the patterns."
      },
      {
        "id": 5534,
        "name": "Counter",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Counts the number of times the timer output transitions from 0 to 1."
      },
      {
        "id": 5538,
        "name": "Remaining Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The time remaining in an operation."
      },
      {
        "id": 5543,
        "name": "Digital State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of the timer output."
      },
      {
        "id": 5544,
        "name": "Cumulative Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "s",
        "description": "The total time in seconds that the timer input is true. Writing a 0 resets the time."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5850,
        "name": "On/Off",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "On/off control for the timer input, 0\u003dOFF, 1\u003dON."
      }
    ]
  },
  {
    "name": "Addressable Text Display",
    "id": 3341,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to send text to a text-only or text mode graphics display. POSTing a string of text to the text resource causes it to be displayed at the selected X and Y locations on the display. If X or Y are set to a value greater than the size of the display, the position “wraps around” to the modulus of the setting and the display size. Likewise, if the text string overflows the display size, the text “wraps around” and displays on the next line down or, if the last line has been written, wraps around to the top of the display. Brightness and Contrast controls are provided to allow control of various display types including STN and DSTN type LCD character displays. POSTing an empty payload to the Clear Display resource causes the display to be erased.\n        ",
    "resourcedefs": [
      {
        "id": 5527,
        "name": "Text",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A string of text."
      },
      {
        "id": 5528,
        "name": "X Coordinate",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "X Coordinate."
      },
      {
        "id": 5529,
        "name": "Y Coordinate",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Y Coordinate."
      },
      {
        "id": 5530,
        "name": "Clear Display",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Command to clear the display."
      },
      {
        "id": 5531,
        "name": "Contrast",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "0-100",
        "units": "%",
        "description": "Proportional control, integer value between 0 and 100 as a percentage."
      },
      {
        "id": 5545,
        "name": "Max X Coordinate",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The highest X coordinate the display supports before wrapping to the next line."
      },
      {
        "id": 5546,
        "name": "Max Y Coordinate",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The highest Y coordinate the display supports before wrapping to the next line."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "0-100",
        "units": "%",
        "description": "Proportional control, integer value between 0 and 100 as a percentage."
      }
    ]
  },
  {
    "name": "On/Off switch",
    "id": 3342,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with an On/Off switch to report the state of the switch.",
    "resourcedefs": [
      {
        "id": 5500,
        "name": "Digital Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of a digital input."
      },
      {
        "id": 5501,
        "name": "Digital Input Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The number of times the input transitions from 0 to 1."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5852,
        "name": "On Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The time in seconds since the On command was sent. Writing a value of 0 resets the counter."
      },
      {
        "id": 5854,
        "name": "Off Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The time in seconds since the Off command was sent. Writing a value of 0 resets the counter."
      }
    ]
  },
  {
    "name": "Dimmer",
    "id": 3343,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object should be used with a dimmer or level control to report the state of the control.\n        ",
    "resourcedefs": [
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5851,
        "name": "Dimmer",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "0-100",
        "units": "%",
        "description": "Proportional control, integer value between 0 and 100 as a percentage."
      },
      {
        "id": 5852,
        "name": "On Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The time in seconds that the dimmer has been on (Dimmer value has to be \u003e 0). Writing a value of 0 resets the counter."
      },
      {
        "id": 5854,
        "name": "Off Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "s",
        "description": "The time in seconds that the dimmer has been off  (dimmer value less or equal to 0) Writing a value of 0 resets the counter. "
      }
    ]
  },
  {
    "name": "Up/Down Control",
    "id": 3344,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to report the state of an up/down control element like a pair of push buttons or a rotary encoder. Counters for increase and decrease operations are provided for counting pulses from a quadrature encoder.\n        ",
    "resourcedefs": [
      {
        "id": 5532,
        "name": "Increase Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates an increase control action."
      },
      {
        "id": 5533,
        "name": "Decrease Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Indicates a decrease control action."
      },
      {
        "id": 5541,
        "name": "Up Counter",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Counts the number of times the increase control has been operated. Writing a 0 resets the counter."
      },
      {
        "id": 5542,
        "name": "Down Counter",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "Counts the times the decrease control has been operated. Writing a 0 resets the counter."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Multiple Axis Joystick",
    "id": 3345,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object can be used to report the position of a shuttle or joystick control. A digital input is provided to report the state of an associated push button.\n        ",
    "resourcedefs": [
      {
        "id": 5500,
        "name": "Digital Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of a digital input."
      },
      {
        "id": 5501,
        "name": "Digital Input Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The number of times the input transitions from 0 to 1."
      },
      {
        "id": 5702,
        "name": "X Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the X axis."
      },
      {
        "id": 5703,
        "name": "Y Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Y axis."
      },
      {
        "id": 5704,
        "name": "Z Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The measured value along the Z axis."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Rate",
    "id": 3346,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This object type should be used to report a rate measurement, for example the speed of a vehicle, or the rotational speed of a drive shaft. It also provides resources for minimum and maximum measured values, as well as the minimum and maximum range that can be measured by the sensor.An example measurement unit is Feet per Second (ucum:ft_us/s).\n        ",
    "resourcedefs": [
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since power ON or reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "",
        "units": "",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Measurement Units Definition e.g. Rate, example units \u003d Feet per Second"
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case"
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Push button",
    "id": 3347,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to report the state of a momentary action push button control and to count the number of times the control has been operated since the last observation.\n        ",
    "resourcedefs": [
      {
        "id": 5500,
        "name": "Digital Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "The current state of a digital input."
      },
      {
        "id": 5501,
        "name": "Digital Input State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The number of times the input transitions from 0 to 1."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Multi-state Selector",
    "id": 3348,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This IPSO object is used to represent the state of a Multi-state selector switch with a number of fixed positions.\n        ",
    "resourcedefs": [
      {
        "id": 5547,
        "name": "Multi-state Input",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "",
        "description": "The current state of a Multi-state input or selector."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      }
    ]
  },
  {
    "name": "Bitmap",
    "id": 3349,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Summarize several digital inputs to one value by mapping each bit to a digital input.",
    "resourcedefs": [
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5910,
        "name": "Bitmap Input",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Integer in which each of the bits are associated with specific digital input value. Represented as a binary signed integer in network byte order, and in two\u0027s complement representation. Using values in range 0-127 is recommended to avoid ambiguities with byte order and negative values."
      },
      {
        "id": 5911,
        "name": "Bitmap Input Reset",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Reset the Bitmap Input value."
      },
      {
        "id": 5912,
        "name": "Element Description",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The semantics / description of each bit as a string. First instance describes the least significant bit, second instance the second least significant bit, etc."
      }
    ]
  },
  {
    "name": "Stopwatch",
    "id": 3350,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "An ascending timer that counts how long time has passed since the timer was started after reset.",
    "resourcedefs": [
      {
        "id": 5501,
        "name": "Digital Input Counter",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The number of times the input transitions from off to on."
      },
      {
        "id": 5544,
        "name": "Cumulative Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "\n        ",
        "units": "s",
        "description": "The total time in seconds that the stopwatch has been on. Writing a 0 resets the time."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The application type of the sensor or actuator as a string depending on the use case."
      },
      {
        "id": 5850,
        "name": "On/Off",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "\n        ",
        "units": "\n        ",
        "description": "On/Off control for the stopwatch, True\u003dON, False\u003dOFF."
      }
    ]
  },
  {
    "name":"PowerUpLog",
    "id":3351,
    "instancetype":"Single",
    "mandatory":true,
    "description":"One time event sent by the device at power up.",
    "resourcedefs":[
      {"id": 0,
        "name": "deviceName",
        "operations": "R",
        "instancetype": "Single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Human-readable name of the device"
      },
      {"id": 1,
        "name": "toolVersion",
        "operations": "R",
        "instancetype": "Single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The tool version that the device supports - used to determine the logging object/resource version to be used for parsing"
      },
      {"id": 2,
        "name": "IMEI",
        "operations": "R",
        "instancetype": "Single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "IMEI of device"
      },
      {"id": 3,
        "name": "IMSI",
        "operations": "R",
        "instancetype": "Single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "IMSI of device"
      },
      {"id": 4,
        "name": "MSISDN",
        "operations": "R",
        "instancetype": "Single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "MSISDN of device"
      }
    ]
  },
  {
    "name": "HostDeviceInfo",
    "id": 10241,
    "instancetype": "multiple",
    "mandatory": true,
    "description": "This LwM2M Object provides a range of host device related information which can be queried by the LwM2M Server. The host device is any integrated device with an embedded cellular radio module.",
    "resourcedefs": [
      {
        "id": 5905,
        "name": "Host Device Manufacturer",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Human readable host device manufacturer name"
      },
      {
        "id": 5906,
        "name": "Host Device Model Number",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A host device model identifier (manufacturer specified string)"
      },
      {
        "id": 5907,
        "name": "Host Device Unique ID",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "The host device unique ID is assigned by AT\u0026T as the “Device ID” in the onboarding tool and will be stored in"
      },
      {
        "id": 5908,
        "name": "Host Device Software Version",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Current software version of the host device. (manufacturer specified string)."
      }
    ]
  },
  {
    "name": "3-Phase Power Meter",
    "id": 10242,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "\n        This Object provides the information to represent a generic 3-Phase Power Meter.\n    ",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Manufacturer",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                Human readable manufacturer name\n            "
      },
      {
        "id": 1,
        "name": "Model Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                A model identifier (manufacturer specified string)\n            "
      },
      {
        "id": 2,
        "name": "Serial Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                Serial number of the meter\n            "
      },
      {
        "id": 3,
        "name": "Description",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                Description of the meter\n            "
      },
      {
        "id": 4,
        "name": "Tension R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "\n                Voltage phase 1 (phase to neutral)\n            "
      },
      {
        "id": 5,
        "name": "Current R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "\n                Current phase 1\n            "
      },
      {
        "id": 6,
        "name": "Active Power R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW",
        "description": "\n                Active Power phase 1\n            "
      },
      {
        "id": 7,
        "name": "Reactive Power R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar",
        "description": "\n                Reactive Power phase 1\n            "
      },
      {
        "id": 8,
        "name": "Inductive Reactive Power R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarL",
        "description": "\n                Inductive Reactive Power phase 1\n            "
      },
      {
        "id": 9,
        "name": "Capacitive Reactive Power R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarC",
        "description": "\n                Capacitive Reactive Power phase 1\n            "
      },
      {
        "id": 10,
        "name": "Apparent Power R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA",
        "description": "\n                Apparent Power phase 1\n            "
      },
      {
        "id": 11,
        "name": "Power Factor R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "-1..1",
        "units": "",
        "description": "\n                Power Factor phase 1\n            "
      },
      {
        "id": 12,
        "name": "THD-V R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion phase 1 (Tension)\n            "
      },
      {
        "id": 13,
        "name": "THD-A R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonig Distortion phase 1 (Current)\n            "
      },
      {
        "id": 14,
        "name": "Tension S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "\n                Voltage phase 2 (phase to neutral)\n            "
      },
      {
        "id": 15,
        "name": "Current S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "\n                Current phase 2\n            "
      },
      {
        "id": 16,
        "name": "Active Power S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW",
        "description": "\n                Active Power phase 2\n            "
      },
      {
        "id": 17,
        "name": "Reactive Power S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar",
        "description": "\n                Reactive Power phase 2\n            "
      },
      {
        "id": 18,
        "name": "Inductive Reactive Power S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarL",
        "description": "\n                Inductive Reactive Power phase 2\n            "
      },
      {
        "id": 19,
        "name": "Capacitive Reactive Power S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarC",
        "description": "\n                Capacitive Reactive Power phase 2\n            "
      },
      {
        "id": 20,
        "name": "Apparent Power S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA",
        "description": "\n                Apparent Power phase 2\n            "
      },
      {
        "id": 21,
        "name": "Power Factor S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "-1..1",
        "units": "",
        "description": "\n                Power Factor phase 2\n            "
      },
      {
        "id": 22,
        "name": "THD-V S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion phase 2 (Tension)\n            "
      },
      {
        "id": 23,
        "name": "THD-A S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion phase 2 (Current)\n            "
      },
      {
        "id": 24,
        "name": "Tension T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "\n                Voltage phase 3 (phase to neutral)\n            "
      },
      {
        "id": 25,
        "name": "Current T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "\n                Current phase 3\n            "
      },
      {
        "id": 26,
        "name": "Active Power T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW",
        "description": "\n                Active Power phase 3\n            "
      },
      {
        "id": 27,
        "name": "Reactive Power T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar",
        "description": "\n                Reactive Power phase 3\n            "
      },
      {
        "id": 28,
        "name": "Inductive Reactive Power T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarL",
        "description": "\n                Inductive Reactive Power phase 3\n            "
      },
      {
        "id": 29,
        "name": "Capacitive Reactive Power T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarC",
        "description": "\n                Capacitive Reactive Power phase 3\n            "
      },
      {
        "id": 30,
        "name": "Apparent Power T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA",
        "description": "\n                Apparent Power phase 3\n            "
      },
      {
        "id": 31,
        "name": "Power Factor T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "-1..1",
        "units": "",
        "description": "\n                Power Factor phase 3\n            "
      },
      {
        "id": 32,
        "name": "THD-V T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion phase 3 (Tension)\n            "
      },
      {
        "id": 33,
        "name": "THD-A T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion phase 3 (Current)\n            "
      },
      {
        "id": 34,
        "name": "3-Phase Active Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW III",
        "description": "\n                3-Phase Active Power\n            "
      },
      {
        "id": 35,
        "name": "3-Phase Reactive Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar III",
        "description": "\n                3-Phase Reactive Power\n            "
      },
      {
        "id": 36,
        "name": "3-Phase Inductive Reactive Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarL III",
        "description": "\n                3-Phase Inductive Reactive Power\n            "
      },
      {
        "id": 37,
        "name": "3-Phase Capacitive Reactive Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarC III",
        "description": "\n                3-Phase Capacitive Reactive Power\n            "
      },
      {
        "id": 38,
        "name": "3-Phase Apparent Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA III",
        "description": "\n                3-Phase Apparent Power\n            "
      },
      {
        "id": 39,
        "name": "3-Phase Power Factor",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "-1..1",
        "units": "",
        "description": "\n                3-Phase Power Factor\n            "
      },
      {
        "id": 40,
        "name": "3-Phase phi cosine",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "-1..1",
        "units": "",
        "description": "\n                3-Phase phi cosine\n            "
      },
      {
        "id": 41,
        "name": "Active Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW/h III",
        "description": "\n                Active Energy\n            "
      },
      {
        "id": 42,
        "name": "Reactive Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar/h III",
        "description": "\n                Reactive Energy\n            "
      },
      {
        "id": 43,
        "name": "Inductive Reactive Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarL/h III",
        "description": "\n                Inductive Reactive Energy\n            "
      },
      {
        "id": 44,
        "name": "Capacitive Reactive Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarC/h III",
        "description": "\n                Capacitive Reactive Energy\n            "
      },
      {
        "id": 45,
        "name": "Apparent Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA/h III",
        "description": "\n                Apparent Energy\n            "
      },
      {
        "id": 46,
        "name": "Tension R-S",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "\n                Voltage phase 1 to phase 2\n            "
      },
      {
        "id": 47,
        "name": "Tension S-T",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "\n                Voltage phase 2 to phase 3\n            "
      },
      {
        "id": 48,
        "name": "Tension T-R",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "\n                Voltage phase 3 to phase 1\n            "
      },
      {
        "id": 49,
        "name": "Frequency",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Hz",
        "description": "\n                Frequency\n            "
      },
      {
        "id": 50,
        "name": "Neutral Current",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "\n                Neutral Current\n            "
      }
    ]
  },
  {
    "name": "Single-Phase Power Meter",
    "id": 10243,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "\n        This Object provides the information to represent a generic Single-Phase Power Meter.\n    ",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Manufacturer",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                Human readable manufacturer name\n            "
      },
      {
        "id": 1,
        "name": "Model Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                A model identifier (manufacturer specified string)\n            "
      },
      {
        "id": 2,
        "name": "Serial Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                Serial number of the meter\n            "
      },
      {
        "id": 3,
        "name": "Description",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "\n                Description of the meter\n            "
      },
      {
        "id": 4,
        "name": "Tension",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "V",
        "description": "\n                Voltage\n            "
      },
      {
        "id": 5,
        "name": "Current",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "\n                Current\n            "
      },
      {
        "id": 6,
        "name": "Active Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW",
        "description": "\n                Active Power\n            "
      },
      {
        "id": 7,
        "name": "Reactive Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar",
        "description": "\n                Reactive Power\n            "
      },
      {
        "id": 8,
        "name": "Inductive Reactive Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarL",
        "description": "\n                Inductive Reactive Power\n            "
      },
      {
        "id": 9,
        "name": "Capacitive Reactive Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvarC",
        "description": "\n                Capacitive Reactive Power\n            "
      },
      {
        "id": 10,
        "name": "Apparent Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA",
        "description": "\n                Apparent Power\n            "
      },
      {
        "id": 11,
        "name": "Power Factor",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "-1..1",
        "units": "",
        "description": "\n                Power Factor\n            "
      },
      {
        "id": 12,
        "name": "THD-V",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion (Tension)\n            "
      },
      {
        "id": 13,
        "name": "THD-A",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "%",
        "description": "\n                Total Harmonic Distortion (Current)\n            "
      },
      {
        "id": 14,
        "name": "Active Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW/h",
        "description": "\n                Active Energy\n            "
      },
      {
        "id": 15,
        "name": "Reactive Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kvar/h",
        "description": "\n                Reactive Energy\n            "
      },
      {
        "id": 16,
        "name": "Apparent Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kVA/h",
        "description": "\n                Apparent Energy\n            "
      },
      {
        "id": 17,
        "name": "Frequency",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Hz",
        "description": "\n                Frequency\n            "
      }
    ]
  },
  {
    "name": "VehicleControlUnit",
    "id": 10244,
    "instancetype": "single",
    "mandatory": false,
    "description": "This Object provides the information to represent a generic VCU(vehicle control unit).",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Vehicle UI State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-15",
        "units": "",
        "description": "The UI state of the vehicle. 0: idle 1: driving 2: charging 3: limp-home 4-15: reserved for future use"
      },
      {
        "id": 1,
        "name": "Vehicle Speed",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "km/h",
        "description": "Current speed of the vehicle."
      },
      {
        "id": 2,
        "name": "Vehicle Shift Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-3",
        "units": "",
        "description": "Current shift status of the vehicle. 0: Neutral 1: Forward 2: Reverse"
      },
      {
        "id": 3,
        "name": "Vehicle AP Position",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "Current position of the accelerator pedal."
      },
      {
        "id": 4,
        "name": "Vehicle Power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "kW",
        "description": "Current power of drive output/regenerative braking."
      },
      {
        "id": 5,
        "name": "Vehicle Drive Energy",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Wh",
        "description": "Accumulated drive energy of the vehicle."
      },
      {
        "id": 6,
        "name": "Vehicle Energy Consumption Efficiency",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "",
        "units": "Wh/km",
        "description": "Energy consumption efficiency of the vehicle."
      },
      {
        "id": 7,
        "name": "Vehicle Estimated Mileage",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "",
        "units": "km",
        "description": "Estimated mileage of current battery capacity."
      },
      {
        "id": 8,
        "name": "Vehicle Charge Cable Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether the charge cable is connected or not. 0: unconnected 1: connected"
      },
      {
        "id": 9,
        "name": "Vehicle Charge Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-15",
        "units": "",
        "description": "Charging status of the vehicle. 1: non-charge mode 2: charging 3: charge completed 4: charging abort abnormally "
      },
      {
        "id": 10,
        "name": "Vehicle Charge Voltage",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "Charging voltage"
      },
      {
        "id": 11,
        "name": "Vehicle Charge Current",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "Charging current"
      },
      {
        "id": 12,
        "name": "Vehicle Charge Remaining Time",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "minute",
        "description": "Remaining charging time"
      },
      {
        "id": 13,
        "name": "Battery Pack Voltage",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "V",
        "description": "Voltage of the battery pack"
      },
      {
        "id": 14,
        "name": "Battery Pack Current",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "A",
        "description": "Current of the battery pack"
      },
      {
        "id": 15,
        "name": "Battery Pack Remaining Capacity",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Ah",
        "description": "Remaining capacity of the battery pack"
      },
      {
        "id": 16,
        "name": "Battery Pack SOC",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "SOC(state of charge) of the battery pack"
      },
      {
        "id": 17,
        "name": "Battery Pack SOH",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-100",
        "units": "%",
        "description": "SOH(state of health) of the battery pack"
      },
      {
        "id": 18,
        "name": "Battery Cell MinVolt",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "mV",
        "description": "Minimum voltage of the battery module (with parallel connection of cells)"
      },
      {
        "id": 19,
        "name": "Battery Cell MaxVolt",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "mV",
        "description": "Maximum voltage of the battery module (with parallel connection of cells)"
      },
      {
        "id": 20,
        "name": "Battery Module MinTemp",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Celsius",
        "description": "Minimum temperature of the battery module"
      },
      {
        "id": 21,
        "name": "Battery Module MaxTemp",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Celsius",
        "description": "Maximum temperature of the battery module"
      },
      {
        "id": 22,
        "name": "Battery Connection Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether the battery is connected or not. 0: unconnected 1: connected"
      },
      {
        "id": 24,
        "name": "MCU Voltage",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "V",
        "description": "Voltage of the MCU(motor control unit)"
      },
      {
        "id": 25,
        "name": "MCU Temperature",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Celsius",
        "description": "Temperature of MCU(motor control unit)"
      },
      {
        "id": 26,
        "name": "Motor Speed",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "rpm",
        "description": "Rotational speed of the motor"
      },
      {
        "id": 27,
        "name": "Motor Temperature",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "",
        "units": "Celsius",
        "description": "Temperature of the motor"
      },
      {
        "id": 28,
        "name": "Motor OT Warning",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether the motor is OT or not. 0: normal 1: OT warning"
      },
      {
        "id": 29,
        "name": "MCU OT Warning",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether the MCU is OT or not. 0: normal 1: OT warning"
      },
      {
        "id": 30,
        "name": "Battery Pack OT Warning",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether the battery pack is OT or not. 0: normal 1: OT warning"
      },
      {
        "id": 31,
        "name": "MCU fault",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Status of MCU. 0: normal 1: level 1 minor fault 2: level 2 critical fault"
      },
      {
        "id": 32,
        "name": "Motor Error",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Status of the battery pack. 0: normal 1: level D25 minor fault 2: level 2 critical fault"
      }
    ]
  },
  {
    "name": "Relay Management",
    "id": 10245,
    "instancetype": "single",
    "mandatory": true,
    "description": "This LwM2M Object provides a range of eNB related measurements and parameters of which several are changeable. Furthermore, it includes Resources to enable/disable the eNB.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "eNB Availability",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "AVAILABLE; UNAVAILABLE",
        "units": "",
        "description": "This field indicates to the CCC whether or not the eNB of the CrowdBox is available for activation: AVAILABLE \u003d TRUE; UNAVAILABLE \u003d FALSE This is set by the CrowdBox itself using an algorithm specific to the use case and based on parameters known to the CrowdBox which may not necessarily be signalled to the network. In the absence of a more specific algorithm, this parameter should be set to AVAILABLE, unless a fault is detected which would prevent activation of the eNB, in which case it should be set to UNAVAILABLE."
      },
      {
        "id": 1,
        "name": "GPS Status",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "UNSYNCHRONISED; SYNCHRONISED",
        "units": "",
        "description": "States whether the CrowdBox GPS receiver is synchronised to GPS time or not: UNSYCHRONISED \u003d FALSE; SYNCHRONISED \u003d TRUE If more than one GPS receiver is used by the CrowdBox, then SYNCHRONISED should be reported only if all receivers are synchronised."
      },
      {
        "id": 2,
        "name": "Orientation",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "-180..180",
        "units": "degrees",
        "description": "Orientation of CrowdBox with respect to magnetic north. The reference orientation of the CrowdBox shall be the pointing direction of the eNB antenna(s) or, in the case of an omni-directional CrowdBox antenna, as defined in the accompanying product documentation."
      },
      {
        "id": 3,
        "name": "eNB EARFCN",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..65535",
        "units": "",
        "description": "EARFCN currently used by the eNB. Highest valid value in 3GPP is currently 46589. If the requested EARFCN is not supported by the eNB, the response should be \"Bad Request\". The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 4,
        "name": "eNB Bandwidth",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "5, 10, 15, 20",
        "units": "",
        "description": "Bandwidth of the currently used eNB carrier. If the requested bandwidth is not supported by the eNB, the response should be \"Bad Request\". The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 5,
        "name": "Backhaul Primary EARFCN",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..65535",
        "units": "",
        "description": "EARFCN of primary cell used for the backhaul. If the requested EARFCN is not supported by the CrowdBox UE, the response should be \"Bad Request\". The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 6,
        "name": "Backhaul Secondary EARFCN",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "0..65535",
        "units": "",
        "description": "EARFCN of any secondary cells used for the backhaul, in the event that carrier aggregation is being used. If the requested EARFCN is not supported by the CrowdBox UE, the response should be \"Bad Request\". The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 7,
        "name": "Cumulative Measurement Window",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..65535",
        "units": "s",
        "description": "The current measurement interval over which cumulative statistics are collected for the following resources: Cumulative Number of Unique Users, Cumulative Downlink Throughput per Connected User, Cumulative Uplink Throughput per Connected User. Note that this measurement period is a sliding window rather than a granularity period. Measurements should never be reset, but rather old measurements should be removed from the cumulative total as they fall outside of the window. A value of 0 shall be interpreted as meaning only the current value should be reported. A value of 65535 shall be interpreted as an infinite window size (i.e. old measurements are never discarded)."
      },
      {
        "id": 8,
        "name": "eNB ECI",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..2^28-1",
        "units": "",
        "description": "A 28 bit E-UTRAN Cell Identifier (ECI)"
      },
      {
        "id": 9,
        "name": "eNB Status",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "This resource indicates the current status of the eNB and can be used by the CCC to change the state from enabled to disabled. TRUE \u003d eNB enabled FALSE \u003d eNB disabled"
      },
      {
        "id": 10,
        "name": "Enable eNB",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Enables the eNB. In addition the CrowdBox shall also update its configuration to reflect the current state of other relevant parameters. This might require a reboot."
      },
      {
        "id": 11,
        "name": "eNB Maximum Power",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..63",
        "units": "dBm",
        "description": "Maximum power for the eNB measured as the sum of input powers to all antenna connectors. The maximum power per antenna port is equal to the maximum eNB power divided by the number of antenna ports. If the requested power is above or below the maximum or minimum power levels of the eNB, then the power level should be set to the maximum or minimum respectively. The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 12,
        "name": "Backhaul Primary q-OffsetFreq",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "-24..24",
        "units": "dB",
        "description": "q-OffsetFreq parameter for the backhaul primary EARFCN in SIB5 of the CrowdBox eNB BCCH. See TS 36.331 for details. Range: dB-24; dB-22 .. dB24 The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 13,
        "name": "Backhaul Secondary q-OffsetFreq",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "-24..24",
        "units": "dB",
        "description": "q-OffsetFreq parameter for the backhaul secondary EARFCN in SIB5 of the CrowdBox eNB BCCH. See TS 36.331 for details Range: dB-24; dB-22 .. dB24 The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 14,
        "name": "Neighbour CrowdBox EARFCN",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "0..66635",
        "units": "",
        "description": "EARFCN of a neighbour CrowdBox. Each instance of this resource relates to the same instance of resource ID 15."
      },
      {
        "id": 15,
        "name": "Neighbour CrowdBox q-OffsetFreq",
        "operations": "RW",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "integer",
        "range": "-24..24",
        "units": "dB",
        "description": "q-OffsetFreq parameter of the Neighbour CrowdBox EARFCN in SIB5 of the Neighbour CrowdBox eNB BCCH. See TS 36.331 for details Range: dB-24; dB-22 .. dB24 Each instance of this resource relates to the same instance of resource ID 14. The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      },
      {
        "id": 16,
        "name": "Serving Macro eNB cellIndividualOffset",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "-24..24",
        "units": "dB",
        "description": "Specifies the value of the cellIndividualOffset parameter applicable to the CrowdBox macro serving cell that is to be signalled to connected UEs in their measurement configuration information . See TS 36.331 for details. The CrowdBox shall only apply a change of this resource upon execution of the “Enable eNB” command."
      }
    ]
  },
  {
    "name": "CrowdBox Measurements",
    "id": 10246,
    "instancetype": "single",
    "mandatory": true,
    "description": "This LwM2M Object provides CrowdBox-related measurements such as serving cell parameters, backhaul timing advance, and neighbour cell reports.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Serving Cell ID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..2^32-1",
        "units": "",
        "description": "Serving cell ID as specified by the cellIdentity field broadcast in SIB1 of the serving cell (see TS 36.331)."
      },
      {
        "id": 1,
        "name": "Serving Cell RSRP",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..97",
        "units": "",
        "description": "Serving cell RSRP, as defined in TS 36.133, Section 9.1.4. Range: RSRP_00; RSRP_01 .. RSRP_97"
      },
      {
        "id": 2,
        "name": "Serving Cell RSRQ",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "-30..46",
        "units": "",
        "description": "Serving cell RSRQ, as defined in TS 36.133, Section 9.1.7. Range: RSRQ_-30; RSRQ_-29 .. RSRQ_46"
      },
      {
        "id": 3,
        "name": "Serving Cell SINR",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "-10..30",
        "units": "dB",
        "description": "SINR of serving cell as estimated by the CrowdBox. Note that this is a proprietary measurement dependent on the UE chipset manufacturer. The UE chipset used should be stated in the accompanying product documentation."
      },
      {
        "id": 4,
        "name": "Cumulative Backhaul Timing Advance",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0..65535",
        "units": "",
        "description": "The cumulative timing advance signalled by the current serving cell to the CrowdBox. This is the sum of the initial timing advance signalled in the MAC payload of the Random Access Response (11 bits, 0 .. 1282) and subsequent adjustments signalled in the MAC PDU of DL-SCH transmissions (6 bits, -31 .. 32). See TS 36.321 for details."
      },
      {
        "id": 5,
        "name": "Neighbour Cell Report",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "A link to the \"Neighbour Cell Report\" object for each neighbour cell of the CrowdBox."
      }
    ]
  },
  {
    "name": "Neighbour Cell Report",
    "id": 10247,
    "instancetype": "multiple",
    "mandatory": true,
    "description": "This LwM2M Object provides the neighbour cell report. The CrowdBox Measurements Object and the Connected UE Report Object have both Objlnk Resources pointing to this Object.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Neighbour PCI",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..503",
        "units": "",
        "description": "Physical Cell ID of neighbouring LTE cell, as defined in TS 36.211"
      },
      {
        "id": 1,
        "name": "Neighbour Cell ID",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0..2^32-1",
        "units": "",
        "description": "Neighbour cell ID as specified by the cellIdentity field broadcast in SIB1 of the neighbour cell (see TS 36.331)."
      },
      {
        "id": 2,
        "name": "Neighbour Cell Rank",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..255",
        "units": "",
        "description": "Current neighbour cell rank. Neighbour cells should be ordered (ranked) by the CrowdBox according to neighbour cell RSRP, with a higher RSRP corresponding to a lower index. Hence the neighbouring cell with the highest RSRP should be neighbour cell 0, the second neighbour cell 1, and so on."
      },
      {
        "id": 3,
        "name": "Neighbour Cell RSRP",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..97",
        "units": "",
        "description": "Neighbour cell RSRP, as defined in TS 36.133, Section 9.1.4. Range: RSRP_00; RSRP_01 .. RSRP_97"
      },
      {
        "id": 4,
        "name": "Neighbour Cell RSRQ",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "-30..46",
        "units": "",
        "description": "Neighbour cell RSRQ, as defined in TS 36.133, Section 9.1.7. Range: RSRQ_-30; RSRQ_-29 .. RSRQ_46"
      }
    ]
  },
  {
    "name": "Connected UE Measurements",
    "id": 10248,
    "instancetype": "single",
    "mandatory": true,
    "description": "This LwM2M Object provides a range of measurements of connected UEs and provides an Object link to the Connected UE report.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Number of Connected Users",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..255",
        "units": "",
        "description": "The number of different UEs currently connected to the eNB (i.e. in RRC_CONNECTED state)."
      },
      {
        "id": 1,
        "name": "Cumulative Number of Unique Users",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..65535",
        "units": "",
        "description": "The number of different UEs that have connected to the eNB over the immediately preceding period specified by the \"Cumulative Measurement Window\" field."
      },
      {
        "id": 2,
        "name": "Connected UE Report",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "Provides an Object link to the Connected UE Report which provides a range of information related to the connected UEs."
      }
    ]
  },
  {
    "name": "Connected UE Report",
    "id": 10249,
    "instancetype": "multiple",
    "mandatory": true,
    "description": "This LwM2M Object provides a range of information related to the connected UEs.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Connected User MMEC",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..255",
        "units": "",
        "description": "MMEC signalled by the UE to the eNB in the RRCConnectionRequest message (see TS 36.331)."
      },
      {
        "id": 1,
        "name": "Connected User M-TMSI",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..2^32-1",
        "units": "",
        "description": "M-TMSI signalled by the UE to the eNB in the RRCConnectionRequest message (see TS 36.331)."
      },
      {
        "id": 2,
        "name": "Serving Cell (CrowdBox) eNB RSRP",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..97",
        "units": "",
        "description": "The RSRP of the CrowdBox eNB, as defined in TS 36.133, Section 9.1.4. Range: RSRP_00; RSRP_01 .. RSRP_97"
      },
      {
        "id": 3,
        "name": "Serving Cell (CrowdBox) eNB RSRQ",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "-30..46",
        "units": "",
        "description": "The RSRQ of the CrowdBox eNB, as defined in TS 36.133, Section 9.1.7. Range: RSRQ_-30; RSRQ_-29 .. RSRQ_46"
      },
      {
        "id": 4,
        "name": "Cumulative Timing Advance per Connected User",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "0-65535",
        "units": "",
        "description": "The cumulative timing advance signalled by the eNB to each currently connected UE. This is the sum of the initial timing advance signalled in the MAC payload of the Random Access Response (11 bits, 0 .. 1282) and subsequent adjustments signalled in the MAC PDU of DL-SCH transmissions (6 bits, -31 .. 32). See TS 36.321 for details."
      },
      {
        "id": 5,
        "name": "Last downlink CQI report per Connected User",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..255",
        "units": "",
        "description": "The last downlink wideband CQI reported by a connected user the eNB. The CQI format is defined in Table 7.2.3-1 of TS 36.213."
      },
      {
        "id": 6,
        "name": "Cumulative Downlink Throughput per Connected User",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..2^32-1",
        "units": "bytes",
        "description": "The total number of MAC bytes sent to the connected user over the immediately preceding period specified by the \"Cumulative Measurement Window\" field."
      },
      {
        "id": 7,
        "name": "Cumulative Uplink Throughput per Connected User",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0..2^32-1",
        "units": "bytes",
        "description": "The total number of MAC bytes received from the connected user over the immediately preceding period specified by the \"Cumulative Measurement Window\" field."
      },
      {
        "id": 8,
        "name": "Neighbour Cell Report",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "objlnk",
        "range": "",
        "units": "",
        "description": "A link to the \"Neighbour Cell Report\" object for each neighbour cell reported to the CrowdBox by the connected UE"
      }
    ]
  },
  {
    "name": "App Data Container",
    "id": 10250,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M Object is used for reporting application data of a device.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "UL data",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Uplink application data, e.g. gas meter reporting data."
      },
      {
        "id": 1,
        "name": "DL data",
        "operations": "W",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Downlink application data, e.g. application response message of uplink data."
      }
    ]
  },
  {
    "name": "AT Command",
    "id": 10251,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "Used to execute an AT command on a cellular modem",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Command",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The AT command to run. Example: AT+CREG? to query registration status"
      },
      {
        "id": 1,
        "name": "Response",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Response to the AT command. Example: +CREG:0,5\nIf multiple lines are returned as the modem response, each line will be returned in a separate resource."
      },
      {
        "id": 2,
        "name": "Status",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Status of the command execution as returned by the modem. Typical values:\nOK\nERROR"
      },
      {
        "id": 3,
        "name": "Timeout",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Amount of time in seconds allowed for the modem to respond to the command. "
      },
      {
        "id": 4,
        "name": "Run",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Executing this resource will cause the command to be sent to the modem. And the result to be populated using the Response (1) and Status (2) resources"
      }
    ]
  },
  {
    "name": "Manifest",
    "id": 10252,
    "instancetype": "single",
    "mandatory": true,
    "description": "This object provides a range of information related to updating packages on a device",
    "resourcedefs": [
      {
        "id": 1,
        "name": "Manifest",
        "operations": "W",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Content of a new manifest"
      },
      {
        "id": 2,
        "name": "State",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-8",
        "units": "\n        ",
        "description": "Current state of manifest processing\n0.\tUninitialised\n1.\tIdle\n2.\tProcessing manifest\n3.\tAwaiting download approval\n4.\tDownloading \n5.\tDownloaded\n6.\tAwaiting application approval\n7.\tUpdating\n8.\tRebooting\n"
      },
      {
        "id": 3,
        "name": "Manifest Result",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "0-19",
        "units": "\n        ",
        "description": "Final result of the device processing a manifest.\n0.\tUninitialised\n1.\tSuccess\n2.\tManifest timeout. The Manifest URI has timed-out.\n3.\tManifest not found. The Manifest URI not found.\n4.\tManifest failed integrity check. The manifest integrity check failed. \n5.\tManifest rejected. The Manifest attributes do not apply to this device.\n6.\tManifest certificate not found\n7.\tManifest signature failed. The Manifest signature is not recognised by this device.\n8.\tDependent manifest not found\n9.\tNot enough storage for the new asset\n10.\tOut of memory during download process\n11.\tConnection lost during download process\n12.\tAsset failed integrity check\n13.\tUnsupported asset type\n14.\tInvalid asset URI\n15.\tTimed out downloading asset\n16.\tUnsupported delta format\n17.\tUnsupported encryption format\n18.\tAsset update successfully completed\n19.\tAsset updated successfully after recovery"
      },
      {
        "id": 4,
        "name": "Payload Result",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Contains payload-specific errors or output."
      },
      {
        "id": 5,
        "name": "Asset Hash",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Hash of the installed asset."
      },
      {
        "id": 6,
        "name": "Manifest version",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Version of the current manifest."
      },
      {
        "id": 7,
        "name": "Asset Installation Progress",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Progress update of the asset installation process (in bytes)."
      },
      {
        "id": 8,
        "name": "Campaign Id",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Id of campaign affecting this device. There currently isn’t any logic on the server or the client to handle this. "
      },
      {
        "id": 9,
        "name": "Manual Trigger",
        "operations": "E",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Manually apply the asset update. This will only have effect if the manifest requires this. The state resource must also be in the downloaded state for the execute command to be actioned."
      }
    ]
  },
  {
    "name": "Confidential Data",
    "id": 10253,
    "instancetype": "single",
    "mandatory": false,
    "description": "This LwM2M Object is used for reporting data, but in a confidential way",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Public Key",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Object public key provided from the server side"
      },
      {
        "id": 1,
        "name": "Application Data",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Application Data encrypted by the Public Key"
      }
    ]
  },
  {
    "name": "Current Loop Input",
    "id": 10254,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This LwM2M Object provides a representation of a current loop sensor, which indicates the value emitted by a current source.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Current Loop Input Current Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "0; 3.8-20.5",
        "units": "mA",
        "description": "The current value of the current loop input. A value of 0 indicates the not-connected state and/or invalid (i.e. out-of-range) values."
      },
      {
        "id": 5601,
        "name": "Min Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value measured by the sensor since it is ON or Reset."
      },
      {
        "id": 5602,
        "name": "Max Measured Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value measured by the sensor since it is ON or Reset"
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5605,
        "name": "Reset Min and Max Measured Values",
        "operations": "E",
        "instancetype": "single",
        "mandatory": false,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Reset the Min and Max Measured Values to Current Value"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The application type of the sensor or actuator as a string, for instance, “Air Pressure”."
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Device Metadata",
    "id": 10255,
    "instancetype": "single",
    "mandatory": true,
    "description": "This object provides a range of information related to device metadata",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Protocol supported",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Manifest protocol supported"
      },
      {
        "id": 1,
        "name": "Bootloader hash",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Hash of the bootloader. This is used for tracking the version of the bootloader used."
      },
      {
        "id": 2,
        "name": "OEM bootloader hash",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "opaque",
        "range": "\n        ",
        "units": "\n        ",
        "description": "If the end-user has modified the bootloader the hash of the modified bootloader is recorded here"
      },
      {
        "id": 3,
        "name": "Vendor",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Vendor Class UUID"
      },
      {
        "id": 4,
        "name": "Class",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Class UUID"
      },
      {
        "id": 5,
        "name": "Device",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Device UUID"
      }
    ]
  },
  {
    "name": "Heat / Cooling meter",
    "id": 10257,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "\nThis Object provides the information to represent a generic (district) heat or cooling meter\n    ",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Manufacturer",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Human readable manufacturer name"
      },
      {
        "id": 1,
        "name": "Model Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "A model identifier (manufacturer specified string)"
      },
      {
        "id": 2,
        "name": "Serial Number",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Serial number of the meter"
      },
      {
        "id": 3,
        "name": "Description",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "Description of the meter"
      },
      {
        "id": 11,
        "name": "Error code",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": false,
        "type": "integer",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Error code reported by the meter"
      },
      {
        "id": 12,
        "name": "Flow temperature",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Celcius",
        "description": "Flow temperature"
      },
      {
        "id": 13,
        "name": "Max Measured flow temperature",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Celcius",
        "description": "The maximum flow temperature measured by the meter"
      },
      {
        "id": 14,
        "name": "Return temperature",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Celcius",
        "description": "Return temperature"
      },
      {
        "id": 15,
        "name": "Max Measured return temperature",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Celcius",
        "description": "The maximum return temperature measured by the meter "
      },
      {
        "id": 16,
        "name": "Temperature difference",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Kelvin",
        "description": "Temperature difference"
      },
      {
        "id": 17,
        "name": "Flow rate",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "m^3 / s",
        "description": "The flow rate"
      },
      {
        "id": 18,
        "name": "Max Measured flow",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "m^3 / s",
        "description": "The maximum flow measured by the meter "
      },
      {
        "id": 20,
        "name": "Flow volume",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "m^3",
        "description": "The cumulative flow volume measured on the flow pipe"
      },
      {
        "id": 21,
        "name": "Return volume",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "m^3",
        "description": "The cumulative flow volume measured on the return pipe"
      },
      {
        "id": 5506,
        "name": "Current Time",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "time",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Unix Time. A signed integer representing the number of seconds since Jan 1st, 1970 in the UTC time zone."
      },
      {
        "id": 5800,
        "name": "Instantaneous active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "W",
        "description": "The current active power"
      },
      {
        "id": 5802,
        "name": "Max Measured active power",
        "operations": "R",
        "instancetype": "multiple",
        "mandatory": true,
        "type": "float",
        "range": "\n        ",
        "units": "W",
        "description": "The maximum active power measured by the sensor since it is ON"
      },
      {
        "id": 5805,
        "name": "Cumulative active power",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Wh",
        "description": "The cumulative active power since the last cumulative energy reset or device start"
      }
    ]
  },
  {
    "name": "Current Loop Output",
    "id": 10258,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "This LwM2M Object provides a representation of a current loop source, which may be used to carry control signals.",
    "resourcedefs": [
      {
        "id": 0,
        "name": "Current Loop Output Current Value",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "3.8-20.5",
        "units": "mA",
        "description": "The current value of the current loop output."
      },
      {
        "id": 5603,
        "name": "Min Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Defined by “Units” resource.",
        "description": "The minimum value that can be measured by the sensor"
      },
      {
        "id": 5604,
        "name": "Max Range Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "Defined by “Units” resource.",
        "description": "The maximum value that can be measured by the sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Measurement Units Definition e.g. “Cel” for Temperature in Celsius."
      },
      {
        "id": 5750,
        "name": "Application Type",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "\n        ",
        "units": "\n        ",
        "description": "The application type of the sensor or actuator as a string, for instance, “Air Pressure”."
      },
      {
        "id": 5821,
        "name": "Current Calibration",
        "operations": "RW",
        "instancetype": "single",
        "mandatory": false,
        "type": "float",
        "range": "\n        ",
        "units": "\n        ",
        "description": "Read or Write the current calibration coefficient"
      }
    ]
  },
  {
    "name": "Weather",
    "id": 22001,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "\nThis Object provides the information to represent weather\n    ",
    "resourcedefs": [
      {
        "id": 21001,
        "name": "Rain",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether it's rainy"
      },
      {
        "id": 21002,
        "name": "Snow",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether it's snowy"
      },
      {
        "id": 21003,
        "name": "Sun",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "boolean",
        "range": "",
        "units": "",
        "description": "Whether it's suuny"
      }
    ]
  },
  {
    "name": "Rainfall",
    "id": 22002,
    "instancetype": "multiple",
    "mandatory": false,
    "description": "\nThis Object provides the information to represent rainfall\n    ",
    "resourcedefs": [
      {
        "id": 5700,
        "name": "Sensor Value",
        "operations": "R",
        "instancetype": "single",
        "mandatory": true,
        "type": "float",
        "range": "",
        "units": "Defined by “Units” resource.",
        "description": "Last or Current Measured Value from the Sensor"
      },
      {
        "id": 5701,
        "name": "Sensor Units",
        "operations": "R",
        "instancetype": "single",
        "mandatory": false,
        "type": "string",
        "range": "",
        "units": "",
        "description": "If present, the type of sensor defined as the UCUM Unit Definition e.g. “Cel” for Temperature in Celcius."
      }
    ]
  }
]
```