#include<iostream>
#include<set>
#include<cmath>
#include<string>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 101;
int n, m;
double minsum = inf;
int matrix[maxn][maxn];
bool vis[maxn][maxn];
double dis[maxn][maxn];
int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { 0,1,-1,0,1,-1,1,-1 };
struct node {
	int x, y;
};
int left(node a,node b,node c) {
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
bool judge(int x, int y, node st, node des) {
	if (x < 0 || x >= n || y < 0 || y >= m)return false;
	if (x == des.x&&y == des.y)return true;
	if (left(st, des, node{ x,y }) > 0)return true;
	return false;
}
double bfs(node st,node des) {
	fill(vis[0], vis[0] + maxn*maxn, false);
	fill(dis[0], dis[0] + maxn*maxn, inf);
	queue<node> q;
	node nex;
	double w;
	dis[st.x][st.y] = matrix[st.x][st.y];
	q.push(st);
	while (!q.empty()) {
		node tmp = q.front(); q.pop();
		vis[tmp.x][tmp.y] = false;
		for (int i = 0; i < 8; ++i) {
			int newy = tmp.y + dy[i];
			int newx = tmp.x + dx[i];
			if (judge(newx,newy,st,des)) {
				w = matrix[newx][newy];
				if (dx[i] && dy[i])
					w += (sqrt(2) - 1)*(matrix[tmp.x][tmp.y] + matrix[newx][newy]);
				if (dis[newx][newy] > dis[tmp.x][tmp.y] + w) {//¼ÇÂ¼×î¶Ì¾àÀë
					dis[newx][newy] = dis[tmp.x][tmp.y] + w;
					if (!vis[newx][newy]) {
						nex.x = newx;
						nex.y = newy;
						q.push(nex);
						vis[newx][newy] = true;
					}
				}
			}
		}
	}
	return dis[des.x][des.y];
}
int main() {
	node st, des;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrix[i][j];
	cin >> st.y >> st.x >> des.y >> des.x;//(st.x,st.y)µ½(des.x,des.y)
	printf("%.2lf",bfs(st,des)+bfs(des,st)-matrix[st.x][st.y]-matrix[des.x][des.y]);
	return 0;
}
