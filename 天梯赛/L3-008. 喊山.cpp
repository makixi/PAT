#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn=10010;
bool vis[maxn];
vector<int> v[maxn];
int n;
struct node{
	int num;
	int depth;
};
int bfs(int num){
	int res=0;
	int maxdepth=0;
	queue<node> q;
	q.push(node{num,0});
	fill(vis,vis+maxn,false);
	vis[num]=true;
	while(!q.empty()){
		node tmp=q.front();q.pop();
		if(tmp.depth>maxdepth){
			maxdepth=tmp.depth;
			res=tmp.num;
		}else if(tmp.depth==maxdepth&&tmp.num<res)
			res=tmp.num;
		for(int i=0;i<v[tmp.num].size();++i)
			if(!vis[v[tmp.num][i]]){
				vis[v[tmp.num][i]]=true;
				q.push(node{v[tmp.num][i],tmp.depth+1});
			}
	}
	return res;
}
int main(){
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	while(k--){
		scanf("%d",&m);
		printf("%d\n",bfs(m));
	}
	return 0;
}
