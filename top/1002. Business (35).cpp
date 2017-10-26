#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=51;
int n,maxd=0;
struct node{
	int p,l,d;
	void read(){cin>>p>>l>>d;maxd=max(maxd,d);}
	friend bool operator < (node a,node  b){
		return a.d<b.d;
	}
}v[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i)v[i].read();
	sort(v,v+n);
	int *dp=new int [maxd+1];
	fill(dp,dp+maxd+1,0);
	int res=0;
	for(int i=0;i<n;++i)
		for(int j=maxd;j>=v[i].l;--j)
			if(j<=v[i].d){
				dp[j]=max(dp[j],dp[j-v[i].l]+v[i].p);
				res=max(dp[j],res);
			}
	cout<<res;
	return 0;
}
