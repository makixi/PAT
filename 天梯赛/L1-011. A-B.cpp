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
map<char,bool> m;
int main(){
	ios::sync_with_stdio(false);
	string a,b;
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<b.length();++i)
		m[b[i]]=true;
	for(int i=0;i<a.length();++i)
		if(!m[a[i]])cout<<a[i];
	return 0;
}
