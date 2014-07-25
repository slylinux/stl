#include <string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc,char* argv[])
{
	char buf[128];
	map<string,int> line_map;
	if(argc!=2){
		cout<<"Usage: ./getline filename"<<endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	if(!ifs.is_open()){
		cout<<"file open error:"<<argv[1]<<endl;
		return -1;
	}
	int i=0;
	while(ifs.getline(buf,sizeof(buf))){
		string line=buf;
		if(line_map.find(line)==line_map.end()){
			line_map.insert(make_pair(line,i));
		}
		i++;
	}
	for(map<string,int>::iterator it=line_map.begin();it!=line_map.end();it++){
		cout<<it->first<<endl;
	}
	return 0;
}

