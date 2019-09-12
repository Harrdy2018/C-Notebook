#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
/*
基于UDP面向无连接的socket编程server：
创建套接字socket （socket）
将套接字绑定（bind）到一个本地地址和端口上
等待接收数据（recvfrom）
释放套接字资源（close）
*/
void main(void) {
	//create server socket
	int s_sockfd= socket(AF_INET, SOCK_DGRAM, 0);
    	if (s_sockfd == -1){
		perror("the server create socket");
		exit(1);
	}

	//bind
	socklen_t len = sizeof(struct sockaddr);
	struct sockaddr_in addr,recv_addr;
    	addr.sin_family = AF_INET;
    	addr.sin_port = htons(2001);
    	addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	int status=bind(s_sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr));
    	if (status==-1){
		perror("the server bind status");
	}

	printf("the UDP server is running>>>\n");
	while(1){
		char buffer[512];
        	sleep(5);
		memset(buffer, 0, 512);
        	ssize_t recv_len = recvfrom(s_sockfd,
                                    buffer,
                                    sizeof(buffer),
                                    0,
                                    (struct sockaddr*)&recv_addr,
                                    &len);
        	if (recv_len <= 0) {
            		perror("接收数据失败");
            		break;
        	}
        	printf("recv: %s\n",buffer);	
    	}
  	printf("关闭UDP套接字\n");
 	close(s_sockfd);
}