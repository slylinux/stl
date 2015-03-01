#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s="123456789";
	cout<<"s="<<s<<endl;
	reverse(s.begin(),s.end());
	cout<<"after reverse s="<<s<<endl;
	return 0;
}






