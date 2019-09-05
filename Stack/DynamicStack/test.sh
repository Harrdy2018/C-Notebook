gcc -c Stack.c
gcc -c main.c
gcc -g Stack.o main.o -o main.exe && ./main.exe
rm -rf Stack.o main.o main.exe