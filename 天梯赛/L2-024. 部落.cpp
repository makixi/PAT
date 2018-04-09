#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=1e4+5;
const int inf=0x3f3f3f3f;
int fa[maxn];
bool exist[maxn];
int find(int x){
	int a=x;
	while(x!=fa[x])x=fa[x];
	while(a!=fa[a]){
		int tmp=a;
		a=fa[a];
		fa[tmp]=x;
	}
	return x;
}
void unite(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return;
	if(b<a)fa[a]=b;
	else fa[b]=a;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=10000;++i)fa[i]=i;
	set<int> s,buluo;
	while(n--){
		int k,pre;
		cin>>k;
		if(k){
			cin>>pre;
			s.insert(pre);
			exist[pre]=true;
		}
		for(int j=1;j<k;++j){
			int tmp;
			cin>>tmp;
			s.insert(tmp);
			exist[tmp]=true;
			unite(pre,tmp);
		}
	}
	int cnt=0;
	for(int i=1;i<=10000;++i){
		if(exist[i]){
			buluo.insert(find(i));
		}
	}
	cout<<s.size()<<" "<<buluo.size()<<endl;
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(fa[a]==fa[b])cout<<"Y\n";
		else cout<<"N\n";
	}
	return 0;
}
