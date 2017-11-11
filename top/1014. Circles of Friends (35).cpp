#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
bool vis[maxn];
int ans[maxn];
vector<int> v[maxn];
int n,cnt=0;
int main(){
	int k,tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&tmp);
			v[i].push_back(tmp);
			v[tmp].push_back(i);
		}
	}
	int res=0;
	for(int i=1;i<=n;++i){
		queue<int> q;
		q.push(i);
		if(!vis[i])++cnt;
		for(int j=1;j<=n;++j)ans[j]=0;
		ans[i]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=true;
			res=max(res,ans[u]-2); 
			for(int j=0;j<v[u].size();++j){
				if(ans[v[u][j]])continue;
				ans[v[u][j]]=ans[u]+1;
				q.push(v[u][j]);
			}
		}
	}
	cout<<cnt<<" "<<res;
	return 0;
}
