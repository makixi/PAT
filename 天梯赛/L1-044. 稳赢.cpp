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
	int k;
	cin>>k;
	k++;
	string s;
	int cnt=0;
	while(cin>>s&&s!="End"){
		cnt=(cnt+1)%k;
		if(cnt==0){
			cout<<s<<endl;
			continue;
		}
		switch(s[0]){
			case 'C':cout<<"Bu\n";break;
			case 'B':cout<<"JianDao\n";break;
			case 'J':cout<<"ChuiZi\n";break;
		}
	}
	return 0;
}
