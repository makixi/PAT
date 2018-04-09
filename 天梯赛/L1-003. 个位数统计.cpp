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
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.length();++i){
		cnt[s[i]-'0']++;
	}
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it){
		cout<<it->first<<":"<<it->second<<endl;
	}
	return 0;
}
