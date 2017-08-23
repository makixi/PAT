#include<iostream>
#include<set>
using namespace std;
const int maxn=10001;
int father[maxn];
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
	int n,k,a,b,q;
	cin>>n;
	set<int> s;
	for(int i=1;i<maxn;++i)
		father[i]=i;
	for(int i=0;i<n;++i){
		cin>>k>>a;
		s.insert(a);
		for(int j=0;j<k-1;++j){
			cin>>b;
			s.insert(b);
			unite(a,b);
		}
	}
	int cnt=0;
	for(int i=1;i<=s.size();++i)find(i);
	for(int i=1;i<=s.size();++i)
		if(father[i]==i)cnt++;
	cout<<s.size()<<" "<<cnt<<endl;
	cin>>q;
	while(q--){
		cin>>a>>b;
		if(father[a]!=father[b])cout<<"N"<<endl;
		else cout<<"Y"<<endl;
	}
	return 0;
}
