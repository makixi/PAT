#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
ll c[maxn],val[maxn],l[maxn],r[maxn];
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
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	for(int i=1;i<=n;++i){//左边比我大
		l[i] = i - 1 - getsum(val[i]);
        update(val[i],1);
	}
	memset(c,0,sizeof(c)); 
	for(int i = n; i; i--){//右边比我小
        r[i] = getsum(val[i]);
        update(val[i],1);
    }
    ll ans=0;
	for(int i = 1; i <= n; i++)ans += l[i]*r[i]; 
	cout<<ans<<"\n";
	return 0;
} 
