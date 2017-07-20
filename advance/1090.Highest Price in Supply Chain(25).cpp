//-------------------------------------------DFS--------------------------
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;//supply chain
double p; //price
double r;//rate
int root, level = 0, leaf = 0;
vector<vector<int>> v;
void dfs(int root, int index) {
	if (v[root].size() == 0) {
		if (index == level)leaf++;
		if (index > level) {
			level = index;
			leaf = 1;
		}
		return;
	}
	for (int i = 0; i < v[root].size(); ++i) {
		dfs(v[root][i], index + 1);
	}
}
int main() {
	cin >> n >> p >> r;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		if (temp == -1) root = i;
		else v[temp].push_back(i);
	}
	dfs(root, 0);
	printf("%.2f %d", p*pow(1 + r / 100, level), leaf);
	return 0;
}
//------------------------------------BFS---------------------------
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n;//supply chain
double p; //price
double r;//rate
int root;
int main() {
	cin >> n >> p >> r;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		if (temp == -1) root = i;
		else v[temp].push_back(i);
	}
	queue<int> q,next;
	q.push(root);
	int len,a;
	int index=0,level=0;//当前层结点数 和 当前层数
	while (!q.empty()) {
		level++;
		index = q.size();
		while (!q.empty()) {
			a = q.front(); q.pop();
			for (int i = 0; i < v[a].size(); ++i)
				next.push(v[a][i]);
		}
		swap(q, next);
	}
	printf("%.2f %d", p*pow(1 + r / 100, level - 1), index);
	return 0;
}
