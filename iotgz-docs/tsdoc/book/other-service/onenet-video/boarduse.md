# Development Board Live Broadcast Experience

* Usart/Development Board Start-up*

Open the super terminal. Plug in the export line connected with serial port (if notebook computer has no serial port, you can use serial port-USB converter), development board start, super terminal output interface. If there is no relevant experience, please refer to Chapter 1.3.2 of Appendix 1.

![pic](/images/vedio-image/开发板直播体验01.png)

Interaction can be done by inputting related commands through super terminals, such as LS

![pic](/images/vedio-image/开发板直播体验02.png)

* Keyboard*

Enter the command. / saradc_test to execute the saradc_test program and test the keys.

![pic](/images/vedio-image/开发板直播体验03.png)

* Ethernet*

Setting IP address through ifconfig and testing network through ping command

![pic](/images/vedio-image/开发板直播体验04.png)

![pic](/images/vedio-image/开发板直播体验05.png)

*Wifi*

Access to WiFi hotspots, where Baiduiot is the name of the hotspot, Linux IOT123 is the WiFi password, need to replace their WiFi information.

```
./wpa_passphrase Baiduiot "LinuxIOT123" >> /usr/wpa_supplicant.conf
./wpa_supplicant -Dwext -ira0 -c/usr/wpa_supplicant.conf -B
```

![pic](/images/vedio-image/开发板直播体验06.png)

Get IP

```
ifconfig ra0 `udhcpc -i  ra0 | grep 'Lease of'| awk '{print $3}'`
route add default gw `ifconfig|grep 'inet addr'|grep -v '127.0.0.1'|cut -d: -f2 |awk '{print $1}'|awk '{split($0,ip,"." ); printf "%s.%s.%s.1\n",ip[1],ip[2],ip[3] }'`
```

![pic](/images/vedio-image/开发板直播体验07.png)

test

![pic](/images/vedio-image/开发板直播体验08.png)

* TF card*

Mount TF card by command ``mount-t'vfat/dev/mmcblk0p1/usr/tfcar```d

![pic](/images/vedio-image/开发板直播体验09.png)

* Audio*

Test the input and output of audio by executing audio_live sound

![pic](/images/vedio-image/开发板直播体验10.png)

* Video*

Enter / MNT / MTD and execute rtspd program. Real-time video can be played on PC through VLC and other players.

![pic](/images/vedio-image/开发板直播体验11.png)

![pic](/images/vedio-image/开发板直播体验12.png)

** Introduction to Functions**

Functional demonstration should be completed by interacting with the development board. If you have no experience in using or developing embedded linux, please read Appendix 1 first and complete the installation of the super terminal according to Appendix 1.3.2.

* Setting up the network*

The development board configures WiFi and wired network communication modes, and developers can freely choose any one.

Cable Network

Setting IP Address Command: ifconfig eth0 192.168.200.172

Set up the network command: route add default gw 192.168.200.1

*WIFI*

Enter the / usr / onenet directory, open wifi. sh, change the WiFi name and password to the WiFi name and password you need to set, and save.

![pic](/images/vedio-image/开发板直播体验13.png)

Execute the wifi. sh script to connect to wifi. SH wifi.sh

* Note: All experiential experiments need the network, so you must set up the network first. *

** Video Live Experience**

Objective: To enable users to quickly experience video capabilities.

OneNET Video Experience Experiment Function:

Based on the official SDK, the function of live video broadcasting is realized.

Experience process:

Follow the steps described in[https://open.iot.10086.cn/doc/art 388.html 68](https://open.iot.10086.cn/doc/art388.html#68), create video products and devices in onenet, and obtain product ID and registration code. Product Management Page Gets Product ID, Registration Code

![pic](/images/vedio-image/开发板直播体验14.png)

Enter Development Board Directory/usr/onenet

Modify the config.json file using the VI config.json command

![pic](/images/vedio-image/开发板直播体验15.png)

Modify the value of product ID and pass to the product ID of the video device created above. The registration code, device ID can be set to 0, and ID can be set independently.

Run. / sample_test

![pic](/images/vedio-image/开发板直播体验16.png)

Video can be viewed through onenet video management page