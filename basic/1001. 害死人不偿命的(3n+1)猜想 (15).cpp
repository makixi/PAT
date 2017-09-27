#include<iostream>
using namespace std;
int main(){
	int n,res=0;
	cin>>n;
	while(n!=1){
		if(n%2)n=n*3+1;
		n/=2;
		++res;
	}
	cout<<res;
	return 0;
}
