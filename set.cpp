#include <iostream>
#include <set>
using namespace std;

int main(int argc,char* argv[])
{
  set<int> myset;
  set<int>::iterator it;
  pair<set<int>::iterator,bool> ret;

  for(int i=1;i<=5;i++) myset.insert(i*10);
  ret=myset.insert(20);
  if(ret.second==false)
    it=ret.first;
  myset.insert(it,25);
  myset.insert(it,24);
  myset.insert(it,26);
  
  for(it=myset.begin();it!=myset.end();it++)
    cout<<" "<<*it;
  int myints[]={10,5,15};
  myset.insert(myints,myints+3);
  cout<<endl;
  for(it=myset.begin();it!=myset.end();it++)
    cout<<" "<<*it;

  return 0;
}
