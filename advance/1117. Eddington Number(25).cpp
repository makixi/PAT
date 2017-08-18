#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
	int rank;
	int val;
};
bool cmp(node a, node b) {
	return a.val > b.val;
}
int main() {
	int n,e,tmp,i;
	cin >> n;
	vector<node> v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i].val;
	sort(v.begin(), v.end(), cmp);
	for (i = 0; i < n; ++i) 
		v[i].rank = i + 1;
	int vi = 0;
	while (vi<n&&v[vi].val>v[vi].rank)
		vi++;
	cout << vi;
	return 0;
}
