#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	vector<double> grade;
	double ave; 
};
bool cmp(node a,node b){
	return a.ave>b.ave;
}
int main(){
	int n,k,m;
	cin>>n>>k>>m;
	vector<node> v(n);
	for(int i=0;i<n;++i){
		v[i].grade.resize(k);
		double sum=0.0,minn=101,maxn=-1;
		for(int j=0;j<k;++j){
			cin>>v[i].grade[j];
			sum+=v[i].grade[j];
			minn=min(minn,v[i].grade[j]);
			maxn=max(maxn,v[i].grade[j]);
		}
		v[i].ave=(sum-minn-maxn)/(double)(k-2);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=m-1;i>=0;--i){
		printf("%.3lf",v[i].ave);
		if(i)cout<<" ";
	}
	return 0;
}
