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
	int n;
	cin>>n;getchar();
	bool flag=true;
	while(n--){
		string s;
		getline(cin,s);
		int tmp=0;
		bool ff=true;
		for(int i=0;i<17;++i){
			if(!(s[i]>='0'&&s[i]<='9')){
				ff=false;
				break;
			}
			tmp+=pri[i]*(s[i]-'0');
		}
		if(!ff){
			cout<<s<<endl;
			flag=false;
			continue;
		}
		int z=tmp%11;
		if(m[z]!=s[17]){
			cout<<s<<endl;
			flag=false;
		}
	}
	if(flag)cout<<"All passed";
	return 0;
}
