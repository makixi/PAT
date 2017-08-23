#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1050;
const int inf=0x3f3f3f3f;
int e[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int main(){
	int n,m,k,ds;
	cin>>n>>m>>k>>ds;
	memset(e,inf,sizeof(e));
	
	for (int i = 0; i < k; i++) {
		int tempdis;
		string s, t;
		cin >> s >> t >> tempdis;
		int a, b;
		if (s[0] == 'G') {
			s = s.substr(1);
			a = n + stoi(s);
		}
		else {
			a = stoi(s);
		}
		if (t[0] == 'G') {
			t = t.substr(1);
			b = n + stoi(t);
		}
		else {
			b = stoi(t);
		}
		e[a][b] = tempdis;
		e[b][a] = tempdis;
	}
	int resid=-1;
	double resdis=-1,resave=inf;
	for(int curr=n+1;curr<=n+m;++curr){//所有垃圾桶到其他点的最短距离 
		double mindis=inf,ave=0;
		memset(dis,inf,sizeof(dis));
		memset(vis,false,sizeof(vis));
		dis[curr]=0;
		for(int i=0;i<n+m;++i){
			int u=-1,minn=inf;
			for(int j=1;j<=n+m;++j)
				if(!vis[j]&&dis[j]<minn){
					minn=dis[j];
					u=j;
				}
			if(u==-1)break;
			vis[u]=true;
			for(int j=1;j<=n+m;++j)
				if(!vis[j]&&dis[j]>e[u][j]+dis[u])
					dis[j]=dis[u]+e[u][j];
		}
		for(int i=1;i<=n;++i){
			if(dis[i]>ds){
				mindis=-1;break;
			}
			mindis=min(mindis,dis[i]*1.0);
			ave+=1.0*dis[i];
		}
		if(mindis==-1)continue;
		ave/=n;
		if(mindis>resdis){
			resid=curr;
			resdis=mindis;
			resave=ave;
		}else if(mindis==resdis&&ave<resave){
			resave=ave;
			resid=curr;
		}
	}
	if(resid==-1)printf("No Solution");
	else{
		printf("G%d\n",resid-n);
		printf("%.1f %.1f",resid,resave);
	}
	return 0;
}
