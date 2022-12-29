# Manual for the Use of Management Console

** 1. Creating Products**

Create RTMP products in OneNET Developer Center

![pic1](/images\vedio-image\管理控制台01.png)

** 2. Add/Create Devices, Take Video Private Protocol as an Example **

1. Automatic Creation

SDK interface (``ont_device_connect``) can be used to automatically create devices when connecting authentication through product registration code.

![pic1](/images\vedio-image\管理控制台02.png)

2. Manual creation

You can create devices on the management page

![pic1](/images\vedio-image\管理控制台03.png)


** 3. Add/Create Video Channels**

1. Create by sdk-c

See specifically the SDK interface ```ont_video_dev_add_channel'.```

2. Manual creation

Channel creation can be done on administrative pages

![pic1](/images\vedio-image\管理控制台04.png)


** IV. Equipment Access**

Use SDK interface (``ont_device_connect``) for device access. After the connection authentication is successful, you can see the device online on the page.

![pic1](/images\vedio-image\管理控制台05.png)


** V. Real-time Video Playing**

![pic1](/images\vedio-image\管理控制台06.png)


** VI. Remote Local History Video Play**

Click the History Video Button on the Channel List

![pic1](/images\vedio-image\管理控制台07.png)


The page queries remotely and displays a list of local videos:

![pic1](/images\vedio-image\管理控制台08.png)


The list here is sent to the device through instructions, and the list reported by the device. Reference can be made to the SDK callback interface (``t_ont_video_dev_query_files').

** VII. Apikey Rights Management**

Apikey Used for Group Management of Video Channel Playing Rights

Add apikey

![pic1](/images\vedio-image\管理控制台09.png)


Associated Video Channel

![pic1](/images\vedio-image\管理控制台10.png)


Cancel Association

![pic1](/images\vedio-image\管理控制台11.png)


** VIII, Real-time Query**

Real-time push-flow query

![pic1](/images\vedio-image\管理控制台12.png)


Real-time playback query

![pic1](/images\vedio-image\管理控制台13.png)