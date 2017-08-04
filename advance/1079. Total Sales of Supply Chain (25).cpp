#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	vector<int> child;
	double val;
};
vector<node> v;
double sum = 0.0,p,r;
void dfs(int index,int dep) {
	if (!v[index].child.size()) {
		sum += v[index].val*pow(1 + r, dep);
		return;
	}
	for (int i = 0; i < v[index].child.size(); ++i)
		dfs(v[index].child[i], dep + 1);
}
int main() {
	int n,k;
	cin >> n >> p >> r;
	v.resize(n);
	r /= 100;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		v[i].child.resize(k);
		if (k == 0)
			cin >> v[i].val;
		else
			for (int j = 0; j < k; ++j)
				cin >> v[i].child[j];
	}
	dfs(0, 0);
	printf("%.1f", sum*p);
	return 0;
}
