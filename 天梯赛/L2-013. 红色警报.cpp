#include<iostream>
#include<cstring>
using namespace std;
const int maxn=510;
bool vis[maxn];
bool connect[maxn][maxn];
int n;
void dfs(int i){
	vis[i]=true;
	for(int j=0;j<n;++j)
		if(!vis[j]&&connect[i][j])
			dfs(j);
}
int connectcnt(){
	int res=0;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;++i)
		if(!vis[i]){
			dfs(i);
			++res;
		}
	return res;
}
int main(){
	int m,a,b,k,pre,tmp;
	cin>>n>>m;
	memset(connect,false,sizeof(connect));
	for(int i=0;i<m;++i){
		cin>>a>>b;
		connect[a][b]=connect[b][a]=true;
	}
	pre=connectcnt();
	cin>>k;
	for(int cnt=0;cnt<k;++cnt){
		cin>>a;
		for(int i=0;i<n;++i)
			if(connect[i][a]){
				connect[i][a]=false;
				connect[a][i]=false;
			}
		tmp=connectcnt();
		if(tmp>pre+1)
			printf("Red Alert: City %d is lost!\n", a);
        else
            printf("City %d is lost.\n", a);
        pre=tmp;
        if(cnt==n-1)printf("Game Over.\n");
	}
	return 0;
}
