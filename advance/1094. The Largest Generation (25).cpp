//---------------------------------------------dfs----------------------------------- 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
int n;//family members
int m;//have children;
vector<int> v[MAX];
int num[MAX];
int large = 0;

void dfs(int index, int level) {
	num[level]++;
	for (int i = 0; i < v[index].size(); ++i) {
		dfs(v[index][i], level + 1);
	}
}

int main() {
	int k,child,par;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> par >> k;
		for (int j = 0; j < k; ++j) {
			cin >> child;
			v[par].push_back(child);
		}
	}
	dfs(1, 1);
	int lp = 0, lg = 0;
	for (int i = 0; i < MAX; ++i) {
		if (num[i] > lp) {
			lp = num[i];
			lg = i;
		}
	}
	cout << lp << " " << lg << endl;
	return 0;
}


//---------------------------------------------------bfs-----------------------------------------
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100
int n;//family members
int m;//have children;
vector<int> v[MAX];
int num[MAX];
int large = 0;

int main() {
	int k,child,par;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> par >> k;
		for (int j = 0; j < k; ++j) {
			cin >> child;
			v[par].push_back(child);
		}
	}
	int a,nowlevel=0,maxlevel=0,maxnum=0;
	queue<int> q,next;
	q.push(1);
	while (!q.empty()) {
		int num = 0;
		nowlevel++;
		while (!q.empty()) {
			a = q.front(); q.pop();
			for (int i = 0; i < v[a].size(); ++i)
				next.push(v[a][i]);
			num++;
		}
		if (num > maxnum) { maxnum = num; maxlevel = nowlevel; }
		swap(next, q);
	}
	cout << maxnum << " " << maxlevel << endl;
	return 0;
}
