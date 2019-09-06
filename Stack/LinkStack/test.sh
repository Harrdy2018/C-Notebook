echo "正在执行的文件>>>"$1.c
gcc -c Stack.c
gcc -c $1.c
gcc -g Stack.o $1.o -o $1.exe && ./$1.exe
rm -rf Stack.o $1.o $1.exe