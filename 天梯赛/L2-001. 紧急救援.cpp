#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
const int inf=0x3f3f3f3f;
int aid[maxn];
int table[maxn][maxn],dis[maxn];
bool vis[maxn];
int pre[maxn],num[maxn],pathnum[maxn];
int s,d;
void dfs(int u){
	if(u==s){
		cout<<u;
		return;
	}
	dfs(pre[u]);
	cout<<" "<<u;
}
int main(){
	int n,m,a,b,c;
	cin>>n>>m>>s>>d;
	memset(table,inf,sizeof(table));
	memset(dis,inf,sizeof(dis));
	for(int i=0;i<n;++i)cin>>aid[i];
	for(int i=0;i<m;++i){
		cin>>a>>b>>c;
		table[a][b]=table[b][a]=c;
	}
	dis[s]=0;
	num[s]=aid[s];
	pathnum[s]=1;
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
			if(!vis[j]&&table[u][j]!=inf)
				if(dis[j]>dis[u]+table[u][j]){
					dis[j]=dis[u]+table[u][j];
					pathnum[j]=pathnum[u];
					num[j]=num[u]+aid[j];
					pre[j]=u;
				}else if(dis[j]==table[u][j]+dis[u]){
					pathnum[j]+=pathnum[u];
					if(num[u]+aid[j]>num[j]){
						num[j]=num[u]+aid[j];
						pre[j]=u;
					}
				}
	}
	printf("%d %d\n",pathnum[d],num[d]);
	dfs(d);
	return 0;
}
