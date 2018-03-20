#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
int fa[maxn][100],deep[maxn],e[maxn][2];
map<int,bool> exist;
void build(int &u,int key){
	if(u==0){
		u=key;
		return;
	}
	if(u>key)build(e[u][0],key);
	else build(e[u][1],key);
}
void  getdeep(int k, int d){
	deep[k] = d;
	for (int i = 1; (1 << i) <= deep[k]; i++)
		fa[k][i] = fa[fa[k][i - 1]][i - 1];
	for (int i = 0; i < 2; i++)
		if (e[k][i]&&!deep[e[k][i]]){
			fa[e[k][i]][0] = k;
			getdeep(e[k][i], d + 1);
		}
}
int lca(int x, int y){
	if (deep[x]<deep[y]) swap(x, y);
	int t = deep[x] - deep[y];
	for (int i = 0; i<20; i++)
		if ((1 << i)&t) x = fa[x][i];
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	if (x == y) return x;
	return fa[x][0];
}
int main(){
	ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	int root=1;
	for(int i=0;i<n;++i){
		int tmp;
		cin>>tmp;
		exist[tmp]=true;
		if(i)build(root,tmp);
		else root=tmp;
	}
	getdeep(root,1);
	while(m--){
		int a,b;
		cin>>a>>b;
		if(!exist[a]&&!exist[b])cout<<"ERROR: "<<a<<" and "<<b<<" are not found.\n";
		else if(!exist[a])cout<<"ERROR: "<<a<<" is not found.\n";
		else if(!exist[b])cout<<"ERROR: "<<b<<" is not found.\n";
		else{
			int res=lca(a,b);
			if(res==a)cout<<a<<" is an ancestor of "<<b<<".\n";
			else if(res==b)cout<<b<<" is an ancestor of "<<a<<".\n";
			else cout<<"LCA of "<<a<<" and "<<b<<" is "<<res<<".\n";
		}
	}
	return 0;
}
