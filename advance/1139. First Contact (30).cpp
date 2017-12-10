#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int,bool> gender;//false if girl, true is boy
vector<int> e[100000];
bool vis[100000];
map<string,bool> exist;
int A,B;
vector<pair<int,int> > res;
void findd(int C){
	for(int i=0;i<e[C].size();++i){
		int D=e[C][i];
		if(!vis[D]&&gender[D]==gender[B]&&find(e[B].begin(),e[B].end(),D)!=e[B].end())
			res.push_back(make_pair(C,D));
	}
}
void findc(){
	for(int i=0;i<e[A].size();++i){
		int C=e[A][i];
		if(!vis[C]&&gender[A]==gender[C])findd(C);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--){
		string a,b;
		int ai,bi;
		cin>>a>>b;
		exist[a]=true;
		exist[b]=true;
		if(a[0]=='-'){
			ai=(stoi(a.substr(1,a.length()-1)));
			gender[ai]=false;
		}else{
			ai=stoi(a);
			gender[ai]=true;
		}
		if(b[0]=='-'){
			bi=stoi(b.substr(1,b.length()-1));
			gender[bi]=false;
		}else{
			bi=stoi(b);
			gender[bi]=true;
		}
		e[ai].push_back(bi);
		e[bi].push_back(ai);
	}
	int k;
	scanf("%d",&k);
	while(k--){
		string a,b;
		cin>>a>>b;
		if(!exist[a]||!exist[b]){
			cout<<0<<"\n";
			continue;
		}
		res.clear();
		if(a[0]=='-') A=(stoi(a.substr(1,a.length()-1)));
		else A=stoi(a);
		if(b[0]=='-') B=stoi(b.substr(1,b.length()-1));
		else B=stoi(b);
		vis[A]=true;
		vis[B]=true;
		findc();
		vis[A]=false;
		vis[B]=false;
		sort(res.begin(),res.end());
		cout<<res.size()<<"\n";
		for(int i=0;i<res.size();++i)
			printf("%04d %04d\n",res[i].first,res[i].second);
	}
	return 0;
} 
