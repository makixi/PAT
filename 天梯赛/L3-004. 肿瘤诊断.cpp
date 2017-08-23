#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int table[1300][130][70];//x,y,z
bool vis[1300][130][70];
struct node{
	int x,y,z;
};
int dx[]={0,0,1,0,0,-1};
int dy[]={0,1,0,0,-1,0};
int dz[]={1,0,0,-1,0,0};
int m,n,l,t;
bool judge(int x,int y,int z){
	if(x<0||y<0||z<0||x>=m||y>=n||z>=l)return false;
	if(vis[x][y][z])return false;
	if(!table[x][y][z])return false;
	return true;
}
int bfs(int x,int y,int z){
	int cnt=0;
	queue<node> q;
	vis[x][y][z]=true;
	node tmp,nex;
	tmp.x=x;tmp.y=y;tmp.z=z;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.front();q.pop();
		cnt++;
		for(int i=0;i<6;++i){
			int newx=tmp.x+dx[i];
			int newy=tmp.y+dy[i];
			int newz=tmp.z+dz[i];
			if(judge(newx,newy,newz)){
				vis[newx][newy][newz]=true;
				nex.x=newx;nex.y=newy;nex.z=newz;
				q.push(nex);
			}
		}
	}
	if(cnt>=t)return cnt;
	else return 0;
}
int main(){
	int res=0;
	cin>>m>>n>>l>>t;
	for(int i=0;i<l;++i)
		for(int j=0;j<m;++j)
			for(int k=0;k<n;++k)
				cin>>table[j][k][i];
	for(int i=0;i<l;++i)
		for(int j=0;j<m;++j)
			for(int k=0;k<n;++k){
				if(!vis[j][k][i]&&table[j][k][i])
					res+=bfs(j,k,i);
			}
	printf("%d\n",res);
	return 0;
}
