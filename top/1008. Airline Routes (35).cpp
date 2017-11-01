#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
const int maxn=10000+10;
using namespace std;
vector<int> e[maxn];
int dfn[maxn],low[maxn],belong[maxn];
int n,num=0,cnt=0;
stack<int> s;
void tarjan(int u){
	low[u]=dfn[u]=++num;
	s.push(u);
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(!belong[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++cnt;
		while(true){
			int x=s.top();s.pop();
			belong[x]=cnt;
			if(x==u)break;
		}
	}
}
int main(){
	int m,k;
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
	}
	scanf("%d",&k);
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	while(k--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(belong[a]==belong[b])cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
} 
