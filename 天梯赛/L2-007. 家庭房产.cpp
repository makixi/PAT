#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=10100;
const int inf=0x3f3f3f3f;
bool exist[maxn];
struct person{
	int id,fid,mid;
	vector<int> child;
	int num;
	int area;
}p[maxn];
struct family{
	int id;
	double num;
	double area;
	int peo;
	bool operator < (const family &ff)const{
		if (area != ff.area)return area > ff.area;
		return id < ff.id;
	}
}f[maxn];
int fa[maxn];
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
	if(a<=b)fa[b]=a;
	else fa[a]=b;
}
int n;
int main(){
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<=10000;++i)fa[i]=i;
	for(int i=0;i<n;++i){
		int id,fid,mid,k;
		cin>>p[i].id>>p[i].fid>>p[i].mid>>k;
		exist[p[i].id]=true;
		if(p[i].fid!=-1){
			exist[p[i].fid]=true;
			unite(p[i].id,p[i].fid);
		}
		if(p[i].mid!=-1){
			exist[p[i].mid]=true;
			unite(p[i].id,p[i].mid);
		}
		while(k--){
			int child;
			cin>>child;
			p[i].child.push_back(child);
			unite(p[i].id,child);
			exist[child]=true;
		}
		cin>>p[i].num>>p[i].area;
	}
	for(int i=0;i<n;++i){
		int id=find(p[i].id);
		f[id].id=id;
		f[id].num+=p[i].num;
		f[id].area+=p[i].area;
	}
	for(int i=0;i<maxn;++i)
		if(exist[i])f[find(i)].peo++;
	int cnt=0;
	for (int i = 0; i < maxn; ++i)
		if (f[i].num) {
			f[i].num /= f[i].peo;
			f[i].area /= f[i].peo;
			cnt++;
		}
	cout<<cnt<<endl;
	sort(f,f+maxn);
	for (int i = 0; i < cnt; ++i)
		printf("%04d %d %.3lf %.3lf\n", f[i].id, f[i].peo, f[i].num, f[i].area);
	return 0;
}
