#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define MAX 210
#define INF 9999999
int n;//city
int k;//routes
vector<int> pre[MAX],path,temppath;
map<int, string> its;
map<string, int> sti;
int dis[MAX][MAX], weight[MAX], happy[MAX];
int maxhappy=0,cnt=0;
double avehappy;
bool vis[MAX];

void dfs(int v) {
	temppath.push_back(v);
	if (v == 0) {
		int temphappy = 0;
		double tempave;
		for (int i = 0; i < temppath.size(); ++i) {
			temphappy += happy[temppath[i]];
		}
		tempave = 1.0*temphappy / (temppath.size()-1);
		if (temphappy > maxhappy) {
			maxhappy = temphappy;
			avehappy = tempave;
			path = temppath;
		}
		else if (temphappy == maxhappy&&tempave > avehappy) {
			avehappy = tempave;
			path = temppath;
		}
		cnt += 1;
		temppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); ++i)
		dfs(pre[v][i]);
	temppath.pop_back();
}

int main() {
	fill(dis[0], dis[0] + MAX*MAX, INF);
	fill(weight, weight + MAX, INF);
	string start;
	cin >> n >> k>>start;
	int ha;
	string temp;
	sti[start] = 0;
	its[0] = start;
	for (int i = 1; i < n; ++i) {
		cin >> temp>>ha;
		sti[temp] = i; its[i] = temp;
		happy[i] = ha;
	}
	string a, b; int e;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> e;
		dis[sti[a]][sti[b]] = dis[sti[b]][sti[a]]=e;
	}
	weight[0] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, minn = INF;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && weight[j] < minn) {
				minn = weight[j];
				u = j;
			}
		}
		if (u == -1)break;
		vis[u] = true;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && dis[u][j] != INF) {
				if (weight[j] > dis[u][j] + weight[u]) {
					weight[j] = dis[u][j] + weight[u];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if (weight[j] == dis[u][j] + weight[u]) {
					pre[j].push_back(u);
				}
			}
		}
	}
	int rom = sti["ROM"];
	dfs(rom);
	cout << cnt << " " << weight[rom] << " " << maxhappy << " " << (int)avehappy<<endl;
	for (int i = path.size() - 1; i >= 1; --i) {
		cout << its[path[i]] << "->";
	}
	cout << "ROM";
	return 0;
}
