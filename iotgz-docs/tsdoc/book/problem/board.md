# Technical Problems of Development Board

** 1. Do you have built-in programs for the newly arrived development board? * *

Answer: Yes, there are two-dimensional codes on the back of the development board, which can be experienced by sweeping.

** 2. Where to download development board information and routine code**

Answer: Community - > Development Board Area[https://open.iot.10086.cn/bbs/thread-863-1-1.html](https://open.iot.10086.cn/bbs/thread-863-1-1.html)

** 3. How does the development board download the code **

Answer: Kirin board can download code through ST-Link, Mini board can download code through ST-Link or USART1.

** 4. How does the development board connect with the platform **

Answer: WiFi module and GSM module

** 5. Is the Network Module Built-in OneNET Protocol or Use Universal AT Instruction**

Answer: The routine uses software protocol, so the general AT instruction can be used without restriction of network module.

** 6. What is the development board software development environment**

Answer: Keil MDK, Gcc, IAR all work; Keil MDK5 is used as routine.

** 7. Where to start learning after downloading materials and routines**

Answer: Developers who are not familiar with IOT can start with OneNET basic routines and gradually become familiar with IOT device-side development process; in each routine catalogue, there are corresponding development materials, and before learning, they should first check the documents in the catalogue.

** 8. The development board has the problem of WiFi disconnection. The code upload is successful, but it just can't connect? * *

Answer: If the card is in AT + CWJAP command, you need to set WiFi to STAION mode or STATION + AP dual mode. The specific command is AT + CWMODE, then you can use AT + CWJAP to connect WiFi hotspots. Parameters can be consulted in the AT instruction document. Because some WiFi modules may not have CWMODE installed in the factory, they need to be set manually.