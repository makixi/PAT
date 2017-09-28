#include<iostream>
using namespace std;
int prime[100001];
void init(){
	fill(prime,prime+100001,1);
	prime[0]=prime[1]=0;
	for(int i=2;i<=1e5;++i){
		if(!prime[i])continue;
		for(int j=i*2;j<=1e5;j+=i)
			prime[j]=0;
	}
}
int main(){
	init();
	int n,cnt=0;
	cin>>n;
	for(int i=2;i<=n-2;++i){
		if(prime[i]&&prime[i+2])++cnt;
	}
	cout<<cnt;
	return 0;
}
