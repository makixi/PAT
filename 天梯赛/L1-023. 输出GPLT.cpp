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

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int g=0,p=0,l=0,t=0;
	for(int i=0;i<s.length();++i){
		char c=toupper(s[i]);
		if(c=='G')++g;
		else if(c=='P')++p;
		else if(c=='L')++l;
		else if(c=='T')++t;
	}
	while(g||p||l||t){
		if(g){
			cout<<'G';--g;
		}
		if(p){
			cout<<'P';--p;
		}
		if(l){
			cout<<'L';--l;
		}
		if(t){
			cout<<'T';--t;
		}
	}
	return 0;
}
