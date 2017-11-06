#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define lowbit(i) ((i)&(-i))
struct node{
	int val,id;
}p[100005];
int a[100005];//¿Î…¢ªØ~ 
int ans[100005];
int c[100005],n;
bool cmp(node a,node b){
	return a.val<b.val;
}
int getsum(int x){
	int ans=0;
	for(;x>=1;x-=lowbit(x))ans+=c[x];
	return ans;
}
void update(int x,int v){
	for(;x<=n;x+=lowbit(x))c[x]+=v;
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&p[i].val);p[i].id=i;
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)a[p[i].id]=i;
	for(i=n;i>=1;i--){
		ans[i]=getsum(a[i]);
		update(a[i],1);
	}
	for(int i=1;i<=n;++i){
		if(i!=1)cout<<" ";
		cout<<ans[i];
	}
	return 0;
}

