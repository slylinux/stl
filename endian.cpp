#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	int a=0x12345678;
	char c=static_cast<char>(a);
	printf("c is 0x%x\n",c);
	if(c==0x78){
		cout<<"little endian"<<endl;
	}
	else{
		cout<<"big endian"<<endl;
	}
	return 0;
}








