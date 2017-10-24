#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
int n,m;
int fa[maxn],cost[maxn];
struct node{
	int a,b;
	int c,s;//cost and status
	void read(){cin>>a>>b>>c>>s;}
	bool operator < (const node &n1)const{
		if(n1.s==s)return c<n1.c;
		return s>n1.s;
	}
}v[maxn];
int find(int x){
	int a=x;
	while(x!=fa[x])x=fa[x];
	while(a!=fa[a]){
		int tmp=a;
		a=fa[a];
		fa[tmp]=x;
	}
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;++i)v[i].read();
	sort(v,v+m);
	int res=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)fa[j]=j;
		int cnt=n-2;
		cost[i]=0;
		for(int j=0;j<m;++j){
			if(v[j].a==i||v[j].b==i)continue;
			int fx=find(v[j].a),fy=find(v[j].b);
			if(fx==fy)continue;
			--cnt;
			fa[fx]=fy;
			if(!v[j].s)cost[i]+=v[j].c; 
		}
		if(cnt>0)cost[i]=inf;
		res=max(res,cost[i]);
	}
	if(res){
		bool flag=false;
		for(int i=1;i<=n;++i)
			if(cost[i]==res){
				printf("%s%d", flag ? " " : "", i);  
				flag = true;
			}
	}else  cout<<res;
	return 0;
}
