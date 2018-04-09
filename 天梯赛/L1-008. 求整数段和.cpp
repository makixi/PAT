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
	int a,b;
	cin>>a>>b;
	int cnt=0,sum=0;
	for(int i=a;i<=b;++i){
		sum+=i;
		printf("%5d",i);
		++cnt;
		if(cnt%5==0)cout<<endl;
	}
	if(cnt%5)cout<<endl;
	cout<<"Sum = "<<sum;
	return 0;
}
