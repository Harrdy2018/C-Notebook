echo "正在执行的文件>>>"$1.c
gcc -g $1.c -o $1.exe && ./$1.exe
rm -rf $1.exe
