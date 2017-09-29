#include<iostream>
using namespace std;
int prime[10000+1];
bool judge(int n){
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=2,cnt=1;cnt<=n;++i){
		if(judge(i))prime[cnt++]=i;
	}
	for(int i=m,cnt=0;i<=n;++i){
		cout<<prime[i];
		++cnt;
		if(cnt%10==0&&i!=n)cout<<endl;
		else if(i!=n)cout<<" ";
	}
	return 0;
} 
