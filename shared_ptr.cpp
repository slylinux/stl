#include <iostream>
#include <string>
#include <deque>
#include <memory>

using namespace std;

int main(int argc,char* argv[])
{
  deque<string> squ;
  shared_ptr<string> str_ptr(new string("hello"));
  shared_ptr<string> p(str_ptr);
  squ.push_back(*p);

  cout<<"use counts="<<str_ptr.use_count()<<endl;
  cout<<*str_ptr<<endl;
  str_ptr.reset();
  cout<<"after reset use counts="<<str_ptr.use_count()<<endl;
  return 0;
}
