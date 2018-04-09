#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 320;
const int inf = 0x3f3f3f3f;
struct node {
	double x, y;
}p[maxn],q[maxn],all[maxn];
int n, per[maxn], l;
double multiX(node a, node b,node c) {
	return (b.y - a.y)*(c.x - a.x) - (b.x - a.x)*(c.y - a.y);
}
int dis(node a, node b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool cmp(int u, int v) {
	int det = multiX(p[1], p[u], p[v]);
	if (det != 0)return det>0;
	return dis(p[1], p[u])<dis(p[1], p[v]);
}
void graham() {
	int id = 1;
	for(int i=2;i<=n;++i)
		if (p[i].x<p[id].x || (p[i].x == p[id].x&&p[i].y<p[id].y))id = i;
	if (id != 1)swap(p[1], p[id]);
	for (int i = 1; i <= n; i++)per[i] = i;
	sort(per + 2, per + n + 1, cmp);
	q[++l] = p[1];
	for (int i = 2; i <= n; i++) {
		int j = per[i];
		while (l >= 2 && multiX(q[l - 1], q[l],p[j]) <= 0)l--;
		q[++l] = p[j];
	}
}
double area() {
	int ans = 0;
	q[0].x = 0; q[0].y = 0;
	for (int i = 1; i <= l; i++) 
		ans += multiX(q[0], q[i], q[i%l + 1]);
	return abs(ans) / 2;
}
int main() {
	int N, m;
	cin >> N >> m;
	n = m;
	for (int i = 1; i <= N; ++i)scanf("%lf %lf", &all[i].x, &all[i].y);
	vector<int> choose(N + 1, 0);
	vector<int> resc;
	for (int i = N - m + 1; i <= N; ++i)choose[i] = 1;
	double res = -inf;
	do {
		l = 0;
		for (int i = 1, cnt = 1; i <= N; ++i) 
			if (choose[i])p[cnt++] = all[i];
		graham();
		double ans = area() / 50;
		if (ans - res > 0) {
			res = ans;
			resc = choose;
		}
	} while (next_permutation(choose.begin() + 1, choose.end()));
	bool first = true;
	if (resc.size()) 
		for (int i = N; i >= 1; --i)
			if (resc[i]) {
				if (!first)cout << " ";
				first = false;
				cout << i - 1;
			}
	return 0;
}
