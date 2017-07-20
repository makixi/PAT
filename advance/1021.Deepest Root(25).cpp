#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int n;
int maxhei = 0;
const int MAXNUM = 10000;
vector<vector<int>> vec;
vector<int> tmp;
bool vis[MAXNUM + 10] = {false};
set<int> s;

void dfs(int node, int hei) {
	if (hei > maxhei) {
		tmp.clear();
		tmp.push_back(node);
		maxhei = hei;
	}
	else if (hei == maxhei)
		tmp.push_back(node);
	vis[node] = true;
	for (int i = 0; i < vec[node].size(); ++i)
		if (!vis[vec[node][i]])
			dfs(vec[node][i], hei + 1);
}

int main() {
	int cnt = 0, s1 = 0;
	int tmp1, tmp2;
	cin >> n;
	vec.resize(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> tmp1 >> tmp2;
		vec[tmp1].push_back(tmp2); vec[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i, 1);
			if (i == 1) 
				for (int j = 0; j < tmp.size(); ++j) {
					s.insert(tmp[j]);
					if (j == 0)s1 = tmp[j];
				}
			cnt++;
		}
	}
	if (cnt >= 2)
		cout << "Error: " << cnt << " components";
	else {
		tmp.clear();
		maxhei = 0;
		fill(vis, vis + MAXNUM + 10, false);
		dfs(s1, 1);
		for (int i = 0; i < tmp.size(); ++i)
			s.insert(tmp[i]);
		for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
			cout << *it << endl;
	}
	return 0;
}
