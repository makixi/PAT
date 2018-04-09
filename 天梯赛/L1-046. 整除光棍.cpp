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
	int n;
	cin>>n;
	ll res=1;
	int cnt=1;
	while(res<n){
		++cnt;
		res=res*10+1;
	}
	while(true){
		cout<<res/n;
		if(res%n==0)break;
		else{
			res%=n;
			res=res*10+1;
			++cnt;
		}
	}
	cout<<" "<<cnt;
	return 0;
}
