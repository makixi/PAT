#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m, k;
	int num;
	cin >> n;
	vector<set<int>> v(n+1);
	for (int i = 1; i <= n; ++i) {
		set<int> s;
		cin >> m;
		while (m--) {
			cin >> num; 
			s.insert(num);
		}
		v[i] = s;
	}
	cin >> k;
	int q1, q2;
	while (k--) {
		cin >> q1 >> q2;
		int nc = 0, nt = v[q2].size();
		for (auto it = v[q1].begin(); it != v[q1].end(); ++it) 
			if (v[q2].find(*it) == v[q2].end()) nt++;
			else nc++;
		printf("%.1f%%\n",(double)nc/nt*100);
	}
	return 0;
}
