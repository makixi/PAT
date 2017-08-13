#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 510;
int dis[maxn];
int tim[maxn];
int eachdis[maxn][maxn];
int eachtime[maxn][maxn];
int weight[maxn];
int pre[maxn];
bool vis[maxn];
int source, des;
vector<int> dispath, timepath,timepre[maxn],tmp;
int minpath = inf;
void dfsDis(int u) {
	dispath.push_back(u);
	if (u == source)return;
	dfsDis(pre[u]);
}
void dfsTime(int u) {
	tmp.push_back(u);
	if (u == source) {
		if (tmp.size() < minpath) {
			minpath = tmp.size();
			timepath = tmp;
		}
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < timepre[u].size(); ++i)
		dfsTime(timepre[u][i]);
	tmp.pop_back();
}
int main() {
	int n, m;
	int a, b, c, d, e;
	scanf("%d%d", &n, &m);
	memset(dis, inf, sizeof(dis));
	memset(eachdis, inf, sizeof(eachdis));
	memset(tim, inf, sizeof(tim));
	memset(eachtime, inf, sizeof(eachtime));
	memset(weight, inf, sizeof(weight));
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		eachtime[a][b] = e;
		eachdis[a][b] = d;
		if (c != 1) {
			eachtime[b][a] = e; eachdis[b][a] = d;
		}
	}
	scanf("%d%d", &source, &des);
	dis[source] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, minn = inf;
		for(int j=0;j<n;++j)
			if (!vis[j] && dis[j] < minn) {
				minn = dis[j]; 
				u = j;
			}
		if (u == -1)break;
		vis[u] = true;
		for (int j = 0; j < n; ++j) 
			if (!vis[j] && eachdis[u][j] != inf) 
				if (dis[j] > dis[u] + eachdis[u][j]) {
					dis[j] = eachdis[u][j] + dis[u];
					pre[j] = u;
					weight[j] = weight[u] + eachtime[u][j];
				}
				else if (dis[j] == dis[u] + eachdis[u][j] && weight[j] > weight[u] + eachtime[u][j]) {
					weight[j] = weight[u] + eachtime[u][j];
					pre[j] = u;
				}
	}
	dfsDis(des);
	memset(vis, false, sizeof(vis));
	tim[source] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, minn = inf;
		for(int j=0;j<n;++j)
			if (!vis[j] && tim[j] < minn) {
				minn = tim[j];
				u = j;
			}
		if (u == -1)break;
		vis[u] = true;
		for (int j = 0; j < n; ++j) 
			if (!vis[j] && eachtime[u][j] != inf) 
				if (tim[j] > tim[u] + eachtime[u][j]) {
					tim[j] = tim[u] + eachtime[u][j];
					timepre[j].clear();
					timepre[j].push_back(u);
				}
				else if (tim[j] == tim[u] + eachtime[u][j])
					timepre[j].push_back(u);
	}
	dfsTime(des);
	printf("Distance = %d", dis[des]);
	if (dispath == timepath)
		printf("; Time = %d: ", tim[des]);
	else {
		printf(": ");
		for (int i = dispath.size() - 1; i >= 0; i--) {
			printf("%d", dispath[i]);
			if (i != 0) printf(" -> ");
		}
		printf("\n");
		printf("Time = %d: ", tim[des]);
	}
	for (int i = timepath.size() - 1; i >= 0; i--) {
		printf("%d", timepath[i]);
		if (i != 0) printf(" -> ");
	}
	return 0;
}
