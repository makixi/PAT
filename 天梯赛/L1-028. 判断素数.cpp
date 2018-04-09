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
bool isprime(int x){
	if(x<2)return false;
	for(int i=2;i<=sqrt(x);++i)
		if(x%i==0)return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		int tmp;
		cin>>tmp;
		if(isprime(tmp))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
