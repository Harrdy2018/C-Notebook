#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
/*
基于TCP面向连接的socket编程的client：
创建套接字socket（socket）
向服务器发出连接请求（connect）
请求连接后与服务器进行通信操作（send/recv）
释放套接字资源（close）
*/
void main(void) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd==-1) {
        perror("socket error");
    }

    struct sockaddr_in t_sockaddr;
    memset(&t_sockaddr, 0, sizeof(struct sockaddr_in));
    t_sockaddr.sin_family = AF_INET;
    t_sockaddr.sin_port = htons(3000);
    inet_pton(AF_INET,"0.0.0.0", &t_sockaddr.sin_addr);
	
    int status=connect(socket_fd, (struct sockaddr*)&t_sockaddr, sizeof(struct sockaddr));
    if(status==-1) {
        perror("connect error");
        exit(1);
    }
	
    //communication
    char str[5]= "hello";
    int ret=send(socket_fd, str, sizeof(str), 0);
    if(ret==-1) {
        perror("send message error");
        exit(1);
    }
    char info[6];
    read(socket_fd,info,6);
    info[7]='\0';
    printf("receive info from server is %s\n",info);
    close(socket_fd);
}