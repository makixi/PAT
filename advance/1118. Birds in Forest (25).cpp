#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=10001;
int father[maxn];
bool vis[maxn]={false};
int findfather(int x){
	int a=x;
	while(x!=father[x])
		x=father[x];
	while(a!=father[a]){	//不压缩路径就超时 
		int tmp=a;
		a=father[a];
		father[tmp]=x;
	}
	return x;
}
void unite(int a,int b){
	int x=findfather(a);
	int y=findfather(b);
	if(x!=y)
		father[x]=y;
}

int main(){
	int n,q,k,tmp,fa;
	scanf("%d",&n);
	set<int> s;
	for(int i=1;i<maxn;++i)
		father[i]=i;
	while(n--){
		scanf("%d",&k);
		if(k!=0){
			scanf("%d",&fa);
			s.insert(fa);
			vis[fa]=true;
		}
		for(int i=0;i<k-1;++i){
			scanf("%d",&tmp);
			s.insert(tmp);
			vis[tmp]=true;
			unite(tmp,fa);
		}
	}
	int cnt=0;
	for(int i=1;i<maxn;++i)
		if(vis[i]&&father[i]==i)
			cnt++;
	printf("%d %d\n",cnt,s.size());
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		if(findfather(a)!=findfather(b))
			printf("No\n");
		else 
			printf("Yes\n");
	}
	return 0;
}
