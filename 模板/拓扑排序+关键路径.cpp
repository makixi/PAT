#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
int n, m;
int earliestTime[maxn], latestTime[maxn], idx;
int A[maxn][maxn], D[maxn][maxn], ect;
int getMax(int arr[]) {
	int res = 0;
	for (int i = 0; i < n; i++)
		if (res < arr[i]) {
			res = arr[i];
			idx = i;
		}
	return res;
}
int topsort_earliest() {
	int indegree[maxn] = { 0 };
	int cnt = 0;
	queue<int> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (A[i][j] != inf)indegree[j]++;
	for (int i = 0; i < n; i++)
		if (!indegree[i])q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		cnt++;
		for(int j=0;j<n;++j)
			if (A[u][j] != inf) {
				earliestTime[j] = max(earliestTime[u] + A[u][j], earliestTime[j]);
				if (!(--indegree[j])) q.push(j);
			}
	}
	ect = getMax(earliestTime); //最早完成时间应是所有元素中最大的
	if (cnt != n) return 0;	//如果没有取出所有元素，说明图中有回路
	else return 1;
}
void topsort_latest() {
	int outdegree[maxn] = { 0 };
	queue<int> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (A[i][j] != inf)outdegree[i]++;
	for (int i = 0; i < n; i++)
		if (!outdegree[i])q.push(i);
	//初始化LatestTime
	for (int i = 0; i < n; i++)latestTime[i] = inf;
	latestTime[idx] = ect;	//将最后一个活动的最晚完成时间设为它的最早完成时间
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = 0; j < n; j++)
			if (A[j][u] != inf) {  //<j, V>有有向边
				if (latestTime[u] - A[j][u] <= latestTime[j]) {  //必须用<=,只<的话只能算一条关键路径，<=才能算出所有的关键路径(错误原因)
					latestTime[j] = latestTime[u] - A[j][u];
					D[j][u] = latestTime[j] - earliestTime[j];
				}
				if (!(--outdegree[j]))q.push(j);
			}
	}
}
void PrintKeyRoute() {
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j >= 0; j--)	//根据题目要求，i相同时要j要逆序输出
			if (!D[i][j])cout << (i + 1) << "->" << (j + 1) << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	int a, b;
	cin >> n >> m;
	memset(D, inf, sizeof(D));
	memset(A, inf, sizeof(A));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cin >> A[--a][--b];
	}
	if (!topsort_earliest())cout << 0;
	else {
		cout << ect << "\n";
		topsort_latest();
		PrintKeyRoute();
	}
	return 0;
}
