## makefile 知识
* make -f Makefile 等价于 make example
* make clean
```Makefile
# target:dependence
example:test.o
	gcc -g test.o -o example
test.o:test.s
	gcc -c test.s -o test.o
test.s:test.i
	gcc -S test.i -o test.s
test.i:test.c
	gcc -E -C test.c -o test.i
clean:
	rm -rf test.i test.s test.o example
```
```Makefile
# target:dependence
# 定义变量并引用
# %通配符
# @变量获取target
# <变量获取第一个dependence
# ^变量获取所有dependence
SRC=test.o other.o other.h
example:test.o
	gcc -g test.o -o example
	echo $@
	echo $<
	echo $^
test.o:test.s
	gcc -c test.s -o test.o
test.s:test.i
	gcc -S test.i -o test.s
test.i:test.c
	gcc -E -C test.c -o test.i
clean:
	rm -rf test.i test.s test.o example
debug:
	echo ${SRC}
	echo $(SRC)
	echo ${PWD}
```
### 一个多文件编译例子
```sh
[root@localhost mytest]# tree ../mytest/
../mytest/
├── app
├── build
│   ├── hello.o
│   └── main.o
├── lib
│   └── hello.h
├── Makefile
└── src
    ├── hello.c
    └── main.c

3 directories, 7 files
[root@localhost mytest]# cat ./lib/hello.h
#ifndef HELLO_H
#define HELLO_H
void hey();
#endif
[root@localhost mytest]# cat ./src/hello.c
#include <stdio.h>
void hey()
{
	printf("%s\n", "hello");
}
[root@localhost mytest]# cat ./src/main.c
#include <stdio.h>
#include "hello.h"
int main(int argc, char *argv[])
{
	hey();
	return 0;
}
[root@localhost mytest]# cat Makefile
BUILD=${PWD}/build
LIB=${PWD}/lib
SRC=${PWD}/src

app:${BUILD}/main.o ${BUILD}/hello.o
	gcc -g ${BUILD}/main.o ${BUILD}/hello.o -o app
${BUILD}/main.o:${SRC}/main.c
	gcc -c ${SRC}/main.c -I ${LIB} -o ${BUILD}/main.o
${BUILD}/hello.o:${SRC}/hello.c
	gcc -c ${SRC}/hello.c -o ${BUILD}/hello.o
clean:
	rm -rf ${BUILD}/*
debug:
	echo ${PWD};
	echo ${BUILD};
	echo ${LIB};
	echo ${SRC};
print:
	ls -l ${BUILD}
run:
	${PWD}/app
```
### 一个多文件编译例子
```sh
[root@localhost mytest]# tree .
.
├── app
├── build
│   └── main.o
├── lib
│   ├── bits
│   │   └── socket.h
│   └── sys
│       └── socket.h
├── Makefile
└── src
    └── main.c

5 directories, 6 files
```
```sh
[root@localhost mytest]# cat ./lib/bits/socket.h 
#ifndef _BITS_SOCKET_H
#define _BITS_SOCKET_H

#ifndef _SYS_SOCKET_H
#error "Never include 'bits/socket.h' directly;use 'sys/socket.h' instead."
#endif


#endif
[root@localhost mytest]# cat ./lib/sys/socket.h 
#ifndef _SYS_SOCKET_H
#define _SYS_SOCKET_H 1

#include "bits/socket.h"

#endif
[root@localhost mytest]# cat Makefile 
BUILD=${PWD}/build
LIB=${PWD}/lib
SRC=${PWD}/src

app:${BUILD}/main.o
	gcc ${BUILD}/main.o -o app
${BUILD}/main.o:${SRC}/main.c
	gcc -c -g ${SRC}/main.c -I ${LIB} -o ${BUILD}/main.o
clean:
	rm -rf ${BUILD}/*
debug:
	echo ${PWD};
	echo ${BUILD};
	echo ${LIB};
	echo ${SRC};
print:
	ls -l ${BUILD}
run:
	${PWD}/app
[root@localhost mytest]# cat ./src/main.c 
#include <stdio.h>
#include "sys/socket.h"
int main(int argc, char *argv[])
{
	printf("%s\n", "Hello World!");
	return 0;
}
```
