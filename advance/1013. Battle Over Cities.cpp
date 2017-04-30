#include<iostream>
using namespace std;
#define MAX 1000
int n, m, k;//number of city,remaining highways,cities to be checked
int weight[MAX][MAX];
int visit[MAX];

void dfs(int v) {
	visit[v] = 1;
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == 0 && weight[i][v] == 1)
			dfs(i);
	}
}

int main() {
	cin >> n >> m >> k;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		weight[a][b] = weight[b][a] = 1;
	}
	int c;
	while (k--) {
		int count = 0;
		cin >> c;
		memset(visit, 0, sizeof(visit));
		visit[c] = 1;
		for (int i = 1; i <= n; ++i) {
			if (visit[i] == 0) {
				dfs(i);
				count++;
			}
		}
		cout << count - 1 << endl;
	}
}
