#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

void main(void){
	//create socket
	int sockfd=socket(AF_UNIX,SOCK_STREAM,0);

	//connect
	struct sockaddr_un c_sock_addr;
	c_sock_addr.sun_family=AF_UNIX;
	strcpy(c_sock_addr.sun_path,"socket_file");
	int status=connect(sockfd,(struct sockaddr *)&c_sock_addr,sizeof(c_sock_addr));
	if(status==-1){
		perror("client");
		exit(1);
	}
	
	char ch='A';
	write(sockfd,&ch,1);
    printf("I have write %c char to server.\n",ch);
	read(sockfd,&ch,1);
	printf("char from server is %c \n",ch);
	close(sockfd);
	//exit #include <stdlib.h>
	exit(0);
}