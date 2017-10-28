#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<string>
using namespace std;
const int maxn=510*2;
const int inf=0x3f3f3f3f;
int n,cnt=0;
int ss,dd; 
int Layer[maxn];
bool vis[maxn];
int e[maxn][maxn];
map<string,int> change;
bool CountLayer(){
	queue<int> q;
	memset(Layer,0xff,sizeof(Layer));
	q.push(ss);
	Layer[ss]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=cnt;++i){
			if(Layer[i]==-1&&e[u][i]>0){
				Layer[i]=Layer[u]+1;
				if(i==dd)return true;
				else q.push(i);
			}
		}
	}
	return false;
}
int Dinic(){
	int MaxFlow=0;
	deque<int> q;
	while(CountLayer()){
		q.push_back(ss);
		memset(vis,false,sizeof(vis));
		vis[ss]=true;
		int i;
		while(!q.empty()){
			int nd=q.back();
			if(nd==dd){
				int minn=inf,minst;
				for(i=1;i<q.size();++i){
					int vs=q[i-1];
					int ve=q[i];
					if(e[vs][ve]>0&&e[vs][ve]<minn){
						minn=e[vs][ve];minst=vs;
					}
				}
				MaxFlow+=minn;
				for(i=1;i<q.size();++i){
					e[q[i-1]][q[i]]-=minn;
					e[q[i]][q[i-1]]+=minn;
				}
				while(!q.empty()&&q.back()!=minst){
					vis[q.back()]=false;q.pop_back();
				}
			}else{
				for(i=1;i<=cnt;++i)
					if(e[nd][i]>0&&Layer[i]==Layer[nd]+1&&!vis[i]){
						vis[i]=true;
						q.push_back(i);
						break;
					}
				if(i>cnt)q.pop_back();
			}
		}
	}
	return MaxFlow;
}
int main(){
	ios::sync_with_stdio(false);
	string st,des;
	cin>>st>>des>>n;
	for(int i=0;i<n;++i){
		string a,b;int w;
		cin>>a>>b>>w;
		if(change[a]==0)change[a]=++cnt;
		if(change[b]==0)change[b]=++cnt;
		e[change[a]][change[b]]+=w;
	}
	ss=change[st];dd=change[des];
	cout<<Dinic()<<endl;
	return 0;
}
