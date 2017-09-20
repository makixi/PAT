#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int val[maxn],nex[maxn];
int main(){
	int ad,n,k;
	cin>>ad>>n>>k;
	vector<int> v1,v2,v3;//负数 [0,k]  大于k 
	for(int i=0;i<n;++i){
		int tmp;
		cin>>tmp;
		cin>>val[tmp]>>nex[tmp];
	}
	for(;ad!=-1;ad=nex[ad]){
		if(val[ad]<0)v1.push_back(ad);
		else if(val[ad]>k)v3.push_back(ad);
		else v2.push_back(ad);
	}
	v1.insert(v1.end(),v2.begin(),v2.end());
	v1.insert(v1.end(),v3.begin(),v3.end());
	for(int i=0;i<v1.size();++i){
		printf("%05d %d ",v1[i],val[v1[i]]);
		if(i==v1.size()-1)printf("-1");
		else printf("%05d\n",v1[i+1]);
	}
	return 0;
}
