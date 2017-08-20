#include<iostream>
using namespace std;
const int maxn=101;
int relation[maxn][maxn]={0};
int friends[maxn];
int findfriend(int x){
	int a=x;
	while(x!=friends[x])x=friends[x];
	while(a!=friends[a]){
		int tmp=a;
		a=friends[a];
		friends[tmp]=x;
	}
	return x;
}
void unite(int a,int b){
	int x=findfriend(a);
	int y=findfriend(b);
	if(x!=y)friends[x]=y;
}
int main(){
	int n,m,k,a,b;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)friends[i]=i;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		cin>>relation[a][b];
		relation[b][a]=relation[a][b];
		if(relation[a][b]==1)
			unite(a,b);
	}
	for(int i=0;i<=n;++i)findfriend(i);
	while(k--){
		cin>>a>>b;
		if(relation[a][b]==1)printf("No problem\n");
		else if(relation[a][b]==0)printf("OK\n");
		else if(relation[a][b]==-1&&friends[a]==friends[b])
			printf("OK but...\n");
		else printf("No way\n");
	}
	return 0;
}
