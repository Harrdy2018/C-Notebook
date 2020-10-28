### 工具使用
* ftpget/ftpput 指令
```
ftpget -u username -p password 192.168.100.110 source target
将192.168.100.110的source文件下载到本地，并以target文件保存
ftpput -u username -p password 192.168.100.110 target source
将本地的source文件推到 192.168.100.110 上，并以target文件保存

username ：用户名
password ：密码
192.168.100.110  ：远程IP
```