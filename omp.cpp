#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <omp.h>

using namespace std;

int main(){
  cout<<"number of processors:"<<omp_get_num_procs()<<",max number of threads:"<<omp_get_max_threads()<<endl;
  clock_t start=clock();
#pragma omp parallel for
  for(int i=0;i<100000000;i++){
    i/2;
  }
  cout<<"using paralism time(us):"<<clock()-start<<endl;  
  
  start=clock();
  for(int i=0;i<100000000;i++){
    i/2;
  }    
  cout<<"not using paralism time(us):"<<clock()-start<<endl;
#pragma omp parallel for
    for(int i=0;i<4;i++)
    cout<<"hello world!"<<endl;
  return 0;
}
 
