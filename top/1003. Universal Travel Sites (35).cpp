#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 510 * 2;
const int inf = 0x3f3f3f3f;
int n, tot = 3, ss = 1, dd = 2;
int e[maxn][maxn], Layer[maxn];
bool vis[maxn];
bool CountLayer() {
	queue<int> q;
	memset(Layer, 0xff, sizeof(Layer));
	q.push(ss);
	Layer[ss] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for(int i=1;i<tot;++i)
			if (Layer[i] == -1 && e[u][i] > 0) {
				Layer[i] = Layer[u] + 1;
				if (i == dd) return true;
				else q.push(i);
			}
	}
	return false;
}
int Dinic() {
	int flow = 0;
	deque<int> q;
	while (CountLayer()) {
		q.push_back(ss);
		memset(vis, false, sizeof(vis));
		vis[ss] = true;
		int i;
		while (!q.empty()) {
			int nd = q.back();
			if (nd == dd) {
				int minn = inf, minst;
				for (int i = 1; i < q.size(); ++i) {
					int vs = q[i - 1], ve = q[i];
					if (e[vs][ve] > 0 && e[vs][ve] < minn) {
						minn = e[vs][ve];
						minst = vs;
					}
				}
				flow += minn;
				for (int i = 1; i < q.size(); ++i) {
					e[q[i - 1]][q[i]] -= minn;
					e[q[i]][q[i - 1]] += minn;
				}
				while (!q.empty() && q.back()!= minst) {
					vis[q.back()] = false;
					q.pop_back();
				}
			}
			else {
				for (i = 1; i <tot; ++i)
					if (e[nd][i]>0 && Layer[i] == Layer[nd] + 1 && !vis[i]) {
						vis[i] = true;
						q.push_back(i);
						break;
					}
				if (i>=tot)q.pop_back();
			}
		}
	}
	return flow;
}
int main() {
	ios::sync_with_stdio(false);
	map<string, int> getid;
	string st, des;
	cin >> st >> des >> n;
	getid[st] = 1; getid[des] = 2;
	for (int i = 0; i < n; ++i) {
		string a, b;
		int d;
		cin >> a >> b >> d;
		if (!getid[a])getid[a] = tot++;
		if (!getid[b])getid[b] = tot++;
		e[getid[a]][getid[b]] += d;
	}
	cout << Dinic() << "\n";
	return 0;
}
