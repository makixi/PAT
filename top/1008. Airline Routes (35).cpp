#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int dfn[maxn],low[maxn],id[maxn];
int scc=0,cnt=0;
vector<int> e[maxn];
bool vis[maxn];
int n,m;
stack<int> s;
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s.push(u);
	vis[u]=true;
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(vis[v])low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]){
		++scc;
		int v;
		do{
			v=s.top();s.pop();
			id[v]=scc;
			vis[v]=false;
		}while(u!=v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	int k;
	scanf("%d",&k);
	while(k--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(id[a]!=id[b])cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
