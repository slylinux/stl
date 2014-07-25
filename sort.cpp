#include <iostream>
#include <string>
using namespace std;

void ShellSort(int a[], int n)
{
  int d, i, j, temp;
  for(d = n/2;d >= 1;d = d/2)
    {
      for(i = d; i < n;i++)
	{
	  temp = a[i];
	  for(j = i - d;(j >= 0) && (a[j] > temp);j = j-d)
	    {
	      a[j + d] = a[j];
	    }
	  a[j + d] = temp;
	}
    }
}

int main(){
  int values[]={10,8,5,2,3,100,98,4};
  ShellSort(values,sizeof(values)/sizeof(values[0]));
  for(int i=0;i<sizeof(values)/sizeof(values[0]);i++){
    cout<<values[i]<<" ";
  }
  cout<<endl;
  return 0;
}
