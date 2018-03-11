#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int val[10005];
bool dp[105];
bool e[10005][10005];
bool cmp(int a,int b){return a>b;}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>val[i];
	dp[0]=1;
	sort(val+1,val+1+n,cmp);
	for(int i=1;i<=n;++i)
		for(int j=m;j>=val[i];--j)
			if(dp[j-val[i]]){
				dp[j]=true;
				e[i][j]=true;
			}
	if(!dp[m])cout<<"No Solution";
	else{
		vector<int> res;
		int curr=m,index=n;
		while(curr>0){
			if(e[index][curr]){
				res.push_back(val[index]);
				curr-=val[index];
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
