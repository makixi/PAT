#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=205;
const int inf=0x3f3f3f3f;
int n,k,s=1,d=2,tot=2;
string st,des;
map<string,int> m;
map<int,string>m2; 
int shou[maxn],e[maxn][maxn],dis[maxn];
int road[maxn],all=0;
bool vis[maxn];
vector<int> tmp,res,pre[maxn];
void dfs(int u){
	tmp.push_back(u);
	if(u==s){
		int tp=0;
		for(int i=0;i<tmp.size();++i){
			tp+=shou[tmp[i]];
		}
		if(tmp.size()>res.size()){
			res=tmp;
			all=tp;
		}
		else if(tmp.size()==res.size()&&tp>all){
			res=tmp;
			all=tp;
		}
		tmp.pop_back();
		return;
	}
	for(int i=0;i<pre[u].size();++i){
		dfs(pre[u][i]);
	}
	tmp.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	memset(dis,inf,sizeof(dis));
	memset(e,inf,sizeof(e));
	cin>>n>>k>>st>>des;
	m[st]=1;m[des]=2;
	m2[1]=st;m2[2]=des;
	for(int i=1;i<n;++i){
		string s;int tmp;
		cin>>s>>tmp;
		if(!m[s]){
			m[s]=++tot;
			m2[tot]=s;
		}
		shou[m[s]]=tmp;
		//cout<<i<<endl;
	}
	while(k--){
		string a,b;int tmp;
		cin>>a>>b>>tmp;
		e[m[a]][m[b]]=e[m[b]][m[a]]=min(e[m[a]][m[b]],tmp);
	}
	dis[1]=0;
	road[1]=1;
	for(int i=0;i<n;++i){
		int minn=inf,u=-1;
		for(int j=1;j<=n;++j)
			if(!vis[j]&&dis[j]<minn){
				minn=dis[j];
				u=j;
			}
		if(u==-1)break;
		vis[u]=true;
		for(int j=1;j<=n;++j)
			if(!vis[j]&&e[u][j]!=inf){
				if(dis[j]>dis[u]+e[u][j]){
					dis[j]=dis[u]+e[u][j];
					road[j]=road[u];
					pre[j].clear();
					pre[j].push_back(u);
				}else if(dis[j]==dis[u]+e[u][j]){
					road[j]+=road[u];
					pre[j].push_back(u); 
				}
			}
	}
	dfs(d);
	for (int i = res.size()-1; i>=0 ; --i) {
		if (i != res.size() - 1)cout << "->";
		cout << m2[res[i]];
	}
	cout<<endl;
	cout<<road[d]<<" "<<dis[d]<<" "<<all;
	return 0;
}
