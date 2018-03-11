#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
int n;
int tree[maxn][maxn];
int pre[maxn], post[maxn], in[maxn], t[maxn];
int f[maxn], rein[maxn], repost[maxn], repre[maxn];
int root, flag;
int get() {
	string str;
	cin >> str;
	if (str[0] == '-')return 0;
	return stoi(str);
}
void dfs(int root, int p) {
	if (!root) return;
	if (p == 1) {
		if (flag)cout << " ";
		cout << t[root];
		flag = true;
	}
	dfs(tree[root][0], p);
	if (p == 2) {
		if (flag)cout << " ";
		cout << t[root];
		flag = true;
	}
	dfs(tree[root][1], p);
	if (p == 3) {
		if (flag)cout << " ";
		cout << t[root];
		flag = true;
	}
}
bool dfs(int &index, int inl, int inr, int prel, int prer, int postl, int postr) {
	if (inl>inr) {
		index = 0;
		return true;
	}
	for (int i = inl; i <= inr; ++i) {
		if (in[i] && pre[prel] && pre[prel] != in[i])continue;
		if (in[i] && post[postr] && in[i] != post[postr])continue;
		if (pre[prel] && post[postr] && pre[prel] != post[postr])return false;
		int tmp = max(in[i], max(pre[prel], post[postr]));
		if (rein[tmp] && rein[tmp] != i) continue;
		if (repre[tmp] && repre[tmp] != prel) continue;
		if (repost[tmp] && repost[tmp] != postr) continue;
		if (!dfs(tree[i][0], inl, i - 1, prel + 1, prel + i - inl, postl, postl + i - inl - 1))continue;
		if (!dfs(tree[i][1], i + 1, inr, prel + i - inl + 1, prer, postl + i - inl, postr - 1))continue;
		index = i;
		t[index] = tmp;
		return true;
	}
	return false;
}
void bfs() {
	queue<int> q;
	q.push(root);
	cout << t[root];
	while (!q.empty()) {
		int tmp = q.front(); q.pop();
		if (tree[tmp][0])q.push(tree[tmp][0]), cout << " " << t[tree[tmp][0]];
		if (tree[tmp][1])q.push(tree[tmp][1]), cout << " " << t[tree[tmp][1]];
	}
}
int main() {
	ios::sync_with_stdio(false);
	int n, cnt = 0, rest;
	cin >> n;
	for (int i = 1; i <= n; ++i)in[i] = get(), f[in[i]]++, rein[in[i]] = i;
	for (int i = 1; i <= n; ++i)pre[i] = get(), f[pre[i]]++, repre[pre[i]] = i;
	for (int i = 1; i <= n; ++i)post[i] = get(), f[post[i]]++, repost[post[i]] = i;
	for (int i = 1; i <= n; ++i)if (!f[i])++cnt, rest = i;
	if (cnt>1 || !dfs(root, 1, n, 1, n, 1, n))cout << "Impossible\n";
	else {
		for (int i = 1; i <= n; ++i)if (!t[i])t[i] = rest;
		flag = 0; dfs(root, 2); cout << "\n";
		flag = 0; dfs(root, 1); cout << "\n";
		flag = 0; dfs(root, 3); cout << "\n";
		flag = 0; bfs();
	}
	return 0;
}
