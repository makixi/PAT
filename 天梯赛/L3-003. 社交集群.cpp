#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010;
int father[maxn];
int inter[maxn];
int num[maxn]={0};
int find(int x){
	int a=x;
	while(x!=father[x])x=father[x];
	while(a!=father[a]){
		int tmp=a;
		a=father[a];
		father[tmp]=x;
	}
	return x;
}
void unite(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y)father[x]=y;
}
int main(){
	int n,k,a,b;
	cin>>n;
	for(int i=1;i<maxn;++i)father[i]=i;
	for(int i=1;i<=n;++i){
		scanf("%d: %d",&k,&a);
		inter[i]=a;
		while(--k){
			cin>>b;
			unite(a,b);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
		num[find(inter[i])]++;
	for(int i=0;i<maxn;++i)
		if(num[i])++cnt;
	sort(num,num+maxn,greater<int>());
	cout<<cnt<<endl;
	for(int i=0;i<cnt;++i){
		if(i)cout<<" ";
		cout<<num[i];
	}
	cout<<endl;
	return 0;
}
