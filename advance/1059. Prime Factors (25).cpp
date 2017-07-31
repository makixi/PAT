#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
vector<int> prime(500000,1);
void init(){
	for(int i=2;i*i<500000;++i)
		for(int j=2;j*j<500000;++j)
			prime[i*j]=0;
}
int main(){
	init();
	long long n;
	cin>>n;
	cout<<n<<"=";
	if(n==1){
		cout<<"1";return 0;
	}
	bool flag=false;
	for(int i=2;n>1;++i){
		bool flag2=false;
		int cnt=0;
		while(prime[i]==1&&n%i==0){
			++cnt;
			n/=i;
			flag2=true;
		}
		if(flag2){
			if(flag)cout<<"*";
			cout<<i;
			flag=true;
		}
		if(cnt>=2)
			cout<<"^"<<cnt;
	}
	return 0;
}
