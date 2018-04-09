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
	int odd=0,even=0;
	int n;
	cin>>n;
	while(n--){
		int tmp;
		cin>>tmp;
		if(tmp&1)odd++;
		else even++;
	}
	cout<<odd<<" "<<even;
	return 0;
}
