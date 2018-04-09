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
	int jia,yi,jiahe=0,yihe=0;
	cin>>jia>>yi;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b==(a+c)&&d==(a+c))continue;
		else if(b==(a+c))jiahe++;
		else if(d==(a+c))yihe++;
		else continue;
		if(jiahe>jia){
			cout<<"A\n";
			cout<<yihe;
			break;
		}else if(yihe>yi){
			cout<<"B\n";
			cout<<jiahe;
			break;
		}
	}
	return 0;
}
