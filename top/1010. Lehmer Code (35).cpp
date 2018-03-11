#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
ll c[maxn];
ll r[maxn];
int a[maxn];
struct node{
	int val;
	int id;
}v[maxn];
bool cmp(node a,node b){
	return a.val<b.val;
}
int n;
void update(int x,int v){
	for(;x<=n;x+=lowbit(x))c[x]+=v;
}
ll getsum(int x){
	ll res=0;
	for(;x>=1;x-=lowbit(x))res+=c[x];
	return res;
}
int main(){
	scanf("%d",&n); 
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i].val);
		v[i].id=i;
	}
	sort(v+1,v+1+n,cmp);
	for(int i=1;i<=n;++i)a[v[i].id]=i;
	for(int i=n;i>=1;i--){
		r[i]=getsum(a[i]);
		update(a[i],1);
	}
	for(int i=1;i<=n;++i){
		if(i!=1)cout<<" ";
		cout<<r[i];
	}
	return 0;
} 
