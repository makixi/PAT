#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=10005;
const int inf=0x3f3f3f3f;
int n,s,t;
int line[maxn][maxn],huan=inf;
vector<int> e[maxn],tmp,res;
bool vis[maxn];
int gethuan(){
	int ans=0;
	int pre=line[tmp[0]][tmp[1]];	
	for(int i=1;i<tmp.size();++i){
		if(pre!=line[tmp[i-1]][tmp[i]])
			++ans; 
		pre=line[tmp[i-1]][tmp[i]];
	}
	return ans;
}
void getpath(){
	int preline=line[res[0]][res[1]],st=res[0];
	for(int i=2;i<res.size();++i){
		int currline=line[res[i-1]][res[i]];
		if(currline==preline){
			continue;
		}else{
			printf("Go by the line of company #%d from %04d to %04d.\n",preline,st,res[i-1]);
			st=res[i-1];
			preline=currline;
		}
	}
	printf("Go by the line of company #%d from %04d to %04d.\n",preline,st,res[res.size()-1]);
}
void dfs(int u){
	tmp.push_back(u);
	if(u==t){
		int tmph=gethuan();
		if(tmp.size()<res.size()||res.size()==0){
			res=tmp;
			huan=tmph;
		}else if(tmp.size()==res.size()&&tmph<huan){
			huan=tmph;
			res=tmp;
		}
		tmp.pop_back();
		return;	
	}
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(!vis[v]){
			vis[v]=true;
			dfs(v);
			vis[v]=false;
		}
	}
	tmp.pop_back();
}
int main(){
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		int m,pre;
		cin>>m;
		if(m)cin>>pre;
		for(int j=1;j<m;++j){
			int tmp;
			cin>>tmp;
			e[tmp].push_back(pre);
			e[pre].push_back(tmp);
			line[tmp][pre]=line[pre][tmp]=i;
			pre=tmp;
		}
	}
	int k;
	cin>>k;
	while(k--){
		cin>>s>>t;
		memset(vis,false,sizeof(vis));
		vis[s]=true;
		huan=inf;
		res.clear();
		dfs(s);
		if(huan!=inf)cout<<res.size()-1<<endl;
		else{
			cout<<"Sorry, no line is available.\n";
			continue;
		}
		getpath();
	}
	return 0;
}
