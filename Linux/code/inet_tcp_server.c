#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
/*
基于TCP面向连接的socket编程server
创建套接字socket（socket）
创建的套接字绑定（bind）到本地的地址和端口上
设置套接字的状态为监听（listen），准备接受客户端的连接请求
接受请求（accpet），同时返回得到一个用于连接的新套接字
使用这个新套接字进行通信（通信函数使用send/recv）
通信完毕，释放套接字资源（close）
*/

void main(void) {
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd==-1) {
        perror("socket error");
    }

    struct sockaddr_in t_sockaddr;
    memset(&t_sockaddr, 0, sizeof(t_sockaddr));
    t_sockaddr.sin_family = AF_INET;
    t_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    t_sockaddr.sin_port = htons(3000);

    
    int ret= bind(listen_fd,(struct sockaddr *) &t_sockaddr,sizeof(t_sockaddr));
    if (ret==-1) {
        perror("bind socket error");
	exit(1);
    }

    ret = listen(listen_fd, 1024);
    if (ret==-1) {
        perror("listen error");
    }
	
    printf("the tcp server is running>>>\n");
    while(1){
	struct sockaddr_in addr;
	int len=sizeof(addr);
        int conn_fd = accept(listen_fd, (struct sockaddr*)&addr, (socklen_t *)&len);
        if(conn_fd==-1) {
            perror("accpet socket error");
            continue;
        }
	
	//communication
	char buff[5];
        int recv_len = recv(conn_fd, buff, 5, 0);
        if (recv_len==-1) {
            perror("recv error");
            continue;
        }
        buff[6] = '\0';
        printf("recv message from client: %s\n", buff);
	char str[6]="Harrdy";
        sleep(5);
	write(conn_fd,str,6);
        close(conn_fd);
    }
    close(listen_fd);
}