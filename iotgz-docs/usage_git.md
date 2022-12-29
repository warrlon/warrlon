参考文档： 
[文档编写帮助](http://10.12.3.198/kfptb/portal/web_portal/onenetv4_doc/-/blob/master/usage.md)	
[文档子模块编写注意事项](http://10.12.3.198/kfptb/portal/web_portal/onenetv4_doc/-/blob/master/usage_subbook.md)	
[md文档示例](http://10.12.3.198/kfptb/portal/web_portal/onenetv4_doc/-/blob/master/demo.md)


准备工作，安装git以及markdown编辑器（推荐vs code）

初次使用：

到文档目录（自定）下启动git控制台
1、克隆整个仓库到本地
（初次使用会要求输入用户名密码，用户名为邮箱，密码为登录密码）

2、切换到工作目录
输入：cd iotgz-docs/

3、当前默认为master分支，需要切换到工作分支（分支是自己创建，或者使用已有的分支，注意2点，1、创建分支从master分支创建出来，2、不熟悉就使用已有的分支）
以mqtt为例
输入：git checkout mqtt

4、使用markdown编辑器，进行文档编辑工作 

5、上传改动到分支
  5.1  输入 git staus 查看改动状态（可选）
  5.2  输入 git add .
  5.3  输入 git commit -m "修改说明"
  5.4  输入 git pull
  5.5  输入 git push  同步到远程仓库

后续使用：
1、到文档目录/iotgz-docs 中，启动git控制台

2、将远端仓库同步到本地
输入：git pull

3、切换到工作分支，以mqtt为例
输入：git checkout mqtt


4、使用markdown编辑器，进行文档编辑工作

5、上传改动到分支    
  5.1  输入 git staus 查看改动状态（可选）    
  5.2  输入 git add .    
  5.3  输入 git commit -m "修改说明"    
  5.4  输入 git pull    
  5.5  输入 git push  同步到远程仓库    


注意：
1、各产品经理负责各分支的文档更新工作，应尽量避免多人修改同一个文档的场景
2、修改本地文档时，需要确认是处于自己的分支
