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

int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	/*n=pow(2,31)-1;
	cout<<n<<endl;
	ll res=1;
	for(int i=2;i<=12;++i)res*=i;
	cout<<res<<endl;*/	//检测出范围内最长连续因子长度13
	for(int len=13;len>=1;--len)
		for(ll st=2;st*st<=n;++st){
			ll tmp=n;
			bool flag=true; 
			for(ll j=st;j<st+len;++j){
				if(tmp%j){
					flag=false;
					break;
				}
				tmp/=j;
			}
			if(flag){
				cout<<len<<endl;
				for(ll i=st;i<st+len;++i){
					if(i!=st)cout<<"*";
					cout<<i;
				}
				return 0;
			}
		}
	cout<<1<<endl<<n;
	return 0;
}
