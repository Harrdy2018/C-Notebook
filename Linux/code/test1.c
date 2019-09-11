#include <stdio.h>
#include <stdlib.h>
#define CPU_VENDOR_OS "sparc64-unknown-freebsd5.1"
union Data{
	short s;
	char c[sizeof(short)];
} data;
void main(void){
	data.s=0x0102;
	printf("%s : ",CPU_VENDOR_OS);
	if(sizeof(short) == 2){
		if(data.c[0] == 1 && data.c[1] == 2){
			printf("big-endian\n");
		}else if(data.c[0] == 2 && data.c[1] == 1){
			printf("little-endian\n");
		}else{
			printf("unknown\n");
		}
	}else{
		printf("sizeof(short) = %d\n",sizeof(short));
	}
	exit(0);
}