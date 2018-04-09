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
const int buqiao=12*60;
int main(){
	ios::sync_with_stdio(false);
	int h,m;
	scanf("%d:%d",&h,&m);
	int all=h*60+m;
	if(all<=buqiao){
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
		return 0;
	}
	all-=buqiao;
	all--;
	all=all/60+1;
	while(all--)cout<<"Dang";
	return 0;
}
