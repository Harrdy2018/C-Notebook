gcc -c main.c && gcc -c SingleLinkTable.c && gcc -g main.o SingleLinkTable.o -o main.exe && ./main.exe
rm -rf main.o main.exe SingleLinkTable.o