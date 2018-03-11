#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int from, to, w;
	bool operator<(const node &x){return w < x.w;}
};
int find(vector<int> &a, int i) {
	if (a[i] < 0)return i;
	return a[i] = find(a, a[i]);
}
int unite(vector<int>& a, int root1, int root2){
	if (root1 > root2) swap(root1, root2);
	a[root1] += a[root2];
	a[root2] = root1;
	return root1;
}
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	double c;
	cin >> n >> m >> c;
	vector<node> e(m);
	vector<int> a(n, -1);
	vector<double> H(n, c);
	for (int i = 0; i < m; ++i)cin >> e[i].from >> e[i].to >> e[i].w;
	sort(e.begin(), e.end());
	for (int i = 0; i < m; ++i) {
		int r1 = find(a, e[i].from), r2 = find(a, e[i].to);
		if (r1 != r2 && e[i].w <= H[r1] && e[i].w <= H[r2]) {
			double newH = max(H[r1] + c / a[r1], H[r2] + c / a[r2]);
			newH = max(newH, (double)e[i].w);
			int newRoot = unite(a, r1, r2);
			newH -= c / a[newRoot];
			H[newRoot] = newH;
		}
	}
	vector<vector<int>> components(n);
	for (int i = 0; i < n; i++) components[find(a, i)].push_back(i);
	for (int i = 0; i < n; i++) 
		if (components[i].size()) {
			cout << components[i][0];
			for (int j = 1; j < (int)components[i].size(); j++) cout<<" "<<components[i][j];
			cout << "\n";
		}
	return 0;
}
