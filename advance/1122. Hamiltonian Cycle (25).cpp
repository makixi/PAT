#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=210;
bool table[maxn][maxn]={false};
bool vis[maxn]={false};
int main(){
	int n,m,k,a,b,num,be;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		table[a][b]=table[b][a]=1;
	} 
	cin>>k;
	while(k--){
		bool flag=true;
		cin>>num;
		vector<int> v(num);
		for(int i=0;i<num;++i){
			cin>>v[i];
			vis[v[i]]=true;
		}
		if(v[0]!=v[num-1]) printf("NO\n");
		else if(num!=n+1) printf("NO\n");
		else{
			for(int i=1;i<=n;++i)
				if(!vis[i]){
					flag=false;
					break;
				}
			for(int i=1;i<num;++i)
				if(!table[v[i]][v[i-1]]){
					flag=false;
					break;
				}
			if(flag)printf("YES\n");
			else printf("NO\n");
		}
		if(k)memset(vis,false,sizeof(vis));
	}
	return 0;
}
