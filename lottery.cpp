#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;
extern vector<string> split(string s,string& sep);
bool has_repeate(vector<string> &v){
	for(int i=0;i<v.size();i++){
		if(count(v.begin(),v.end(),v[i])>1){
			return false;
		}
	}
	return true;
}

int judge(vector<string> &v1,vector<string> &v2){
	int level=7;
	for(int i=0;i<v2.size();i++){
		if(std::count(v1.begin(),v1.end(),v2[i])>0){
			level--;
		}
	}
	return level;
}

int main()
{
	string sep=" ";
	vector<string> lines;
	ifstream ifs("lottery.in");
	if(!ifs.is_open()){
		return -1;
	}
	char buffer[128];
	while(ifs.getline(buffer,sizeof(buffer))){
		string line(buffer);
		lines.push_back(line);
	}
	int number=atoi(lines[0].c_str());
	vector<string> winning_number=split(lines[1],sep);
	
	for (int i=2;i<number+2;i++){
		vector<string> buy=split(lines[i],sep);
		cout<<judge(winning_number,buy)<<endl;
	}
	return 0;
}

