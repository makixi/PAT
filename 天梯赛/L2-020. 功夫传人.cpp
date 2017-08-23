#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
double res=0.0;
double r;
struct node{
	vector<int> child;
	double times=0.0;
};
vector<node> v;
void dfs(int cur,double kung){
	if(v[cur].times){
		res+=kung*v[cur].times;
		return;
	}
	for(int i=0;i<v[cur].child.size();++i){
		dfs(v[cur].child[i],kung*r);
	}
	return;
}
int main(){
	int n,k;
	double z;
	cin>>n>>z>>r;
	r=(100-r)/100;
	v.resize(n);
	for(int i=0;i<n;++i){
		cin>>k;
		if(!k){
			cin>>v[i].times;
		}else{
			v[i].child.resize(k);
			for(int j=0;j<k;++j)
				cin>>v[i].child[j];
		}
	}
	dfs(0,z);
	cout<<int(res);
	return 0;
}
