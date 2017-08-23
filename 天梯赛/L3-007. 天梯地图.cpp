#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int inf = 0x3f3f3f3f;
vector<int> timepath, dispath, tmppath, dispre[maxn];
int e[maxn][maxn], t[maxn][maxn];
int  timepre[maxn];
bool vis[maxn];
int dis[maxn],weight[maxn];
int n, source, des;
void disDfs(int v) {
	tmppath.push_back(v);
	if (v == source) {
		if (tmppath.size()<dispath.size() || dispath.size() == 0)
			dispath = tmppath;
		tmppath.pop_back();
		return;
	}
	for(int i=0;i<dispre[v].size();++i)
		disDfs(dispre[v][i]);
	tmppath.pop_back();
}
void timeDfs(int v) {
	timepath.push_back(v);
	if (v == source) 
		return;
	timeDfs(timepre[v]);
}
int main() {
	int m;
	fill(e[0], e[0] + maxn*maxn, inf);
	fill(t[0], t[0] + maxn*maxn, inf);
	cin >> n >> m;
	while (m--) {
		int a, b, c, d, f;
		cin >> a >> b >> c >> d >> f;
		e[a][b] = d;
		t[a][b] = f;
		if (!c) {
			e[b][a] = d;
			t[b][a] = f;
		}
	}
	cin >> source >> des;
	fill(dis, dis + maxn, inf);
	fill(vis, vis + maxn, false);
	dis[source] = 0;
	for (int i = 0; i<n; ++i) {
		int u = -1, minn = inf;
		for (int j = 0; j<n; ++j)
			if (!vis[j] && dis[j]<minn) {
				minn = dis[j];
				u = j;
			}
		if (u == -1)break;
		vis[u] = true;
		for (int j = 0; j<n; ++j)
			if (!vis[j] && e[u][j] != inf) {
				if (dis[j]>dis[u] + e[u][j]) {
					dis[j] = dis[u] + e[u][j];
					dispre[j].clear();
					dispre[j].push_back(u);
				}
				else if (dis[j] == dis[u] + e[u][j]) {
					dispre[j].push_back(u);
				}
			}
	}
	disDfs(des);
	fill(vis, vis + maxn, false);
	fill(dis, dis + maxn, inf);
	fill(weight, weight + maxn, inf);
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
		for(int j=0;j<n;++j)
			if (!vis[j] && t[u][j] != inf) {
				if (dis[j] > dis[u] + t[u][j]) {
					dis[j] = dis[u] + t[u][j];
					timepre[j] = u;
					weight[j] = weight[u] + e[u][j];
				}
				else if (dis[j] == dis[u] + t[u][j] && weight[j] > weight[u] + e[u][j]) {
					timepre[j] = u;
					weight[j] = weight[u] + e[u][j];
				}
			}
	}
	timeDfs(des);
	printf("Time = %d: ", timepath.size());
	for (int i = timepath.size() - 1; i >= 0; --i) {
		if (i != timepath.size() - 1)cout << " => ";
		cout << timepath[i];
	}
	printf("Distance = %d: ", dispath.size());
	for (int i = dispath.size() - 1; i >= 0; --i) {
		if (i != dispath.size() - 1)cout << " => ";
		cout << dispath[i];
	}
	return 0;
}
