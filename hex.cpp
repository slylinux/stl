#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

using namespace std;
uint8_t char2int(const char& c)
{
    uint8_t ret=0;
    if(c>='0'&&c<='9'){
        ret=c-'0';
    }else if(c>='a'&&c<='f'){
        ret=c-'a'+10;
    }	
    return ret;
}
uint8_t hex2int(const string& hex_in_string)//eg. "ae"                                                                                       
{
    char buf[3];
    memcpy(buf,hex_in_string.c_str(),2);
    char first=buf[0];
    char second=buf[1];
    return char2int(first)*16+char2int(second);
}
uint8_t* hex2charp(const string& hex)
{
	uint8_t buf[1024];
	for(int i=0,j=0;i<hex.size();i+=2,j++){
		string s=hex.substr(i,2);		
		buf[j]=hex2int(s);
		printf("%d\n",buf[j]);
	}
}
int main()
{
    string hex_string="8a30972d6735";
	hex2charp(hex_string);
	
    return 0;
}
