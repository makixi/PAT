#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
struct node {
	int left, right;
};
vector<node> tree;
int main() {
	int root=0;
	cin >> n;
	tree.resize(n);
	vector<bool> isRoot(n, true);
	char a[3],b[3];
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a[0] != '-') { 
			tree[i].left = a[0] - '0'; 
			if (strlen(a) == 2)
				tree[i].left = tree[i].left * 10 + (a[1] - '0');
			isRoot[tree[i].left] =false; 
		}
		else tree[i].left = -1;
		if (b[0] != '-') { 
			tree[i].right = b[0] - '0';
			if (strlen(b) == 2)
				tree[i].right = tree[i].right * 10 + (b[1] - '0');
			isRoot[tree[i].right] = false; 
		}
		else tree[i].right = -1;
	}
	for (int i= 0; i < n; ++i) 
		if (isRoot[i]) { root = i; break; }
	queue<int> q;
	int tmp,last=0,cnt=0;
	q.push(root);
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		if (tmp != -1) { last = tmp; ++cnt; }
		else {
			if (cnt != n)printf("NO %d", root);
			else printf("YES %d", last);
			break;
		}
		q.push(tree[tmp].left);
		q.push(tree[tmp].right);
	}
	return 0;
}
