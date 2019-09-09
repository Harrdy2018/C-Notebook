## Linux 网络编程
### 进程间通信方式
* 管道(pipe)(包括匿名管道和命名管道)
* 信号(signal)
* 消息队列(queue)
* 共享内存(最快)
* 信号量
* 套接字
### 套接字
```
套接字是更为基础的进程间通信机制，与其他方式不同的是，套接字可用于不同机器之间的进程间通信。
有两种类型的套接字：基于文件的和面向网络的。
(1).Unix套接字是基于文件的，并且拥有一个“家族名字”--AF_UNIX，它代表地址家族(address family)：UNIX。
(2).第二类型的套接字是基于网络的，它也有自己的家族名字--AF_INET，代表地址家族(address family):INTERNET
不管采用哪种地址家族，都有两种不同的套接字连接：面向连接的和无连接的。
(1)面向连接的套接字(SOCK_STREAM)：进行通信前必须建立一个连接，面向连接的通信提供序列化的、可靠地和不重复的数据交付，而没有记录边界。
这意味着每条信息可以被拆分成多个片段，并且每个片段都能确保到达目的地，然后在目的地将信息拼接起来。
实现这种连接类型的主要协议是传输控制协议(TCP)。
(2)无连接的套接字(SOCK_DGRAM)：在通信开始之前并不需要建立连接，在数据传输过程中并无法保证它的顺序性、可靠性或重复性。
然而,数据报确实保存了记录边界,这就意味着消息是以整体发送的,而并非首先分成多个片段。
由于面向连接的套接字所提供的保证,因此它们的设置以及对虚拟电路连接的维护需要大量的开销。然而,数据报不需要这些开销,即它的成本更加“低廉”
实现这种连接类型的主要协议是用户数据报协议(UDP)。
```
### 协议族和地址族
* 协议族 /usr/include/bits/socket.h
```c
/**
 * 协议族就是不同协议的集合，在Linux中，用宏来表示不同的协议族，这个宏的形式是PF开头，比如IPv4协议族为PF_INET,PF的意思是PROTOCOL  FAMILY
*/
/* Protocol families.  */
#define PF_UNSPEC       0       /* Unspecified.  */
#define PF_LOCAL        1       /* Local to host (pipes and file-domain).  */
#define PF_UNIX         PF_LOCAL /* POSIX name for PF_LOCAL.  */
#define PF_FILE         PF_LOCAL /* Another non-standard name for PF_LOCAL.  */
#define PF_INET         2       /* IP protocol family.  */
#define PF_AX25         3       /* Amateur Radio AX.25.  */
#define PF_IPX          4       /* Novell Internet Protocol.  */
#define PF_APPLETALK    5       /* Appletalk DDP.  */
#define PF_NETROM       6       /* Amateur radio NetROM.  */
#define PF_BRIDGE       7       /* Multiprotocol bridge.  */
#define PF_ATMPVC       8       /* ATM PVCs.  */
#define PF_X25          9       /* Reserved for X.25 project.  */
#define PF_INET6        10      /* IP version 6.  */
```
* 地址族 /usr/include/bits/socket.h
```c
/**
 * 地址族就是一个协议族所使用的地址集合，也是用宏来表示不同的地址族，这个宏的形式是AF开头，比如IP地址族为AF_INET,AF的意思是ADDRESS FAMILY
*/
/* Address families.  */
#define AF_UNSPEC       PF_UNSPEC
#define AF_LOCAL        PF_LOCAL
#define AF_UNIX         PF_UNIX
#define AF_FILE         PF_FILE
#define AF_INET         PF_INET
#define AF_AX25         PF_AX25
#define AF_IPX          PF_IPX
#define AF_APPLETALK    PF_APPLETALK
#define AF_NETROM       PF_NETROM
#define AF_BRIDGE       PF_BRIDGE
#define AF_ATMPVC       PF_ATMPVC
#define AF_X25          PF_X25
#define AF_INET6        PF_INET6
```
* 说明
```
地址族和协议族其实是一样的，值也一样，都是用来识别不同协议的，为什么要搞两套东西呢？
这是因为之前UNIX有两种风格系统：BSD系统和POSIX系统，对于BSD系统，一直用的是AF，对于POSIX系统，一直用的是PF。
Linux作为后起之秀，为了兼容，所以两种都支持，这样两种风格的UNIX下的软件就可以在Linux上运行了。
```
### unlink()
* 删除testfile文件，0删除成功；-1删除失败；
```c
#include <stdio.h>
#include <unistd.h>
void main(void){
	int status=unlink("testfile");
	printf("%d\n",status);
}
```
### bzero()
* Set N bytes of S to 0.
* extern void bzero (void *__s, size_t __n) __THROW __nonnull ((1));
```c
#include <stdio.h>
#include <string.h>
void main(void){
        printf("%d\n",'\0');//0
        char str[]="Hello";
        bzero(str,2);
        int i=2;
        while(str[i] != '\0'){
                printf("%c\n",str[i]);
                i++;
        }
        printf("%s\n",&str[2]);//llo
}
```
### 函数
* socket()  /usr/include/sys/socket.h
```c
/* Create a new socket of type TYPE in domain DOMAIN, using
      protocol PROTOCOL.  If PROTOCOL is zero, one is chosen automatically.
      Returns a file descriptor for the new socket, or -1 for errors.  */
/**
 * domain指明所使用的协议族
 * type参数指定socket的类型：SOCK_STREAM 或SOCK_DGRAM
 * protocol通常赋值"0"
 * return:
 * 返回一个整型socket描述符,是一个指向内部数据结构的指针，它指向描述符表入口。
 * 调用Socket函数时，socket执行体将建立一个Socket，实际上"建立一个Socket"意味着为一个Socket数据结构分配存储空间。
*/
extern int socket (int __domain, int __type, int __protocol) __THROW;   
```
```c
#include <stdio.h>
#include <sys/socket.h>
int main(void){
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("%d\n",sockfd);//3
	return 0;
}
```
**********************************************
* bind()  /usr/include/sys/socket.h
```c
//包含了bits/socket.h 所以有结构 struct sockaddr,socklen_t
/**
 * 一旦你有了一个套接口以后，下一步就是把套接口绑定到本地计算机的某一个端口上
 * sockfd是由socket()调用返回的套接口文件描述符。
 * my_addr是指向数据结构sockaddr的指针。数据结构sockaddr中包括了关于你的地址、端口和IP地址的信息。
 * addrlen可以设置成sizeof(structsockaddr)
*/
/* this is the type we use for generic socket address arguments.*/
# define __CONST_SOCKADDR_ARG   const struct sockaddr *
/* Give the socket FD the local address ADDR (which is LEN bytes long).  */
extern int bind (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len) __THROW;
```
* /sys/bits/socket.h
```c
/* Type for length arguments in socket calls.  */
#ifndef __socklen_t_defined
typedef __socklen_t socklen_t;
# define __socklen_t_defined
#endif
/* Get the definition of the macro to define the common sockaddr members.  */
#include <bits/sockaddr.h>
/* Structure describing a generic socket address.  */
struct sockaddr
  {
    __SOCKADDR_COMMON (sa_);    /* Common data: address family and length.  */
    char sa_data[14];           /* Address data.  */
  };
```
* example
```c
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#define MYPORT 3490
/**
 * Structure describing an Internet socket address
 * define include <netinet/in.h>
 * sin_port that is port number
 * sin_addr that is internet address
 * sin_zero that is pad to size of 'struct sockaddr'
 * */
/*
struct sockaddr_in
  {
    __SOCKADDR_COMMON (sin_);
    in_port_t sin_port;                
    struct in_addr sin_addr;            
    unsigned char sin_zero[sizeof (struct sockaddr) -__SOCKADDR_COMMON_SIZE -sizeof (in_port_t) -sizeof (struct in_addr)];
  };*/
int main(void){
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("%d\n",sockfd);
	struct sockaddr_in myAddr;
	myAddr.sin_family=AF_INET;
	myAddr.sin_port=htons(MYPORT);
	myAddr.sin_addr.s_addr=inet_addr("192.168.99.130");
        //bzero define include<string.h>
	bzero(&(myAddr.sin_zero),8);
	int status=bind(sockfd,(struct sockaddr*)&myAddr,sizeof(struct sockaddr));
	printf("bind status %d\n",status);
	return 0;
}
```
*********************************************
* connect() /usr/include/sys/socket.h
```c
//如果出错，bind()也返回-1。
//如果你使用connect()系统调用，那么你不必知道你使用的端口号。当你调用connect()时，它检查套接口是否已经绑定，如果没有，它将会分配一个空闲的端口。
/* Open a connection on socket FD to peer at ADDR (which LEN bytes long).
   For connectionless socket types, just set the default address to send to
   and the only address from which to accept transmissions.
   Return 0 on success, -1 for errors.
   This function is a cancellation point and therefore not marked with
   __THROW.  */
/**
 * 第一个参数还是套接口文件描述符，它是由系统调用socket()返回的。
 * 第二个参数是serv_addr是指向数据结构sockaddr的指针，其中包括目的端口和IP地址。
 * 第三个参数可以使用sizeof(structsockaddr)而获得。
*/
extern int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
```
* example
```c
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#define MYPORT 3491
/**
 * Structure describing an Internet socket address
 * define include <netinet/in.h>
 * sin_port that is port number
 * sin_addr that is internet address
 * sin_zero that is pad to size of 'struct sockaddr'
 * */
/*
struct sockaddr_in
  {
    __SOCKADDR_COMMON (sin_);
    in_port_t sin_port;                
    struct in_addr sin_addr;            
    unsigned char sin_zero[sizeof (struct sockaddr) -__SOCKADDR_COMMON_SIZE -sizeof (in_port_t) -sizeof (struct in_addr)];
  };*/
int main(void){
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("%d\n",sockfd);
	struct sockaddr_in myAddr;
	myAddr.sin_family=AF_INET;
	myAddr.sin_port=htons(MYPORT);
	myAddr.sin_addr.s_addr=inet_addr("192.168.99.130");
        //bzero define include<string.h>
	bzero(&(myAddr.sin_zero),8);
	int status=connect(sockfd,(struct sockaddr*)&myAddr,sizeof(struct sockaddr));
	printf("connect status %d\n",status);
	return 0;
}
```
***********************************************************
* listen() accept() /usr/include/sys/socket.h
```c
/*
如果你希望不连接到远程的主机，也就是说你希望等待一个进入的连接请求，然后再处理它们。这样，你通过首先调用listen()，然后再调用accept()来实现。
第二个参数是进入队列中允许的连接的个数。进入的连接请求在使用系统调用accept()应答之前要在进入队列中等待。这个值是队列中最多可以拥有的请求的个数
当然，在使用系统调用listen()之前，我们需要调用bind()绑定到需要的端口，否则系统内核将会让我们监听一个随机的端口。
所以，如果你希望监听一个端口，下面是应该使用的系统调用的顺序：
socket();
bind();
listen();
accept();
*/
/* Prepare to accept connections on socket FD.
   N connection requests will be queued before further requests are refused.
   Returns 0 on success, -1 for errors.  */
extern int listen (int __fd, int __n) __THROW;
/*
系统调用accept()比较起来有点复杂。在远程的主机可能试图使用connect()连接你使用
listen()正在监听的端口。但此连接将会在队列中等待，直到使用accept()处理它。调用accept()
之后，将会返回一个全新的套接口文件描述符来处理这个单个的连接。这样，对于同一个连接
来说，你就有了两个文件描述符。原先的一个文件描述符正在监听你指定的端口，新的文件描
述符可以用来调用send()和recv()。
第一个参数是正在监听端口的套接口文件描述符。
第二个参数addr是指向本地的数据结构sockaddr_in的指针。调用connect()中的信息将存储在这里。
通过它你可以了解哪个主机在哪个端口呼叫你。
第三个参数同样可以使用sizeof(structsockaddr_in)来获得
*/
/* Await a connection on socket FD.
   When a connection arrives, open a new socket to communicate with it,
   set *ADDR (which is *ADDR_LEN bytes long) to the address of the connecting
   peer and *ADDR_LEN to the address's actual length, and return the
   new socket's descriptor, or -1 for errors.
   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int accept (int __fd, __SOCKADDR_ARG __addr,socklen_t *__restrict __addr_len);
```
****************************************************************************************************
### sockaddr_un
* #include <sys/un.h> 全部文件如下
```c
#include <sys/cdefs.h>
/* Get the definition of the macro to define the common sockaddr members.  */
#include <bits/sockaddr.h>
/* Structure describing the address of an AF_LOCAL (aka AF_UNIX) socket.  */
struct sockaddr_un
  {
    __SOCKADDR_COMMON (sun_);
    char sun_path[108];         /* Path name.  */
  };
#ifdef __USE_MISC
# include <string.h>            /* For prototype of `strlen'.  */
/* Evaluate to actual length of the `sockaddr_un' structure.  */
# define SUN_LEN(ptr) ((size_t) (((struct sockaddr_un *) 0)->sun_path)+ strlen ((ptr)->sun_path))
#endif
```
```
进程间通信的一种方式是使用UNIX套接字，人们在使用这种方式时往往用的不是网络套接字，而是一种称为本地套接字的方式。这样做可以避免为黑客留下后门。
创建
使用套接字函数socket创建，不过传递的参数与网络套接字不同。
域参数应该是PF_LOCAL或者PF_UNIX，而不能用PF_INET之类。
本地套接字的通讯类型应该是SOCK_STREAM或SOCK_DGRAM，协议为默认协议。例如：
 int sockfd;
 sockfd = socket(PF_LOCAL, SOCK_STREAM, 0);
