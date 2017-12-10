#include <iostream>
#include <algorithm>
using namespace std;
vector<int> post,pre,in;
void findpost(int root,int l,int r) {
	if(l>r)return;
	int i=l;
	while (i <= r&&in[i] != pre[root])++i;
	findpost(root + 1, l, i - 1);
	findpost(root + 1 + i - l, i + 1, r);
	post.push_back(pre[root]);
}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	in.resize(n);
	for(int i=0;i<n;++i)scanf("%d",&pre[i]);
	for(int i=0;i<n;++i)scanf("%d",&in[i]);
	findpost(0,0,n-1);
	cout<<post[0];
	return 0;
} 
