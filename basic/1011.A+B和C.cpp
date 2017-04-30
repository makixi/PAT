#include<iostream>
using namespace std;
#define MAX 10
int main()
{
	int T,count=0;
	cin>>T;
	long a,b,c;
	int judice[MAX];
	while(count<T){
		cin>>a>>b>>c;
		if(a+b>c) judice[count]=1;
		else judice[count]=0;
		count++;
	}
	for(count=0;count<T;count++)
	{
		cout<<"Case #"<<count+1<<":";
		if(judice[count]==0) {
		cout<<"false";
		if(count!=T-1) cout<<endl;}
		else {
		cout<<"true";
		if(count!=T-1) cout<<endl;}
	}
}
