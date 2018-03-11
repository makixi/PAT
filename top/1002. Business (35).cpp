#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=51;
struct node{
	int unite,consume,deadline;
	bool operator < (const node &a)const{return deadline<a.deadline;}
}v[maxn];
int main() {
	ios::sync_with_stdio(false);
	int n,maxd=0,res=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>v[i].unite>>v[i].consume>>v[i].deadline;
		maxd=max(maxd,v[i].deadline); 
	} 
	sort(v,v+n);
	vector<int> dp(maxd+1,0);
	for(int i=0;i<n;++i)
		for(int j=maxd;j>=v[i].consume;--j)
			if(j<=v[i].deadline){
				dp[j]=max(dp[j],dp[j-v[i].consume]+v[i].unite);
				res=max(dp[j],res);
			}
	cout<<res;
	return 0;
}
