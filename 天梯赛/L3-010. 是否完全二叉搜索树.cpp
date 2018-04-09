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
	else root->rchild = buildtree(root->rchild, val);
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
//---------------------------------------------
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=101;
int n;
int tree[maxn];
void bst(int u,int val){
	if(tree[u]==0)tree[u]=val;
	else if(val>tree[u])bst(u<<1,val);
	else bst(u<<1|1,val);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i){
		int val;
		cin>>val;
		bst(1,val);
	}
	bool first=true,flag=true;
	int cnt=0;
	for(int i=1;cnt<n;++i){
		if(tree[i]==0)flag=false;
		else{
			if(!first)cout<<" ";
			first=false;
			cout<<tree[i];
			++cnt;
		}
	}
	cout<<endl;
	if(flag)cout<<"YES";
	else cout<<"NO";
	return 0;
}
