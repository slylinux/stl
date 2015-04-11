#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stru{
	char x1;
	short x2;
	long x3;
	char x4;
};

void func(char* s){
	printf("size s =%d\n",sizeof(s));
	printf("strlen s=%d\n",strlen(s));
}

int main()
{
 
	printf("size struct=%d,char size=%d,short size=%d,long size=%d.\n",sizeof(struct  stru),sizeof(char),sizeof(short),sizeof(long));
	char a[]="123456789";
	printf("size a =%d\n",sizeof(a));
	printf("strlen a=%d\n",strlen(a));
	func(a);
	return 0;
}
