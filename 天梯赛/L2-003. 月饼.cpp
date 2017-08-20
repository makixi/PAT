#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=510;
const int inf=0x3f3f3f3f;
struct node{
	double save;
	double sale;
	double unite;
};
bool cmp(node a,node  b){
	return a.unite>b.unite;
}
int main(){
	int n,d,in=0;
	double maxsum=0;
	cin>>n>>d;
	vector<node> v(n);
	for(int i=0;i<n;++i)cin>>v[i].save;
	for(int i=0;i<n;++i){cin>>v[i].sale;v[i].unite=v[i].sale/v[i].save;}
	sort(v.begin(),v.end(),cmp);
	while(d>0&&in<v.size()){
		if(v[in].save<=d){
			d-=v[in].save;
			maxsum+=v[in].sale;
			++in;
		}else{
			maxsum+=v[in].unite*d;
			d=0;
		}
	}
	printf("%.2lf",maxsum);
	return 0;
}
