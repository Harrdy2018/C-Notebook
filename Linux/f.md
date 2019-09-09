## 文件描述符
* extern void perror (const char *__s);
* Print a message describing the meaning of the value of errno
```c
#include <stdio.h>
int main(){
    perror("error");//error: No error
}
```
* 对于socket文件描述符的取值范围和分配进行了探索
```
在系统头文件posix_types.h中定义了文件描述符的最大数量1024，意味着文件描述符的取值范围是0~1023，
并且0、1、2已经被分配了，0表示标准输入，1表示标准输出，2表示标准错误输出，而通过socket()分配的socket文件描述符的取值范围是从3~1023的。
普通文件描述符和socket文件描述符是统一分配的，所以不会冲突，总数有限。如果socket()循环执行1020次，会从3分配到1023，如果继续调用socket()，就会返回-1，因为超过了文件描述符上限。如果此时调用close()关闭文件描述符，那么再调用socket()，就可以继续成功分配了，并且是从小到大从第一个没有被分配的文件描述符开始分配。
```
* #include <linux/posix_types.h>
```c
#include <linux/stddef.h>
/*
 * This allows for 1024 file descriptors: if NR_OPEN is ever grown
 * beyond that you'll have to change this too. But 1024 fd's seem to be
 * enough even for such "real" unices like OSF/1, so hopefully this is
 * one limit that doesn't have to be changed [again].
 *
 * Note that POSIX wants the FD_CLEAR(fd,fdsetp) defines to be in
 * <sys/time.h> (and thus <linux/time.h>) - but this is a more logical
 * place for them. Solved by having dummy defines in <sys/time.h>.
 */
/*
 * This macro may have been defined in <gnu/types.h>. But we always
 * use the one here.
 */
#undef __FD_SETSIZE
#define __FD_SETSIZE    1024
typedef struct {
        unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
} __kernel_fd_set;
/* Type of a signal handler.  */
typedef void (*__kernel_sighandler_t)(int);
/* Type of a SYSV IPC key.  */
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
#include <asm/posix_types.h>
```
* test
```c
#include <stdio.h>
#include <sys/socket.h>
void main(void){
	for(int i=0;i<1024;i++){
 		int fd=socket(PF_INET,SOCK_STREAM,0);
	    	printf("%d\n",fd);
		if(fd<0){
			perror("fail to socket");
		}	
	}	
}
```
* 结果以及解释
```
3
直到
1023
-1
fail to socket: Too many open files
-1
fail to socket: Too many open files
-1
fail to socket: Too many open files

说明socket()从3~1023分配，若返回-1，表示此时已经没有空闲的文件描述符了。
```
* test2
```c
#include <stdio.h>
#include <sys/socket.h>
void main(void){
	for(int i=0;i<1024;i++){
 		int fd=socket(PF_INET,SOCK_STREAM,0);
	    	printf("%d\n",fd);
		if(fd<0){
			perror("fail to socket");
		}	
	}
	close(1023);
	close(100);
	close(102);
	close(3);
	for(int i=0;i<5;i++){
 		int fd=socket(PF_INET,SOCK_STREAM,0);
	    	printf("%d\n",fd);
		if(fd<0){
			perror("fail to socket");
		}	
	}
}
```
* 结果以及解释
```
1021
1022
1023
-1
fail to socket: Too many open files
-1
fail to socket: Too many open files
-1
fail to socket: Too many open files
3
100
102
1023
-1
fail to socket: Too many open files

可以发现，关闭了3，100，102，1023，再次分配fd的时候，按照从小到大顺次分配未被分配的描述符。
具体的算法不知道，但是很巧妙，这样可以保证文件描述符的数量不会超过系统限制，循环使用文件描述符。
```