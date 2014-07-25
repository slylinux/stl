#include <iostream>
#include <locale>

using namespace std;

int main(int argc,char* argv[])
{
  locale loc;
  cout<<"max length :";
  cout<<use_facet<codecvt<char,char,mbstate_t> >(loc).max_length()<<endl;
  return 0;
}
