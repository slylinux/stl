#include <cstdio>
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{
  int number;
  int numofbits=0;
  cout<<"please input a number:";
  scanf("%d",&number);
  bitset<8> bs(number);
  cout<<"bits="<<bs<<endl;
  for(int i=0;i<bs.size();i++){
    if(bs.test(i))
      numofbits++;
  }
  cout<<"there are "<<numofbits<<" bits."<<endl;
  return 0;
}
