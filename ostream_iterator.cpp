#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
  vector<int> thv;
  for(int i=0;i<10;i++)thv.push_back(i*10);

  ostream_iterator<int> out_it(cout," ");
  copy(thv.begin(),thv.end(),ostream_iterator<int>(cout,","));
  cout<<endl;  
  copy(thv.begin(),thv.end(),out_it);
  cout<<endl;
  return 0;
}
