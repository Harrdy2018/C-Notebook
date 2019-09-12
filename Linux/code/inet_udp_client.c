#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
/*
基于UDP面向无连接的socket编程cient：
创建套接字socket（socket）
向服务器发送数据（sendto）
释放套接字资源（close）
*/
void main(void) {
	//create client socket
	int c_sockfd= socket(AF_INET, SOCK_DGRAM, 0);
    	if (c_sockfd == -1){
		perror("the client create socket");
		exit(1);
	}

    	struct sockaddr_in addr;
    	char *ip="0.0.0.0";
    	addr.sin_family = AF_INET;
    	addr.sin_port = htons(2001);
    	inet_aton(ip, &addr.sin_addr);
    
    	printf("开始连续三次发送数据\n");
    	char msg1[] = "Hi";
    	char msg2[] = "Hello";
    	char msg3[] = "Nice to meet you";
    	sendto(c_sockfd, msg1, sizeof(msg1), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr));
    	sendto(c_sockfd, msg2, sizeof(msg2), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr));
    	sendto(c_sockfd, msg3, sizeof(msg3), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr));
    
    	printf("关闭UDP套接字\n");
    	close(c_sockfd);
}