绑定
创建了套接字后，还必须进行绑定才能使用。不同于网络套接字的绑定，本地套接字的绑定的是struct sockaddr_un结构。
struct sockaddr_un结构有两个参数：sun_family、sun_path。
sun_family只能是AF_LOCAL或AF_UNIX，而sun_path是本地文件的路径。
通常将文件放在/tmp目录下。例如：
 struct sockaddr_un sun;
 sun.sun_family = AF_LOCAL;
 strcpy(sun.sun_path, filepath);
 bind(sockfd, (struct sockaddr*)&sun, sizeof(sun));
监听
本地套接字的监听、接受连接操作与网络套接字类似。
连接
连接到一个正在监听的套接字之前，同样需要填充struct sockaddr_un结构，然后调用connect函数。
连接建立成功后，我们就可以像使用网络套接字一样进行发送和接受操作了。甚至还可以将连接设置为非阻塞模式，这里就不赘述了。
```
### sockaddr_in
* #include <netinet/in.h> 部分内容如下
```c
/* Structure describing an Internet socket address.  */
struct sockaddr_in
  {
    __SOCKADDR_COMMON (sin_);
    in_port_t sin_port;                 /* Port number.  */
    struct in_addr sin_addr;            /* Internet address.  */
    /* Pad to size of `struct sockaddr'.  */
    unsigned char sin_zero[sizeof (struct sockaddr)-__SOCKADDR_COMMON_SIZE -sizeof (in_port_t) -sizeof (struct in_addr)];
  };
