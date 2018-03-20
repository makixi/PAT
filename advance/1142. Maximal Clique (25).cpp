#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=210;
const int inf=0x3f3f3f3f;
bool e[maxn][maxn];
vector<int> edge[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		e[a][b]=e[b][a]=true;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		vector<int> tmp;
		while(k--){
			int val;
			cin>>val;
			tmp.push_back(val);
		}
		bool no=false;
		for(int i=0;i<tmp.size();++i){
			for(int j=i+1;j<tmp.size();++j)
				if(!e[tmp[i]][tmp[j]]){
					no=true;
					break;
				}
			if(no)break;
		}
		if(no){
			cout<<"Not a Clique\n";
			continue;
		}
		bool notmax=false;
		for(int i=1;i<=n;++i){
			bool all=true;
			for(int j=0;j<tmp.size();++j){
				int val=tmp[j];
				if(!e[i][val]){
					all=false;
					break;
				}
			}
			if(all){
				notmax=true;
				break;
			}
		}
		if(notmax){
			cout<<"Not Maximal\n";
			continue;
		}
		cout<<"Yes\n";
	}
	return 0;
}
