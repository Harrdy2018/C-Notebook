## include <sys/socket.h>
* 套接字函数申明 extern int socket (int __domain, int __type, int __protocol) __THROW;
```c
// 使用协议，在协议族里创建一种类型的套接字
// 如果协议是0,协议将会被自动选择，如果成功，返回套接字的文件描述符，否则，返回-1


// domain 有两种，PF_INET AF_INET 定义在<bits/socket.h>
/* Protocol families.  */
#define PF_UNSPEC   0   /* Unspecified.  */
#define PF_LOCAL    1   /* Local to host (pipes and file-domain).  */
#define PF_UNIX     PF_LOCAL /* POSIX name for PF_LOCAL.  */
#define PF_FILE     PF_LOCAL /* Another non-standard name for PF_LOCAL.  */
#define PF_INET     2   /* IP协议族*/
/* Address families.  */
#define AF_UNSPEC   PF_UNSPEC
#define AF_LOCAL    PF_LOCAL
#define AF_UNIX     PF_UNIX
#define AF_FILE     PF_FILE
#define AF_INET     PF_INET


// socket类型，定义在<bits/socket_type.h>
enum __socket_type
{
  SOCK_STREAM = 1,      /*安全的，基于连接的字节流*/
  #define SOCK_STREAM SOCK_STREAM
  SOCK_DGRAM = 2,       /*无连接的，不安全的，固定长度的数据报*/
  #define SOCK_DGRAM SOCK_DGRAM
  /*后面还有很多套接字类型*/
};
```