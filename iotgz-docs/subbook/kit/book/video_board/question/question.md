# 常见问题
1、视频开发板文件内容不能保存，开发板重启后修改内容丢失？
答：开发板采用的自读文件系统。用户可在/mnt/mtd目录下保存自己文件或数据。

2、开发板不能连接WiFi？
答：不能连接wifi可能原因：1）wifi与usb的共用拨码开关未设置到wifi。2）未修改wifi信息，用户可在/usr/onenet
目录下找到wifi.sh脚本，可将其复制到/mnt/mtd目录下，并修改/mnt/mtd下的wifi.sh脚本中的wifi信息

3、开发板不能连接外网或者平台？
答：开发板连接外网需要设置相应网关




