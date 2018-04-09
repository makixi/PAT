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
int pri[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[]={'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
	//ios::sync_with_stdio(false);
	string s;
	cin>>s;
	bool negative=false;
	if(s[0]=='-'){
		s.erase(0,1);
		negative=true;
	}
	int cnt=0;
	for(int i=0;i<s.length();++i){
		if(s[i]=='2')++cnt;
	}
	double res=cnt*1.0/s.length();
	if((s[s.length()-1]-'0')%2==0)res*=2;
	if(negative)res*=1.5;
	res*=100;
	printf("%.2lf%%",res);
	return 0;
}
