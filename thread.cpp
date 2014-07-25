#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;
mutex mlock;
void print_string()
{
  mlock.lock();
  cout<<"hello world!"<<endl;
  mlock.unlock();
}
void print_int(int& i)
{
  mlock.lock();
  cout<<"value="<<i<<endl;
  mlock.unlock();
}
int main(int argc,char* argv[])
{
  cout<<"threads start!"<<endl;

  thread first(print_string);
  thread second(print_int,4);
  first.join();
  second.join();
  cout<<"threads finished!"<<endl;
  return 0;
}
