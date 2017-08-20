#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn=51;
set<int> s[maxn];
int main(){
	int n,m,tmp,k,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&m);
		while(m--){
			scanf("%d",&tmp);
			s[i].insert(tmp);
		}
	}
	scanf("%d",&k);
	while(k--){
		scanf("%d %d",&a,&b);
		set<int> tmp;
		for(set<int>::iterator it=s[a].begin();it!=s[a].end();++it)
			tmp.insert(*it);
		for(set<int>::iterator it=s[b].begin();it!=s[b].end();++it)
			tmp.insert(*it);
		double res=(s[a].size()+s[b].size()-tmp.size())/(tmp.size()*1.0);
		printf("%.2lf%%\n",res*100);
	}
	return 0;
}
