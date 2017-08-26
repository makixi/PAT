#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 21;
bool v[maxn][maxn];
bool vis[maxn];
int res[maxn];
int n;
bool success=false;
void dfs(int u,int cnt) {
	if (success)return;
	res[cnt] = u;
	if (cnt == n&&v[u][1]==1) {
		success = true;
		return;
	}
	if (cnt >= n)return;
	bool flag = false;
	for (int i = 1; i <= n; ++i)
		if (!vis[i] && v[i][1])
			flag = true;
	if (!flag)return;
	for (int i = 1; i <=n; ++i) 
		if (!vis[i]&&v[u][i]) {
			vis[i] = true;
			dfs(i, cnt + 1);
			vis[i] = false;
		}
}
int main() {
	fill(vis, vis + maxn, false);
	fill(v[0], v[0] + maxn*maxn, false);
	scanf("%d", &n);
	char str[maxn];
	for (int i = 1; i <= n; ++i) {
		scanf("%s", str + 1);
		for (int j = 1; j <= n; ++j) {
			if (str[j] == 'W')
				v[i][j] = true;
			if (str[j] == 'L')
				v[j][i] = true;
		}
	}
	vis[1] = true;
	dfs(1,1);
	if (!success)cout << "No Solution";
	else
		for (int i = 1; i <= n; ++i) {
			if (i != 1)printf(" ");
			printf("%d", res[i]);
		}
	return 0;
}
