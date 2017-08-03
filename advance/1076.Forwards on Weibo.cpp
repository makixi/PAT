#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1010;
bool vis[maxn];
int table[maxn][maxn] = {0};
int n, l;
int main() {
	int  k,a;
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> a;
			table[a][i] = 1;	//i¹Ø×¢a
		}
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int layer = 0, cnt = 0;
		fill(vis, vis + maxn, false);
		cin >> a;
		queue<int> q,p;
		q.push(a);
		vis[a] = true;
		while (!q.empty()&&layer<l) {
			while (!q.empty()&&layer<l) {
				int tmp = q.front(); q.pop();
				for (int i = 1; i <= n; ++i) {
					if (!vis[i] && table[tmp][i]) {
						vis[i] = true;
						p.push(i);
						cnt++;
					}
				}
			}
			++layer;
			swap(q, p);
		}
		cout << cnt << endl;
	}
	return 0;
}
