#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=505;
int n;
int fa[maxn];
struct node{
	int from,to,w;
	bool operator < (const node &a)const{
		return w<a.w;
	}
};
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
	int m;
	scanf("%d%d",&n,&m);
	int part=n;
	vector<node> v(m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=0;i<m;++i)
		scanf("%d%d%d",&v[i].from,&v[i].to,&v[i].w);
	sort(v.begin(),v.end());
	int cnt=0,res=0,j;
	for(int i=0;i<m;i=j){
		for(j=i;j<m&&v[i].w==v[j].w;++j){
			int a=find(v[j].from),b=find(v[j].to);
			if(a==b)continue;
			++cnt;
		}
		for(int j=i;j<m&&v[i].w==v[j].w;++j){
			int a=find(v[j].from),b=find(v[j].to);
			if(a==b)continue;
			fa[a]=b;
			res+=v[j].w;
			part--;
		}
	}
	if(part!=1){
		cout<<"No MST\n";
		cout<<part;
	}
	else{
		cout<<res<<endl;
		if(cnt<n)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
