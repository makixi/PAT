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
	vector<int> v(3);
	for(int i=0;i<3;++i)cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=0;i<3;++i){
		if(i)cout<<"->";
		cout<<v[i];
	}
	return 0;
}
