#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10010;
int used[maxn][maxn];
int dp[maxn];
vector<int> v;
int n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	v.resize(n+1);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	sort(v.begin()+1,v.end(),cmp);
	for(int i=1;i<=n;++i){
		for(int j=m;j>=v[i];--j){
			if(dp[j]<=dp[j-v[i]]+v[i]){
				dp[j]=dp[j-v[i]]+v[i];
				used[i][j]=true;
			}
		}
	}
	if(dp[m]!=m)printf("No Solution");
	else{
		vector<int> res;
		int curr=m,index=n;
		while(curr>0){
			if(used[index][curr]){
				res.push_back(v[index]);
				curr-=v[index];
			}
			--index;
		}
		for(int i=0;i<res.size();++i){
			if(i)cout<<" ";
			cout<<res[i];
		}
	}
	return 0;
}
