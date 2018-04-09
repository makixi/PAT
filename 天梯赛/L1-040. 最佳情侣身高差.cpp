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
	int n;
	cin>>n;
	while(n--){
		char c;
		double h;
		cin>>c>>h;
		if(c=='M'){
			h/=1.09;
		}else{
			h*=1.09;
		}
		printf("%.2lf\n",h);
	}
	return 0;
}
