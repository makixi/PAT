#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> 
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f;
vector<int> e[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> in(n+1);
    while(m--){
    	int a,b;
    	cin>>a>>b;
    	e[a].push_back(b);
    	in[b]++;
	}
	int k;
	cin>>k;
	bool first=true;
	for(int i=0;i<k;++i){
		bool flag=true;
		vector<int> tmp(n),tin=in;
		for(int j=0;j<n;++j)cin>>tmp[j];
		for(int j=0;j<n;++j){
			if(tin[tmp[j]]!=0){
				flag=false;
				break;
			}
			for(int l=0;l<e[tmp[j]].size();++l)tin[e[tmp[j]][l]]--;
		}
		if(!flag){
			if(!first)cout<<" ";
			first=false;
			cout<<i;
		}
	}
    return 0;
}
