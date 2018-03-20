#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
struct node {
	int l, r, mark;
	ll minn;
}tree[maxn << 2];
struct ques {
	int l, r;
	ques() {}
	ques(int ll, int rr) :l(ll), r(rr) {}
	bool operator < (const ques &qq)const {
		return r<qq.r;
	}
};
void init(int st, int l, int r) {
	tree[st].l = l;
	tree[st].r = r;
	tree[st].minn = inf;
	tree[st].mark = 0;
	if (l == r) {
		cin >> tree[st].minn;
		return;
	}
	int mid = (l + r) >> 1;
	init(st << 1, l, mid);
	init(st << 1 | 1, mid + 1, r);
	tree[st].minn = min(tree[st << 1].minn, tree[st << 1 | 1].minn);
}
void push_down(int st) {
	if (!tree[st].mark)return;
	tree[st << 1].minn += tree[st].mark;
	tree[st << 1].mark += tree[st].mark;
	tree[st << 1 | 1].minn += tree[st].mark;
	tree[st << 1 | 1].mark += tree[st].mark;
	tree[st].mark = 0;
}
ll find_min(int st, int l, int r) {
	if (tree[st].l == l && tree[st].r == r)return tree[st].minn;
	push_down(st);
	int mid = (tree[st].l + tree[st].r) >> 1;
	if (r <= mid)return find_min(st << 1, l, r);
	else if (l > mid)return find_min(st << 1 | 1, l, r);
	else return min(find_min(st << 1, l, mid), find_min(st << 1 | 1, mid + 1, r));
}
void update(int st, int l, int r, ll val) {
	if (tree[st].l == l && tree[st].r == r) { 
		tree[st].minn += val; 
		tree[st].mark += val;
		return;
	}
	push_down(st);
	int mid = (tree[st].l + tree[st].r) >> 1;
	if (r <= mid)update(st << 1, l, r, val);
	else if (l > mid)update(st << 1 | 1, l, r, val);
	else update(st << 1, l, mid, val), update(st << 1 | 1, mid + 1, r, val);
	tree[st].minn = min(tree[st << 1].minn, tree[st << 1 | 1].minn);
}
int main() {
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	init(1, 0, n - 2);//like eg: 0 to 8
	vector<ques> v;
	for (int i = 0; i<q; ++i) {
		int a, b;
		cin >> a >> b;
		if (a>b)swap(a, b);
		v.push_back(ques(a, b));
	}
	sort(v.begin(), v.end());
	ll res = 0;
	for (int i = 0; i<q; ++i) {
		ll minn = find_min(1, v[i].l, v[i].r - 1);
		if(minn)update(1, v[i].l, v[i].r - 1, -minn);
		res += minn;
	}
	cout << res;
	return 0;
}
