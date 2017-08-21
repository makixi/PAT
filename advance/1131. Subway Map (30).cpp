#include<iostream>
#include<vector>
using namespace std;
const int maxn=10000;
const int inf=0x3f3f3f3f;
int line[maxn][maxn];
vector<int> v[maxn];
vector<int> path,res;
bool vis[maxn];
int mincnt,start,des,minchange;
void printres(){
	printf("%d\n",mincnt);
	int preline=line[res[0]][res[1]],mark=0;
	for(int i=1;i<res.size();++i){
		int tmpline=line[res[i-1]][res[i]];
		if(tmpline!=preline){
			printf("Take Line#%d from %04d to %04d.\n", preline, res[mark], res[i - 1]);
			mark=i-1;
            preline = tmpline;
		}
	}
	printf("Take Line#%d from %04d to %04d.\n", preline, res[mark], res[res.size() - 1]);
}
int getchange(vector<int> v){
	int change=0,preline;
	for(int i=1;i<v.size();++i){
		if(line[v[i]][v[i-1]]!=preline){
			change++;
			preline=line[v[i-1]][v[i]];
		}
	}
	return change;
}
void dfs(int curr,int cnt){
	if(curr==des){
		int tmpchange=getchange(path);
		if(cnt<mincnt||(cnt==mincnt&&tmpchange<minchange)){
			mincnt=cnt;
			minchange=tmpchange;
			res=path;
		}
		return;
	}
	for(int i=0;i<v[curr].size();++i){
		if(!vis[v[curr][i]]){
			vis[v[curr][i]]=true;
			path.push_back(v[curr][i]);
			dfs(v[curr][i],cnt+1);
			path.pop_back();
			vis[v[curr][i]]=false;
		}
	}
}
int main(){
	int n,m,pre,tmp;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>m>>pre;
		for(int j=1;j<m;++j){
			cin>>tmp;
			line[pre][tmp]=line[tmp][pre]=i;//µÚiÌõsubway
			v[pre].push_back(tmp);
			v[tmp].push_back(pre);
			pre=tmp;
		}
	}
	cin>>m;
	while(m--){
		cin>>start>>des;
		vis[start]=true;
		mincnt=inf;
		minchange=inf;
		path.push_back(start);
		dfs(start,0);
		printres();
		vis[start]=false;
		path.clear();
		res.clear();
	}
	return 0;
}
