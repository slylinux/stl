#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void function(int i)
{
  cout<<i<<endl;
}

int main(int argc,char** argv)
{
  vector<int> myvector;
  vector<int>::iterator it;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);
  cout<<"for_each test:"<<endl;
  for_each(myvector.begin(),myvector.end(),function);
  cout<<"find test:"<<endl;
  it=find(myvector.begin(),myvector.end(),40);
  if(it!=myvector.end())
  cout<<"element is "<<*(it)<<endl;
  else
    {
      cout<<"not found"<<endl;
    }
  return 0;
}