```
### refer
* #include <bits/sockaddr.h> 全部内容如下
```c
/* POSIX.1g specifies this type name for the `sa_family' member.  */
typedef unsigned short int sa_family_t;
/* This macro is used to declare the initial common members
   of the data types used for socket addresses, `struct sockaddr',
   `struct sockaddr_in', `struct sockaddr_un', etc.  */
#define __SOCKADDR_COMMON(sa_prefix) sa_family_t sa_prefix##family
#define __SOCKADDR_COMMON_SIZE  (sizeof (unsigned short int))
/* Size of struct sockaddr_storage.  */
#define _SS_SIZE 128
```
### 服务端
* server.c
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

void main(void){
	unlink("server_socket");
	int server_sockfd=socket(AF_UNIX,SOCK_STREAM,0);

	//bind
	struct sockaddr_un server_address;
	server_address.sun_family=AF_UNIX;
	strcpy(server_address.sun_path,"server_socket");
	bind(server_sockfd,(struct sockaddr *)&server_address,sizeof(server_address));

	//listen
	listen(server_sockfd,5);

	while(1){
		char ch;
		printf("server is waiting\n");
		struct sockaddr_un client_address;
		int client_len=sizeof(client_address);
		int client_sockfd=accept(server_sockfd,(struct sockaddr *)&server_address,(socklen_t *)&client_len);
		
		read(client_sockfd,&ch,1);
		ch++;

		write(client_sockfd,&ch,1);
		close(client_sockfd);
	}
}
```
* gcc -g server.c -o server.o && ./server.o
* 这时候表明服务端的socket进程监听和等待客户端的连接，使用ps命令可以看到当前的进程正在后台运行，并且处于休眠状态，因此它没有消耗CPU资源
```linux
[harrdy@localhost ~]$ ps -lx | grep './server.o'
0  1000  13234   4184  20   0   4212   344 skb_wa S+   pts/1      0:00 ./server.o
0  1000  13639  13458  20   0 112704   984 pipe_w S+   pts/2      0:00 grep --color=auto ./server.o
[harrdy@localhost ~]$ ps -aux | grep './server.o'
harrdy    14581  0.0  0.0   4212   348 pts/1    S+   13:50   0:00 ./server.o
harrdy    14786  0.0  0.0 112704   984 pts/2    S+   13:55   0:00 grep --color=auto ./server.o
[harrdy@localhost ~]$ ps -a
   PID TTY          TIME CMD
 14581 pts/1    00:00:00 server.o
 14817 pts/2    00:00:00 ps
[harrdy@localhost ~]$ ps -A
   PID TTY          TIME CMD
     1 ?        00:00:01 systemd
     2 ?        00:00:00 kthreadd
     3 ?        00:00:00 ksoftirqd/0
     5 ?        00:00:00 kworker/0:0H
[harrdy@localhost ~]$ ps -A | wc -l
234
[harrdy@localhost ~]$ ps -x | wc -l
82
[harrdy@localhost ~]$ ps -x
   PID TTY      STAT   TIME COMMAND
  2390 ?        Sl     0:00 /usr/bin/gnome-keyring-daemon --daemonize --login
  2426 ?        Ssl    0:00 /usr/libexec/gnome-session-binary --session gnome-classic
  2435 ?        S      0:00 dbus-launch --sh-syntax --exit-with-session
  2436 ?        Ss     0:05 /usr/bin/dbus-daemon --fork --print-pid 5 --print-address 7 --session
  2454 ?        Sl     0:00 /usr/libexec/imsettings-daemon
```
### 客户端
* client.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

void main(void){
	//socket
	int sockfd=socket(AF_UNIX,SOCK_STREAM,0);

	//connect
	struct sockaddr_un address;
	address.sun_family=AF_UNIX;
	strcpy(address.sun_path,"server_socket");
	int result=connect(sockfd,(struct sockaddr *)&address,sizeof(address));
	if(result==-1){
		perror("oops:client1");
		exit(1);
	}
	
	char ch='A';
	write(sockfd,&ch,1);
	read(sockfd,&ch,1);
	printf("char from server = %c \n",ch);
	close(sockfd);
	//exit #include <stdlib.h>
	exit(0);
}
```
* gcc -g client.c -o client.o && ./client.o