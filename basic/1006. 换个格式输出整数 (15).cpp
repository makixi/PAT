#include<iostream>
using namespace std;
int main(){
	int n,a,b,c;
	cin>>n;
	a=n/100,b=n%100/10,c=n%10;
	for(;a;--a)cout<<"B";
	for(;b;--b)cout<<"S";
	for(int i=1;i<=c;++i)cout<<i;
	return 0;
}
