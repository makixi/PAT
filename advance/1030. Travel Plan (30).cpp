#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=510;
const int inf=0x3f3f3f3f;
int n,m,s,d;
int e[maxn][maxn],dis[maxn],cost[maxn][maxn],consume[maxn];
bool vis[maxn];
vector<int> pre[maxn],res,tmp;
void dfs(int u){
	tmp.push_back(u);
	if(u==s){
		res=tmp;
		tmp.pop_back();
		return;
	}
	dfs(pre[u][0]);
	tmp.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	memset(e,inf,sizeof(e));
	memset(dis,inf,sizeof(dis));
	memset(cost,inf,sizeof(cost));
	memset(consume,inf,sizeof(consume));
	cin>>n>>m>>s>>d;
	for(int i=0;i<m;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		e[a][b]=e[b][a]=c;
		cost[a][b]=cost[b][a]=d;
	}
	dis[s]=0;
	consume[s]=0;
	for(int i=0;i<n;++i){
		int minn=inf,u=-1;
		for(int j=0;j<n;++j)
			if(!vis[j]&&dis[j]<minn){
				minn=dis[j];
				u=j;
			}
		if(u==-1)break;
		vis[u]=true;
		for(int j=0;j<n;++j)
			if(!vis[j]&&e[u][j]!=inf)
				if(dis[j]>dis[u]+e[u][j]){
					dis[j]=dis[u]+e[u][j];
					pre[j].clear();
					pre[j].push_back(u);
					consume[j]=consume[u]+cost[u][j];
				}else if(dis[j]==dis[u]+e[u][j]){
					if(consume[j]>consume[u]+cost[u][j]){
						consume[j]=consume[u]+cost[u][j];
						pre[j].clear();
						pre[j].push_back(u);
					}else if(consume[j]==consume[u]+cost[u][j])
						pre[j].push_back(u);
				}
	}
	dfs(d);
	for(int i=res.size()-1;i>=0;--i)cout<<res[i]<<" ";
	cout<<dis[d]<<" "<<consume[d];
	return 0;
}
