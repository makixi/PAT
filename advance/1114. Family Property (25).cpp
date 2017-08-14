#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int father[maxn];
bool vis[maxn];
struct person {
	int id;
	int fid;
	int mid;
	vector<int> kid;
	int num;
	int area;
}p[1010];
struct family {
	int id;
	double num=0;
	double area=0;
	int people=0;
	bool flag = false;
}f[maxn];
int findfather(int i) {
	while (i != father[i])i = father[i];
	return i;
}
void unite(int a, int b) {
	int x = findfather(a);
	int y = findfather(b);
	if (x < y)
		father[y] = x;
	else if (x > y)
		father[x] = y;
}
bool cmp(family a, family b) {
	if (a.area != b.area)
		return a.area > b.area;
	return a.id < b.id;
}
int main() {
	int n, k, cnt = 0;
	cin >> n;
	for (int i = 0; i < maxn; ++i)
		father[i] = i;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].id >> p[i].fid >> p[i].mid >> k;
		vis[p[i].id] = true;
		if (p[i].fid != -1) {
			vis[p[i].fid] = true;
			unite(p[i].id, p[i].fid);
		}
		if (p[i].mid != -1) {
			vis[p[i].mid] = true;
			unite(p[i].id, p[i].mid);
		}
		p[i].kid.resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> p[i].kid[j];
			vis[p[i].kid[j]] = true;
			unite(p[i].kid[j], p[i].id);
		}
		cin >> p[i].num >> p[i].area;
	}
	for (int i = 0; i < n; ++i) {
		int id = findfather(p[i].id);
		f[id].id = id;
		f[id].num += p[i].num;
		f[id].area += p[i].area;
		f[id].flag = true;
	}
	for (int i = 0; i < maxn; ++i) 
		if (vis[i])
			f[findfather(i)].people++;
	for (int i = 0; i < maxn; ++i) 
		if (f[i].flag) {
			f[i].num /= f[i].people;
			f[i].area /= f[i].people;
			cnt++;
		}
	sort(f, f + maxn, cmp);
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i)
		printf("%04d %d %.3lf %.3lf\n", f[i].id, f[i].people, f[i].num, f[i].area);
	return 0;
}
