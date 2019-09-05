gcc -c DynamicStack.c
gcc -c DynamicMain.c
gcc -g DynamicStack.o DynamicMain.o -o DynamicMain.exe && ./DynamicMain.exe
rm -rf DynamicStack.o DynamicMain.o DynamicMain.exe