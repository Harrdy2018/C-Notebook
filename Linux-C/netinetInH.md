### include <netinet/in.h>
* 网络地址
```c
/* Internet address.  */
typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
```
* 网络套接字地址
```c
/* Type to represent a port.  */
typedef uint16_t in_port_t;
/* Structure describing an Internet socket address.  */
struct sockaddr_in
  {
    __SOCKADDR_COMMON (sin_);
    in_port_t sin_port;         /* Port number.  */
    struct in_addr sin_addr;        /* Internet address.  */
    /* Pad to size of `struct sockaddr'.  */
    unsigned char sin_zero[sizeof (struct sockaddr) - __SOCKADDR_COMMON_SIZE -sizeof (in_port_t) -sizeof (struct in_addr)];
  };
```