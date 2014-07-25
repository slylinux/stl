#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> myvec;
    for(int i=1;i<10;i++){
        myvec.push_back(i);
    }
    rotate(myvec.begin(),myvec.begin()+3,myvec.end()-2);
    for(auto it=myvec.begin();it!=myvec.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
