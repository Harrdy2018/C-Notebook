gcc -c main.c && gcc -c SequenceList.c && gcc -g main.o SequenceList.o -o main.exe && ./main.exe
rm -rf SequenceList.o main.o main.exe