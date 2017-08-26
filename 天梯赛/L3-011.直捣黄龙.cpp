#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 210;
const int inf = 0x3f3f3f3f;
int maxtown=0;
vector<int> tmppath, path, pre[maxn];
int e[maxn][maxn];
bool vis[maxn];
int weight[maxn],dis[maxn];
int n,res=0;
map<string, int> m;
map<int, string> m2;
void init() {
	string name;
	int num;
	for (int i = 1; i < n; ++i) {
		cin >> name >> num;
		m[name] = i; m2[i] = name;
		weight[i] = num;
	}
}
void dfs(int u,int st,int town) {
	tmppath.push_back(u);
	if (u == st) {
		res++;
		if (tmppath.size() > path.size()) {
			path = tmppath;
			maxtown = town;
		}
		else if (tmppath.size() == path.size() && town > maxtown) {
			path = tmppath;
			maxtown = town;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[u].size(); ++i)
		dfs(pre[u][i],st,town+weight[pre[u][i]]);
	tmppath.pop_back();
}
int main() {
	fill(e[0], e[0] + maxn*maxn, inf);
	fill(vis, vis + maxn, false);
	fill(dis, dis + maxn, inf);
	int k;
	string st, des;
	cin >> n>>k >> st >> des;
	m[st] = 0; m2[0] = st;
	init();
	while (k--) {
		string a, b;
		int d;
		cin >> a >> b >> d;
		e[m[a]][m[b]] = e[m[b]][m[a]] = d;
	}

	dis[m[st]] = 0;//dis[start]=0
	for (int i = 0; i < n; ++i) {
		int minn = inf, u = -1;
		for(int j=0;j<n;++j)
			if (!vis[j] && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		if (u == -1)break;
		vis[u] = true;
		for(int j=0;j<n;++j)
			if (!vis[j] && e[u][j]!= inf) 
				if (dis[j] > dis[u] + e[u][j]) {
					dis[j] = dis[u] + e[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if (dis[j] == dis[u] + e[u][j]) 
					pre[j].push_back(u);
	}
	dfs(m[des],m[st],weight[m[des]]);
	for (int i = path.size()-1; i>=0 ; --i) {
		if (i != path.size() - 1)cout << "->";
		cout << m2[path[i]];
	}
	printf("\n%d %d %d", res, dis[m[des]], maxtown);
	return 0;
}
