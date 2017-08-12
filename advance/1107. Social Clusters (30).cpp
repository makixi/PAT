#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int hobby[maxn];
vector<int> father,root;
bool cmp(int a, int b) {
	return a > b;
}
int findfather(int x) {
	int tmp = x;
	while (x != father[x])
		x = father[x];
	return x;
}
void unite(int a, int b) {
	int x = findfather(a), y = findfather(b);
	if (x != y)father[y] = x;
}
int main() {
	int n, tmp, a, cnt = 0;
	cin >> n;
	father.resize(n + 1);
	root.resize(n + 1,0);
	for (int i = 1; i <= n; ++i)father[i] = i;
	for (int i = 1; i <= n; ++i) {
		scanf("%d:", &tmp);
		for (int j = 0; j < tmp; ++j) {
			cin >> a;
			if (!hobby[a])hobby[a] = i;
			unite(findfather(hobby[a]), i);
		}
	}
	for (int i = 1; i <= n; ++i)
		root[findfather(i)]++;
	for (int i = 1; i <= n; ++i)
		if (root[i])cnt++;
	cout << cnt << endl;
	sort(root.begin(), root.end(), cmp);
	for (int i = 0; i < cnt; ++i) {
		if (i)cout << " ";
		cout << root[i];
	}
	return 0;
}
