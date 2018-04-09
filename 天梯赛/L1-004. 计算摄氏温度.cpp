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
map<int,int> cnt;
int main(){
	ios::sync_with_stdio(false);
	int f,c;
	cin>>f;
	c=(int)(5.0*(f-32)/9);
	cout<<"Celsius = "<<c;
	return 0;
}
