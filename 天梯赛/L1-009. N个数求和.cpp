#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	//ios::sync_with_stdio(false);
	int n;
	cin>>n;
	ll zi,mu;
	if(n){
		scanf("%lld/%lld",&zi,&mu);
		ll gg=gcd(zi,mu);
		zi/=gg;
		mu/=gg;
	}
	for(int i=1;i<n;++i){
		ll nzi,nmu;
		scanf("%lld/%lld",&nzi,&nmu);
		ll gg=mu/gcd(mu,nmu)*nmu;
		zi=gg/mu*zi+gg/nmu*nzi;
		mu=gg;
		gg=gcd(zi,mu);
		zi/=gg;
		mu/=gg; 
	}
	bool output=false;
	if(zi/mu){
		cout<<zi/mu;
		zi-=zi/mu*mu;
		if(zi)cout<<" ";
		output=true;
	}
	else zi-=zi/mu*mu;
	if(zi){
		if(zi>0&&mu<0){
			zi=-zi;
			mu=-mu;
		}
		cout<<zi<<"/"<<mu;
		output=true;
	}
	if(!output)cout<<0;
	return 0;
}
