## docker
### 安装镜像加速器(华为云、阿里云)
* cat /etc/docker/daemon.json
```json
{
  "registry-mirrors": ["https://4979fccf8c8a4d1ea56fffbd671e92a7.mirror.swr.myhuaweicloud.com", "https://pbrojcu0.mirror.aliyuncs.com"]
}
```
* sudo systemctl daemon-reload
* sudo systemctl restart docker
* whereis docker
```sh
docker: /usr/bin/docker /etc/docker /usr/share/man/man1/docker.1.gz
```
* docker info
```sh
Docker Root Dir: /var/lib/docker   #important
Debug Mode (client): false
Debug Mode (server): false
Registry: https://index.docker.io/v1/
Labels:
Experimental: false
Insecure Registries:
 127.0.0.0/8
Registry Mirrors:                #important
 https://4979fccf8c8a4d1ea56fffbd671e92a7.mirror.swr.myhuaweicloud.com/
 https://pbrojcu0.mirror.aliyuncs.com/
```
### docker 启动与停止
* systemctl start docker
* systemctl stop docker
* systemctl restart docker
* systemctl status docker
* systemctl enable docker
* systemctl unenable docker
* docker info
* docker --help
### docker 镜像相关命令
* docker history 镜像   展示一个镜像构成历史
* docker images  <==> dcoker image ls
* docker search mysql
* docker pull mysql
* docker rmi mysql
* docker inspect mysql 某个镜像详细信息
### 容器创建与启动
* docker ps --latest
* docker ps --all
* docker run -it --name mytomcat tomcat /bin/bash
* docker run -di --name mytomcat2 tomcat /bin/bash 守护方式创建容器
* docker exec -it mytomcat2 /bin/bash 在一个运行的容器执行命令
### 容器命令
* docker stop 容器
* docker start 容器
* docker rm 容器
* docker rm -f $(docker ps -q -a) 删除所有容器
* docker logs -f 容器 查看启动日志 方便调试 监听
### 容器文件拷贝
* docker cp test.txt eaf5799fdf3c:/usr/local
* docker cp eaf5799fdf3c:/usr/local/test.txt ./
### 目录挂载
* 创建一个卷 docker volume create ubuntu_test
* 查看卷 docker volume ls
* 查看卷的详细信息 docker volume inspect ubuntu_test
* --mount 初始化以容器为主
* docker run -d -it --name myubuntu_test --mount src=ubuntu_test,dst=/usr/local/test ubuntu:18.04
#### other
* 初始化以宿主机为主
* docker run -d -it --name myubuntu -v /home/harrdy/Desktop/:/data ubuntu:18.04
#### 企业级命令
* -e 向容器传递环境变量
* --privileged 使用该参数，container内的root拥有真正的root权限
* --rm 退出容器时会自动将其删除
* docker run -v /home/harrdy:/data -e HOST_IP=192.168.99.132 -e NAME=HARRDY --privileged -it --rm ubuntu:18.04 /bin/bash
