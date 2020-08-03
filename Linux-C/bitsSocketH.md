## include <bits/socket.h>
```c
/* Get the definition of the macro to define the common sockaddr members.  */
#include <bits/sockaddr.h>
/* Structure describing a generic socket address.  */
struct sockaddr
  {
    __SOCKADDR_COMMON (sa_);    /* Common data: address family and length.  */
    char sa_data[14];       /* Address data.  */
  };
```
### error 宏 生成一个编译错误信息(如果成立，编译是通不过的)
```c
#ifndef _SYS_SOCKET_H
#error "Never include <bits/socket.h> directly; use <sys/socket.h> instead."
#endif
```