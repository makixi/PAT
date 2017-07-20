#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1010
#define INF 9999999

int n, m, s, d;//city,highways,start,destination
int dis[MAX][MAX],cost[MAX][MAX];
int weight[MAX];
bool vis[MAX];
vector<int> path, temppath;
vector<int> pre[MAX];
int mincost = INF;

void dfs(int v) {
	if (v == s) {
		temppath.push_back(v);
		int tempcost = 0;
		for (int i = temppath.size() - 1; i > 0; i--)
		{
			int id = temppath[i];
			int nextid = temppath[i - 1];
			tempcost += cost[id][nextid];
		}
		if (tempcost < mincost) {
			mincost = tempcost;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for (int i = 0; i < pre[v].size(); ++i)
		dfs(pre[v][i]);
	temppath.pop_back();
}

int main() {
	fill(dis[0], dis[0] + MAX*MAX, INF);
	fill(weight, weight + MAX, INF);
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; ++i) {
		int a, b,c,d;
		cin >> a >> b>>c>>d;
		if(dis[a][b]>c)
		{
		dis[b][a] = dis[a][b]=c;
		cost[b][a] = cost[a][b]=d;
	}
	}
	pre[s].push_back(s);
	weight[s] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, minn = INF;
		for (int j = 0; j < n; ++j) {
			if (vis[j] == false && weight[j] < minn) {
				u = j;
				minn = weight[j];
			}
		}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; ++v) {
			if (vis[v] == false && dis[u][v] != INF) {
				if (weight[v] > weight[u] + dis[u][v])
				{
					weight[v] = weight[u] + dis[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (weight[v] == weight[u] + dis[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(d);
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << weight[d] <<" "<< mincost;
	return 0;
}
