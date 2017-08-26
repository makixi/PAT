#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10001;
int line[maxn][maxn];
vector<int> v[maxn],tmppath,path;
bool vis[maxn];
int minchange,minstop;
int st, des;
void printpath() {
	if (!path.size()) {
		printf("Sorry, no line is available.\n");
		return;
	}
	printf("%d\n", minstop);
	int prestop=0, preline = line[path[0]][path[1]];
	for (int i = 1; i < path.size(); ++i) {
		int tmpline = line[path[i - 1]][path[i]];
		if (tmpline != preline) {
			printf("Go by the line of company #%d from %04d to %04d.\n", preline, path[prestop], path[i-1]);
			prestop = i - 1;
			preline = tmpline;
		}
	}
	printf("Go by the line of company #%d from %04d to %04d.\n", preline, path[prestop], path[path.size() - 1]);
}
int getchange(vector<int> path) {
	int pre=0,res=0;
	for (int i = 1; i < path.size(); ++i) 
		if (line[path[i]][path[i - 1]] != pre) {
			pre = line[path[i]][path[i - 1]];
			res++;
		}
	return res;
}
void dfs(int u,int stopnum) {
	if (u == des) {
		int changenum = getchange(tmppath);
		if (stopnum < minstop||(stopnum==minstop&&minchange>changenum)) {
			minstop = stopnum;
			path = tmppath;
			minchange = changenum;
		}
		return;
	}
	for (int i = 0; i < v[u].size(); ++i) 
		if (!vis[v[u][i]]) {
			vis[v[u][i]] = true;
			tmppath.push_back(v[u][i]);
			dfs(v[u][i], stopnum + 1);
			tmppath.pop_back();
			vis[v[u][i]] = false;
		}
}
int main() {
	int n, k, pre, tmp;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k >> pre;
		for (int j = 0; j < k - 1; ++j) {
			cin >> tmp;
			line[pre][tmp] = line[tmp][pre] = i;
			v[tmp].push_back(pre);
			v[pre].push_back(tmp);
			pre = tmp;
		}
	}
	cin >> k;
	while (k--) {
		cin >> st >> des;
		vis[st] = true;
		tmppath.push_back(st);
		minchange = inf;
		minstop = inf;
		dfs(st,0);
		printpath();
		fill(vis, vis + maxn, false);
		tmppath.clear();
		path.clear();
	}
	return 0;
}
