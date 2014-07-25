#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	ostringstream oss;
	oss<<setw(4)<<hex<<89;
	cout<<oss.str()<<endl;
	return 0;
}
