#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node {
	int val;
	int level;
	node *lchild, *rchild;
	node() {lchild = rchild = NULL;}
};
node* buildTree(node* root, int val) {
	if (root == NULL) {
		root = new node();
		root->val = val;
	}
	else if (root->val>val) root->lchild = buildTree(root->lchild, val);
	else root->rchild = buildTree(root->rchild, val);
	return root;
}
void findNode(node *root,int a, int b, node *&an, node *&bn) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *tmp = q.front(); q.pop();
		if (tmp->val == a)  an = tmp; 
		if (tmp->val == b)  bn = tmp; 
		if (an != NULL&&bn != NULL)return;
		if (tmp->lchild != NULL) q.push(tmp->lchild);
		if (tmp->rchild != NULL) q.push(tmp->rchild);
	}
}
void bfs(node *root) {
	queue<node*> q;
	root->level = 1;
	q.push(root);
	while (!q.empty()) {
		node *tmp = q.front(); q.pop();
		if (tmp->lchild != NULL) { 
			tmp->lchild->level = tmp->level + 1; 
			q.push(tmp->lchild); 
		}
		if (tmp->rchild != NULL) { 
			tmp->rchild->level = tmp->level + 1; 
			q.push(tmp->rchild); 
		}
	}
	return;
}
bool findParent(node *root, int a, int b) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *tmp = q.front(); q.pop();
		if (tmp->lchild != NULL&&tmp->rchild != NULL) {
			if (tmp->lchild->val == a&&tmp->rchild->val == b)return true;
			else if (tmp->rchild->val == a&&tmp->lchild->val == b)return true;
			if (tmp->lchild->val == a&&tmp->rchild->val != b)return false;
			else if (tmp->rchild->val != a&&tmp->lchild->val == b)return false;
			else if (tmp->lchild->val != a&&tmp->rchild->val == b)return false;
			else if (tmp->rchild->val == a&&tmp->lchild->val != b)return false;
		}
		if (tmp->lchild != NULL) q.push(tmp->lchild);
		if (tmp->rchild != NULL) q.push(tmp->rchild);
	}
	return false;
}
int main() {
	int n,tmp,q;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		root = buildTree(root, tmp);
	}
	bfs(root);
	cin >> q;
	while (q--) {
		int a, b;
		string str;
		cin >> a >> str;
		if (str == "and") {
			cin >> b >> str >> str;
			if (str == "siblings") {//"A and B are siblings"
				if (findParent(root, a, b)) printf("Yes\n");
				else printf("No\n");
			}
			else {//A and B are on the same level
				cin >> str >> str >> str;
				node *an = NULL, *bn = NULL;
				findNode(root, a, b, an, bn);
				if (an != NULL&&bn != NULL&&an->level == bn->level) printf("Yes\n");
				else printf("No\n");
			}
		}
		else {
			cin >> str >> str;
			if (str == "root") {//A is the root
				if (a == root->val) printf("Yes\n");
				else printf("No\n");
			}
			else if (str == "parent") {//A is the parent of B
				cin >> str >> b;
				node *an = NULL, *bn = NULL;
				findNode(root, a, b, an, bn);
				if ((an != NULL&&bn != NULL)&&(an->lchild == bn||an->rchild==bn)) printf("Yes\n");
				else printf("No\n");
			}
			else if (str == "left") {//A is the left child of B
				cin >> str >> str >> b;
				node *an=NULL, *bn=NULL;
				findNode(root, a, b, an, bn);
				if (bn != NULL&&an != NULL&&bn->lchild == an) printf("Yes\n");
				else printf("No\n");
			}
			else {//A is the right child of B
				cin >> str >> str >> b;
				node *an = NULL, *bn = NULL;
				findNode(root, a, b, an, bn);
				if (bn != NULL&&an != NULL&&bn->rchild == an) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
