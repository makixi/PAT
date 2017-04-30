#include<iostream>
using namespace std;

struct tree {
	struct tree *lchild, *rchild;
	int val;
};
int height(tree *root) {
	if (root == NULL) return 0;
	return height(root->lchild) > height(root->rchild) ? height(root->lchild) + 1 : height(root->rchild) + 1;
}
tree *rotateLeft(tree *root) {
	tree *t = root->rchild;
	root->rchild = t->lchild;
	t->lchild = root;
	return t;
}
tree *rotateRight(tree *root) {
	tree *t = root->lchild;
	root->lchild = t->rchild;
	t->rchild = root;
	return t;
}
tree *rotateLeftRight(tree *root) {
	root->lchild = rotateLeft(root->lchild);
	return rotateRight(root);
}
tree *rotateRightLeft(tree *root) {
	root->rchild = rotateRight(root->rchild);
	return rotateLeft(root);
}
tree *insert(tree *root, int val) {
	if (root == NULL) {
		root = new tree();
		root->val = val;
		root->lchild = root->rchild = NULL;
	}
	else if (val < root->val) {
		root->lchild = insert(root->lchild, val);
		if (height(root->lchild) - height(root->rchild) == 2)
			root = val < root->lchild->val ? rotateRight(root) : rotateLeftRight(root);
	}
	else {
		root->rchild = insert(root->rchild, val);
		if (height(root->lchild) - height(root->rchild) == -2)
			root = val > root->rchild->val ? rotateLeft(root) : rotateRightLeft(root);
	}
	return root;
}
int main() {
	int n,value;
	tree *root = NULL;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> value;
		root = insert(root,value);
	}
	cout << root->val;
	return 0;
}
