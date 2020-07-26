## compile
* -E 预处理(preprocess)
```
gcc -E test.c -o test.i 等价于 gcc -E test.c > test.i 
保留注释 gcc -E -C test.c -o test.i
```
* -S 编译(compile) 生成汇编代码文件
```
gcc -S test.i -o test.s
```
* -c 由汇编器将汇编代码转变成机器可以执行的指令得到目标文件
```
gcc -c test.s -o test.o
```
* 链接 链接到库中，变成可执行文件
```
gcc test.o -o test
```
### 一步到位编译
* gcc test.c -o test