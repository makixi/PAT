#include<iostream>
#include<cstdio>
#include<cstring>
#define lowbit(i) ((i)&(-i))
using namespace std;
typedef long long LL;
const int maxn=100010;
LL l[maxn],r[maxn];
int c[maxn],val[maxn],n;
void update(int x,int v){
	for(;x<=n;x+=lowbit(x))c[x]+=v;
}
LL getsum(int x){
	LL res=0;
	for(;x>=1;x-=lowbit(x))res+=c[x];
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	for(int i=1;i<=n;++i){
		l[i] = i - 1 - getsum(val[i]);
        update(val[i],1);
	}
	memset(c,0,sizeof(c));
	for(int i = n; i; i--){
        r[i] = getsum(val[i]);
        update(val[i],1);
    }
    LL ans=0;
	for(int i = 1; i <= n; i++)ans += l[i]*r[i];
	cout<<ans<<"\n";
	return 0;
}
