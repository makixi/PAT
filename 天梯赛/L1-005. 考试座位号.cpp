#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
map<int,int> cnt;
struct node{
	string zhunkao;
	string kaoshi;
	node(){}
	node(string z,string k):zhunkao(z),kaoshi(k){}
};
map<string,node> q;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		string a,b,c;
		cin>>a>>b>>c;
		q[b]=node(a,c);
	}
	int m;
	cin>>m;
	while(m--){
		string shiji;
		cin>>shiji;
		cout<<q[shiji].zhunkao<<" "<<q[shiji].kaoshi<<endl;
	}
	return 0;
}
