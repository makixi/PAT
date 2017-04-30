#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Tree {
	int lchild, rchild;
	int val;
};
vector<Tree> tree;
vector<int> all;
int t = 0;
void inorder(int root) {
	if (tree[root].lchild == -1 && tree[root].rchild == -1) {
		tree[root].val = all[t++];
		return;
	}
	if (tree[root].lchild != -1)
		inorder(tree[root].lchild);
	tree[root].val=all[t++];
	if (tree[root].rchild != -1)
		inorder(tree[root].rchild);
}
int main() {
	int n;
	cin >> n;
	tree.resize(n);
	all.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i].lchild >> tree[i].rchild;
	}
	for (int i = 0; i < n; ++i) {
		cin >> all[i];
	}
	sort(all.begin(), all.end());
	inorder(0);
	queue<int> q;
	q.push(0);
	cout << tree[0].val;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node != 0) cout << " " << tree[node].val;
		if (tree[node].lchild!=-1) q.push(tree[node].lchild);
		if (tree[node].rchild!=-1) q.push(tree[node].rchild);
	}
	return 0;
}
