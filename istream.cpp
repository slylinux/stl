#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char buf[32]="hello world!";
	istream* is=&cin;
	is->clear();
	is->rdbuf()->pubsetbuf(buf,sizeof(buf));
	is->sync();
	char c,b='h';
	is->putback(b);
	is->get(c);	
	cout<<c<<endl;
	return 0;
}








