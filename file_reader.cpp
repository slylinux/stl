#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string s,string& sep)
{
	vector<string> v;
	size_t start_pos=0;
	size_t pos=s.find_first_of(sep);
	while(pos!=string::npos){
		string subs=s.substr(start_pos,pos-start_pos);
		v.push_back(subs);
		start_pos=pos+1;
		pos=s.find_first_of(sep,start_pos);
	}
	return v;	
}

int main()
{
	char buffer[256];

	ifstream ifs("a.txt");
	if(!ifs.is_open()){
		return -1;
	}
	ifs.getline(buffer,sizeof(buffer));
	ifs.close();
	string line(buffer);
	cout<<line<<endl;
	string sep=" ";
	vector<string> v=split(line,sep);
	for(size_t index=0;index<v.size();index++){
		cout<<v[index]<<endl;
	}
	return 0;
}
