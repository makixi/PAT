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
	int n;
	string s;
	cin>>n>>s;
	int row=round(1.0*n/2);
	for(int i=0;i<row;++i){
		for(int j=0;j<n;++j)
			cout<<s;
		cout<<endl;
	}
	return 0;
}
