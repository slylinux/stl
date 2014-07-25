#include <iostream>
#include <string>

using namespace std;

class Base{
public:
	Base(const int& x,const int& y){a=123;b=456;}
	int a,b;
	void print2(){print();}
protected:
	void print(){cout<<"a="<<a<<",b="<<b<<endl;}
private:
	int c,d;
};

class Sub1:public Base
{
public:
	Sub1();
	Sub1(const int& x,const int& y):Base(x,y){a=x;b=y;}
	void print1(){print();}
};

int main()
{
	Base* base=new Sub1(2,4);
	base->print2();
	return 0;
}
