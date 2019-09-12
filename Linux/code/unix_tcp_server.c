#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

void main(void){
	unlink("socket_file");

    //create socket
	int server_sockfd=socket(AF_UNIX,SOCK_STREAM,0);

	//bind
	struct sockaddr_un server_address;
	server_address.sun_family=AF_UNIX;
	strcpy(server_address.sun_path,"socket_file");
	bind(server_sockfd,(struct sockaddr *)&server_address,sizeof(server_address));

	//listen
	listen(server_sockfd,5);
	/*
	功能：accept函数从listen的已完成连接队列中返回下一个已完成连接, 也就是对端的套接字, 一个新的套接字
	      当已完成连接队列的下一个完成连接是空, 那么accept函数将被阻塞.
    extern int accept (int __fd, __SOCKADDR_ARG __addr,socklen_t *__restrict __addr_len);
	return：调用成功时返回: 1. __addr: 客户端进程的协议地址和地址大小 2. 新套接字描述符
	*/

    printf("server is waiting\n");
	while(1){
		struct sockaddr_un c_sock_addr;
        int c_sock_len=sizeof(c_sock_addr);
		int accept_sockfd=accept(server_sockfd,(struct sockaddr *)&c_sock_addr,(socklen_t *)&c_sock_len);
        if(accept_sockfd != -1){
            char ch;
	  	    read(accept_sockfd,&ch,1);
            printf("I read %c char from client.\n",ch);
		    ch++;
		    write(accept_sockfd,&ch,1);
            printf("I write %c char to client.\n",ch);
		    close(accept_sockfd);
        }else{
            perror("server");
        }
	}
}