#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int vi = 0;
struct node {
	string name;
	int height;
};
vector<node> v;
bool cmp(node a, node b) {
	if(a.height!=b.height)
		return a.height > b.height;
	return a.name < b.name;
}
void solve(int columnNum) {
	vector<node> row(columnNum);
	int right=columnNum/2, left=right-1;
	for (; left >= 0 || right<columnNum; ) {
		row[right++] = v[vi++];
		if(left>=0)row[left--] = v[vi++];
	}
	for (int i = 0; i < row.size(); ++i) {
		if (i)cout << " ";
		cout << row[i].name;
	}
	cout << endl;
}
int main() {
	int n, k,eachrow,lastrow;
	cin >> n >> k;
	eachrow = n / k;
	lastrow = n - n / k*(k - 1);
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].name >> v[i].height;
	sort(v.begin(), v.end(), cmp);
	vector<node> last(lastrow);
	solve(lastrow);
	for (int i = 0; i < k - 1; ++i)
		solve(eachrow);
	return 0;
}
