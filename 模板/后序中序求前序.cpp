//前中-》后 
int pre[maxn], in[maxn];
vector<int> post;
void findpost(int root,int l,int r) {
	int i=l;
	while (i <= r&&in[i] != pre[root])++i;
	findpost(root + 1, l, i - 1);
	findpost(root + 1 + i - l, i + 1, r);
	post.push_back(pre[root]);
}

//中后=》前
int post[maxn], in[maxn];
vector<int> pre;
void findpre(int root,int l,int r) {
	int i=l;
	while (i <= r&&in[i] != post[root])++i;
	pre.push_back(post[root]);
	findpre(root - 1 + i - r, l, i - 1);
	findpre(root - 1, i + 1, r);
} 
