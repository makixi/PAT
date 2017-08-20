#include<iostream>
#include<vector>
#include<queue>
using namespace  std;
const int maxn=35;
vector<int> res[maxn];
int tree[maxn][2];
int in[maxn],post[maxn],root;
struct node{
	int val;
	int depth;
};
void tolevel(int &root,int il,int ir,int pl,int pr){
	if(il>ir)return;
	root=pr;
	int i;
	for(i=il;in[i]!=post[pr];++i);
	tolevel(tree[root][0],il,i-1,pl,pl+i-il-1);
	tolevel(tree[root][1],i+1,ir,pl+i-il,pr-1);
}
void bfs(){
	queue<node> q;
	q.push(node{root,0});
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		res[tmp.depth].push_back(post[tmp.val]);
		if(tree[tmp.val][0])
			q.push(node{tree[tmp.val][0],tmp.depth+1});
		if(tree[tmp.val][1])
			q.push(node{tree[tmp.val][1],tmp.depth+1});
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>post[i];
	for(int i=1;i<=n;++i)cin>>in[i];
	tolevel(root,1,n,1,n);
	bfs();
	cout<<res[0][0];
	for(int i=1;i<maxn;++i)
		for(int j=0;j<res[i].size();++j)
			cout<<" "<<res[i][j];
	return 0;
}
