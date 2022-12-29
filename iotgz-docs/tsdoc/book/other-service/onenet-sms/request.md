# Call description

### Call mode

The short MMS capability platform API is a Web service interface designed using HTTP and following REST principles. You can interact with REST API using almost any client and any programming language. Simple HTTP GET/POST requests can be easily accessed and used.

Note: In order to ensure the security of your account and information, it is recommended to add the IP address you want to use to the IP whitelist list on the account settings page after registration.

### Uniform Request Format

BASE URL：
http://api.sms.heclouds.com

URL format:
/ {Interface Name}? {Parameters}
Detailed parameters are shown in API instructions for each interface.
HTTP header information:
Accept:text/plain;charset=utf-8;
Content-Type:application/x-www-form-urlencoded;charset=utf-8;

### Coding

Unified use of UTF-8 encoding, please ensure that your file encoding and the format of the incoming parameters.