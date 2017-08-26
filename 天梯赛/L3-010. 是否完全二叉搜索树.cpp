#include<iostream>
#include<queue>
using namespace std;
struct node {
	int val;
	node *lchild, *rchild;
	node() {
		lchild = rchild = NULL;
	}
};
node* buildtree(node *root, int val) {
	if (root == NULL) {
		root = new node();
		root->val = val;
	}
	else if (root->val <= val) 
		root->lchild = buildtree(root->lchild, val);
	else
		root->rchild = buildtree(root->rchild, val);
	return root;
}
int main() {
	int n, tmp;
	cin >> n;
	node* root = NULL;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		root = buildtree(root, tmp);
	}
	bool flag = true;
	int cnt = 0;
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *tmp = q.front(); q.pop();
		++cnt;
		if (tmp == NULL) {
			if (cnt == n+1&&flag) {
				cout << endl << "YES";
				return 0;
			}
			else { flag = false; continue; }
		}
		if (cnt != 1)cout << " ";
		cout << tmp->val;
		q.push(tmp->lchild);
		q.push(tmp->rchild);
	}
	cout << endl<<"NO";
	return 0;
}
