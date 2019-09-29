str1=$1
str2=$2
a=${str1%.*}
b=${str2%.*}
gcc -c $a.c && gcc -c $b.c
gcc -g $a.o $b.o -o test.exe && ./test.exe
rm -rf $a.o $b.o test.exe
