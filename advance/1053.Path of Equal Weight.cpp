#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, s;
struct node {
	int weight;
	vector<int> child;
};
vector<node> v;
vector<int> path;
bool cmp(int a,int b) {
	return v[a].weight>v[b].weight;
}
void print(int num) {
	for (int i = 0; i < num; ++i)
		cout << path[i] << " ";
	cout << path[num] << endl;
}
bool dfs(int currid,int currindex,int lefts) {
	path[currindex] = v[currid].weight;
	if (lefts < 0)return false;
	if (lefts == 0) {
		if (v[currid].child.size() != 0)
			return false;
		print(currindex);
		return true;
	}
	for (int i = 0; i < v[currid].child.size(); ++i)
		dfs(v[currid].child[i], currindex + 1, lefts - v[v[currid].child[i]].weight);
	return false;
}
int main() {
	int fa, k;
	cin >> n >> m >> s;
	v.resize(n);
	path.resize(n);
	for (int i = 0; i < n; ++i)cin >> v[i].weight;
	for (int i = 0; i < m; ++i) {
		cin >> fa >> k;
		v[fa].child.resize(k);
		for (int j = 0; j < k; ++j)
			cin >> v[fa].child[j];
		sort(v[fa].child.begin(), v[fa].child.end(), cmp);
	}
	dfs(0,0,s-v[0].weight);
	return 0;
}
