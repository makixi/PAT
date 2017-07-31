#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100010;
int dis[maxn];
int main(){
	int n,m,tmp,sum=0;
	int s,d;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&tmp);
		sum+=tmp;
		dis[i]=sum;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&s,&d);
		if(s>d)swap(s,d);
		tmp=dis[d-1]-dis[s-1];
		printf("%d\n",min(tmp,sum-tmp));
	}
	return 0;
}
