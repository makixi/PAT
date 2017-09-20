#include<iostream>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
vector<vector<int> > e;
int n,m;
int main(){
	cin>>n>>m;
	e.resize(n);
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int k;
	cin>>k;
	while(k--){
		int num;cin>>num;
		set<pair<int,int>> s;
		for(int i=0;i<num;++i){
			int tmp;
			cin>>tmp;
			for(int i=0;i<e[tmp].size();++i){
				if(tmp>e[tmp][i])s.insert(make_pair(e[tmp][i],tmp));
				else s.insert(make_pair(tmp,e[tmp][i]));
			}
		}
		if(s.size()==m)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
