#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	double price;
	double amount;
	double cp;	//cost performance
};
bool cmp(node a,node b){
	return a.cp<b.cp;
}
vector<node> v;
int main(){
	int n,d;
	double res=0.0;
	scanf("%d %d",&n,&d);
	v.resize(n);
	for(int i=0;i<n;++i)scanf("%lf",&v[i].amount);
	for(int i=0;i<n;++i){
		scanf("%lf",&v[i].price);
		v[i].cp=v[i].amount/v[i].price;
	}
	sort(v.begin(),v.end(),cmp);
	int index=0;
	while(d){
		if(index>=v.size())break;
		if(v[index].amount<=d){
			d-=v[index].amount;
			res+=v[index].price;
			++index;
		}
		else{
			res+=d/v[index].cp;
			break;
		}
	}
	printf("%.2lf",res);
	return 0;
}
