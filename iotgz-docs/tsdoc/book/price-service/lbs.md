# OneNET LBS

## Product introduction

OneNET LBS is a base station location service launched by China Mobile Internet of Things Co., Ltd. based on OneNET platform. It is suitable for locating all kinds of Internet of Things devices connected to OneNET. Users can obtain corresponding geographic location information by reporting the base station information connected by Internet of Things devices. Details can be found in[Introduction to Location Capability Services](/book/other-service/onenet-lbs/introduction.md).

> The pricing criteria described in this document are applicable only to OneNET LBS services and not to location services other than this service. The final interpretation of the pricing criteria and strategies is vested in ZhongShi Internet of Things Limited.

## Valuation of products

Billing Unit
- According to the number of positioning charges, users report the relevant information of base station to the platform, and the amount of positioning usage is recorded as one time after the completion of the report and successful positioning.
- History track query and nearest location query are free to use.

Billing unit price
- The validity period of the paid purchasing resource packages is the billing month. The starting point of the billing cycle is the successful time of payment, and the end point is the first 00:00:00 after a month. The purchased resource packages are not used up after expiration and will automatically expire.

| Service Item | Location Number | Unit Price | Validity Period|
|:-|:-|:-|:-|:-|
| Basic Package | Daily Quota: 3 million times | Free | Billing Day|
| Billing unit price | 10,000 times | 12 yuan | Billing month|

Payment Rules

- The platform adopts prepaid system, that is, purchasing positioned usage (resource packages), which can be purchased multiple times, consumed in sequence, preferring to use the daily free quota. After the free daily quota is consumed, the payment balance will be consumed in the order of purchase.


## Examples of billing

- Example 1: Users do not purchase paid resource packages. When the number of locations of the user exceeds 3 million times a day, the LBS service automatically fails. The next day, the 00:00:00 service comes into effect again, and the basic packages are given 3 million times to recalculate.
- Example 2: User purchases 10 resource packages, that is, 100,000 locations. When the user locates 3.05 million times a day, the user purchases 50,000 locations, leaving 50,000 unused locations.
- Example 3: The user purchased a resource bundle A on February 18 and another resource bundle B on February 20. If the device reports location information data points on February 21, the priority is: base bundle - > resource bundle A - > resource bundle B.
- Example 4: If the successful payment time of resource packages purchased by users is 17:00:00 on January 28, 2019, then the failure time of resource packages is 0:00:00 on March 1, 2019.