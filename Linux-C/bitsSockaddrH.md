## include <bits/sockaddr.h>
* 定义的宏用于申明socket地址初始化共同的成员
* struct sockaddr
* struct sockaddr_in
* struct sockaddr_un
```c
typedef unsigned short int sa_family_t;
#define	__SOCKADDR_COMMON(sa_prefix) \
  sa_family_t sa_prefix##family
  
#define __SOCKADDR_COMMON_SIZE	(sizeof (unsigned short int))

/* Size of struct sockaddr_storage.  */
#define _SS_SIZE 128
#endif
```