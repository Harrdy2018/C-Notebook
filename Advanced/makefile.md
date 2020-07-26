## makefile
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