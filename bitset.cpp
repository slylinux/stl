#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& src, string delimit, string null_subst="")
{
  if( src.empty() || delimit.empty() )
    throw "split: empty string\0";
  const size_t npos = -1;

  vector<string> v;
  size_t deli_len = delimit.size();
  long index = npos, last_search_position = 0;
  while( (index=src.find(delimit, last_search_position))!=npos )
    {
      if(index==last_search_position)
	v.push_back(null_subst);
      else
	v.push_back( src.substr(last_search_position, index-last_search_position) );
      last_search_position = index + deli_len;
    }
  string last_one = src.substr(last_search_position);
  v.push_back( last_one.empty()? null_subst:last_one );
  return v;
}

int main()
{
  int a=255;
  bitset<32> bs(a);
  bs.set(31,1);
  cout<<bs<<",bit 2="<<bs.test(2)<<endl;
  bs.set(bs.size()-1,0);
  cout<<"after clear ="<<bs.to_ulong()<<",bs="<<bs<<endl;
  string str="0,0,10,22,312";
  vector<string> v=split(str,",");
  cout<<v[0]<<","<<v[2]<<endl;
  int x=-a;
  cout<<"a=="<<x<<endl;
}
