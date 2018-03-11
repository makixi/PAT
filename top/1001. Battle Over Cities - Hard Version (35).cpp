#include<iostream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int fa[maxn],cost[maxn];
struct node{
	int from,to;
	int w,s;
	void read(){cin>>from>>to>>w>>s;}
	bool operator < (const node &a) const{
		if(s==a.s)return w<a.w;
		return s>a.s;
	}
}v[maxn];
int find(int x){
	int a=x;
	while(x!=fa[x])x=fa[x];
	while(a!=fa[x]){
		int tmp=a;
		a=fa[a];
		fa[tmp]=x;
	}
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,res=0;
	cin>>n>>m;
	for(int i=0;i<m;++i)v[i].read();
	sort(v,v+m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)fa[j]=j;
		int cnt=n-2;
		cost[i]=0;
		for(int j=0;j<m;++j){
			if(v[j].from==i||v[j].to==i)continue;
			int fx=find(v[j].from),fy=find(v[j].to);
			if(fx==fy)continue;
			--cnt;
			if(!v[j].s)cost[i]+=v[j].w;
			fa[fx]=fy;
		}
		if(cnt>0)cost[i]=inf;
		res=max(cost[i],res);
	}
	if(!res){
		cout<<0;
		return 0;
	}
	bool flag=false;
	for(int i=1;i<=n;++i)
		if(res==cost[i]){
			if(flag)cout<<" ";
			flag=true;
			cout<<i;
		}
	return 0;
}
