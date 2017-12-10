#include<iostream>
#include<cstring>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 10;
int zoo[maxn][maxn];//0 animal	1 cell	2 obstacles
int fin[maxn][maxn];
int qx[100], qy[100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
set<LL> s;
LL ans;
int n, m, k, h;
char buf[10];
int place2(int x, int y) {
	if (x <= 0 || y <= 0 || x>n || y>m) return -1;
	return fin[x][y];
}
bool place(LL curr, int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m) return false;
	if (!zoo[x][y]) return false;
	return (!((curr >> ((x - 1)*m + y - 1)) & 1));
}
bool check(LL curr) {
	LL tt = curr;
	int tmp = 0, x, y, H = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin[i][j] = zoo[i][j];
	while (tt) {
		x = (tmp / m) + 1; y = (tmp%m) + 1;
		if (tt & 1) fin[x][y] = 2;
		tmp++;
		tt >>= 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (fin[i][j] == 2) continue;
			bool hole = true;
			int ani = (fin[i][j] == 0);
			int t = 1, w = 1;
			qx[t] = i;
			qy[t] = j;
			fin[i][j] = 2;
			while (t <= w) {
				int xx = qx[t], yy = qy[t];
				t++;
				for (int d = 0; d<4; d++) {
					int res = place2(xx + dx[d], yy + dy[d]);
					if (res == -1) hole = false;
					else if (res == 0 || res == 1) {
						w++;
						fin[xx + dx[d]][yy + dy[d]] = 2;
						qx[w] = xx + dx[d];
						qy[w] = yy + dy[d];
					}
					if (res == 0) ani++;
					if (ani >= 2) return false;
				}
			}
			if (hole) H++;
			if (H>h) return false;
		}
	return H == h;
}
void dfs(LL curr, int num) {
	if (s.count(curr))return;
	s.insert(curr);
	if (num == 0) {
		if (check(curr))ans++;
		return;
	}
	LL t = curr;
	int tmp = 0, x, y;
	while (t) {
		if (t & 1) {
			x = (tmp / m) + 1; 
			y = (tmp%m) + 1;
			for (int i = 0; i<4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (place(curr, xx, yy))
					dfs((curr | (1LL << ((xx - 1)*m + yy - 1))), num - 1);
			}
		}
		tmp++;
		t >>= 1;//从后往前
	}
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d%d%d", &n, &m, &k, &h);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < m; ++j)zoo[i][j + 1] = ((buf[j] == '.' ? 1 : 0));
	}
	LL curr = 0;
	for(int i=n;i>=1;--i)
		for (int j = m; j >= 1; --j) {
			if (!zoo[i][j])continue;//没办法走啊
			curr = 1LL << ((i - 1)*m + (j - 1));//算个状态
			dfs(curr, k - 1);
		}
	cout << ans;
	return 0;
}
