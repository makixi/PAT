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
	//ios::sync_with_stdio(false);
	int n;string c,s;
	cin>>n>>c;getchar();
	getline(cin,s);
	if(s.length()>=n){
		cout<<s.substr(s.length()-n,n);
		return 0;
	}
	for(int i=0;i<n-s.length();++i)cout<<c;
	cout<<s;
	return 0;
}
