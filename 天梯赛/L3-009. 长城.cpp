#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100001;
struct node{
	long long x;
	long long y;
}p[maxn];
bool vis[maxn];
int s[maxn];
double judge(node a,node b,node c){
	return (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);  
}
int main(){
	int n;
	cin>>n;
	fill(vis,vis+maxn,false);
	int tp=0;
	for(int i=0;i<n;++i){
		cin>>p[i].x>>p[i].y;
		if(tp>=1){
			while(tp>=2&&judge(p[s[tp-2]],p[s[tp-1]],p[i])>=0)tp--;
			vis[s[tp-1]]=1;
		}
		s[tp++]=i;
	}
	int cnt=0;
	for(int i=1;i<n;++i)
		if(vis[i])++cnt;
	cout<<cnt<<endl;
	return 0;
}
