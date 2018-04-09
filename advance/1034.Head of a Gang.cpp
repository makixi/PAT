#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=10100;
const int inf=0x3f3f3f3f;
map<string,int> getid;
map<int,string> getname;
int fa[maxn];
int tot=0;
int m,k;
int w[maxn];
bool e[maxn][maxn];
int total[maxn];
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
void unite(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return;
	if(w[a]>=w[b]){fa[b]=a;total[a]+=total[b];}
	else {fa[a]=b;total[b]+=total[a];}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>k;
	for(int i=1;i<maxn;++i)fa[i]=i;
	while(m--){
		string a,b;
		int times;
		cin>>a>>b>>times;
		if(getid[a]==0){getid[a]=++tot;getname[tot]=a;}
		if(getid[b]==0){getid[b]=++tot;getname[tot]=b;}
		w[getid[a]]+=times;
		w[getid[b]]+=times;
		total[getid[a]]+=times;
		total[getid[b]]+=times;
		e[getid[a]][getid[b]]=e[getid[b]][getid[a]]=true;
	}
	for(int i=1;i<=tot;++i)
		for(int j=i+1;j<=tot;++j)
			if(e[i][j])unite(i,j);
	map<string,int> bang;
	set<int> s;
	for(int i=1;i<=tot;++i){
		int ff=find(i);
		if(total[ff]*1.0/2>k){
			bang[getname[ff]]++;
			if(bang[getname[ff]]>=3)s.insert(ff);
		}
	}
	cout<<s.size()<<endl;
	for(map<string,int>::iterator it=bang.begin();it!=bang.end();++it)
		if(it->second>=3)
			cout<<it->first<<" "<<it->second<<endl; 
	return 0;
}
