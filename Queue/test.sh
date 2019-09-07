echo "正在执行的文件>>>"$1.c
gcc -c Queue.c
gcc -c $1.c
gcc -g Queue.o $1.o -o $1.exe && ./$1.exe
rm -rf Queue.o $1.o $1.exe