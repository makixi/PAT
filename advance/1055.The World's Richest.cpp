#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	char name[10];
	int age;
	int net;
};
vector<node> total;
vector<node> res;
bool cmp(node a,node b){
	if(a.net!=b.net)return a.net>b.net;
	if(a.age!=b.age)return a.age<b.age;
	return (strcmp(a.name,b.name)<0);
}
int main(){
	int n,k,m,amin,amax;
	scanf("%d%d",&n,&k);
	total.resize(n);
	for(int i=0;i<n;++i)
		scanf("%s%d%d",&total[i].name,&total[i].age,&total[i].net);
	sort(total.begin(),total.end(),cmp);
	for(int i=1;i<=k;++i){
		res.clear();
		scanf("%d%d%d",&m,&amin,&amax);
		for(int j=0;j<total.size()&&res.size()<m;++j)
			if(total[j].age>=amin&&total[j].age<=amax)
				res.push_back(total[j]);
		printf("Case #%d:\n",i);
		if(!res.size())printf("None\n");
		else
			for(int j=0;j<m&&j<res.size();++j)
				printf("%s %d %d\n",res[j].name,res[j].age,res[j].net);
	}
	return 0;
}
