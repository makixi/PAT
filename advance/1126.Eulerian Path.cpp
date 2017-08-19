#include<iostream>
using namespace std;
const int maxn=505;
int edge[maxn]={0};
int father[maxn];
int findfather(int x){
	int a=x;
	while(x!=father[x])
		x=father[x];
	while(a!=father[a]){
		int tmp=a;
		a=father[a];
		father[tmp]=x;
	}
	return x;
}
void unite(int a,int b){
	int x=findfather(a);
	int y=findfather(b);
	if(x!=y)father[y]=x;
}
int main(){
	int n,m,a,b,cnt=0,res;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		edge[a]++;edge[b]++;
		unite(a,b);
	}
	for(int i=0;i<n;++i){
		if(i)cout<<" ";
		cout<<edge[i+1];
		if(edge[i+1]%2)cnt++;// not an Eulerian circuit
	}
	if(cnt==2)res=1;
	else if(cnt==0)res=2;
	else res=0;
	cout<<endl;
	if(res)
		for(int i=1;i<=n;++i)
			findfather(i);
		int fa=father[1];
		for(int i=2;i<=n;++i)
			if(father[i]!=fa&&father[i]!=i){
				res=0;break;
			}
	if(!res)printf("Non-Eulerian");
	else if(res==1) printf("Semi-Eulerian");
	else printf("Eulerian");
	return 0;
}
