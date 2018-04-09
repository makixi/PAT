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
map<char,string> m;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	m[0]="ling";m[1]="yi";m[2]="er";
	m[3]="san";m[4]="si";m[5]="wu";
	m[6]="liu";m[7]="qi";m[8]="ba";
	m[9]="jiu";
	if(s[0]=='-'){
		cout<<"fu ";
		s.erase(0,1);
	}
	for(int i=0;i<s.length();++i){
		if(i)cout<<" ";
		cout<<m[s[i]-'0'];
	}
	return 0;
}
