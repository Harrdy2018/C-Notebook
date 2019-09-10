## size_t
* C语言中，此类型位于头文件stddef.h中，而在C++中，则位于cstddef中
* 类型应为unsigned int，在64位系统中为 long unsigned int
## ssize_t
```c
#ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
#endif /* sys/types.h */
```
```c
#if __WORDSIZE == 32
# define __SQUAD_TYPE           __quad_t
# define __UQUAD_TYPE           __u_quad_t
# define __SWORD_TYPE           int
# define __UWORD_TYPE           unsigned int
# define __SLONG32_TYPE         long int
# define __ULONG32_TYPE         unsigned long int
# define __S64_TYPE             __quad_t
# define __U64_TYPE             __u_quad_t
/* We want __extension__ before typedef's that use nonstandard base types
   such as `long long' in C89 mode.  */
# define __STD_TYPE             __extension__ typedef
#elif __WORDSIZE == 64
# define __SQUAD_TYPE           long int
# define __UQUAD_TYPE           unsigned long int
# define __SWORD_TYPE           long int
# define __UWORD_TYPE           unsigned long int
# define __SLONG32_TYPE         int
# define __ULONG32_TYPE         unsigned int
# define __S64_TYPE             long int
# define __U64_TYPE             unsigned long int
/* No need to mark the typedef with __extension__.   */
# define __STD_TYPE             typedef
#else
# error
#endif

__STD_TYPE  __SSIZE_T_TYPE   __ssize_t; /* Type of a byte count, or error.  */
/* bits/types.h */
```
```c
#define __SSIZE_T_TYPE          __SWORD_TYPE
/* bits/typesizes.h */
```
* 第一步找到 typedef __ssize_t ssize_t;
* 相当于     __STD_TYPE  __SSIZE_T_TYPE   ssize_t;
* 相当于     typedef __SSIZE_T_TYPE   ssize_t
* 相当于     typedef  __SWORD_TYPE  ssize_t
* 32位系统   typedef int ssize_t
* 64位系统   typedef long int ssize_t