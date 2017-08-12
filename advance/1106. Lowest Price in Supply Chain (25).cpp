#include<iostream>
#include<vector>
#include<cmath> 
#include<map>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
double p, r;
double minprice=inf;
struct node {
	vector<int> child;
};
vector<node> v;
map<double, int> m;
void dfs(int curr,int depth) {
	if (!v[curr].child.size()) {
		double price = p*pow(1 + r, depth);
		m[price]++;
		minprice = min(minprice, price);
		return;
	}
	for (int i = 0; i < v[curr].child.size(); ++i) 
		dfs(v[curr].child[i], depth + 1);
}
int main() {
	int tmp;
	cin >> n >> p >> r;
	r /= 100;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		v[i].child.resize(tmp);
		for (int j = 0; j < tmp; ++j)
			cin >> v[i].child[j];
	}
	dfs(0, 0);
	printf("%.4lf %d", minprice, m[minprice]);
	return 0;
}
