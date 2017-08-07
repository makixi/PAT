#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int m,n,l,t;
int matrix[1300][130][80]={0};
bool vis[1300][130][80]={false};
int change[3][6]={{1,0,0,-1,0,0},{0,1,0,0,-1,0},{0,0,1,0,0,-1}};
//change[0]->x change[1]->y change[2]->z
struct node{
	int x;
	int y;
	int z;
};
bool judge(int x,int y,int z){
	if(x<0||x>=m||y<0||y>=n||z<0||z>=l)return false;
	if(vis[x][y][z])return false;
	if(matrix[x][y][z]==0)return false;
	return true;
}
int bfs(int x,int y,int z){
	int cnt=0;
	node tmp;
	tmp.x=x;tmp.y=y;tmp.z=z;
	queue<node>q;
	q.push(tmp);
	vis[x][y][z]=true;
	while(!q.empty()){
		node newtmp=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<6;++i){
			int newx=newtmp.x+change[0][i];
			int newy=newtmp.y+change[1][i];
			int newz=newtmp.z+change[2][i];
			if(judge(newx,newy,newz)){
				vis[newx][newy][newz]=true;
				tmp.x=newx;tmp.y=newy;tmp.z=newz;
				q.push(tmp);
			}
		}
	}
	if(cnt>=t)
		return cnt;
	else
		return 0;
}
int main(){
	int cnt=0;
	//cin>>m>>n>>l>>t;
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i=0;i<l;++i)
		for(int j=0;j<m;++j)
			for(int k=0;k<n;++k)
				scanf("%d",&matrix[j][k][i]);	//¶ÔÓ¦x,y,z
	for(int i=0;i<l;++i)
		for(int j=0;j<m;++j)
			for(int k=0;k<n;++k)
				if(matrix[j][k][i]&&!vis[j][k][i])
					cnt+=bfs(j,k,i);
	cout<<cnt;
	return 0;
}
