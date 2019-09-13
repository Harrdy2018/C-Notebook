/*
准备工作：
yum -y install xinetd
修改配置文件 /etc/xinetd.d/daytime-stream 
# This is for quick on or off of the service
	disable		= no
service xinetd restart
service xinetd status
netstat -ant | grep '13'
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
void
main(int argc,char **argv){
	if(argc!=2){
		perror("usage: a.o <IPaddress>");
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		perror("socket error");
		exit(1);
	}
	struct sockaddr_in c_sock_addr;
	bzero(&c_sock_addr,sizeof(c_sock_addr));
	c_sock_addr.sin_family=AF_INET;
	c_sock_addr.sin_port=htons(13);
	inet_pton(AF_INET,argv[1],&c_sock_addr.sin_addr);
	connect(sockfd,(struct sockaddr *)&c_sock_addr,sizeof(c_sock_addr));
	char buffer[1024];
	int n=read(sockfd,buffer,1024);
	printf("%s\n",buffer);
	exit(0);
}
/*
[harrdy@localhost Desktop]$ gcc -g test.c -o test.o && ./test.o 192.168.99.131
13 SEP 2019 13:24:13 CST
*/