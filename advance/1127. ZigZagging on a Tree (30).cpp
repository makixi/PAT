#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<int> in,post,res[35];
int root;
int tree[35][2];
struct node{
	int val;
	int depth;
};
void buildtree(int &cur,int inb,int ine,int postb,int poste){
	if(inb>ine)return;
	cur=poste;
	int i=0;
	while(in[i]!=post[poste])++i;
	buildtree(tree[cur][0],inb,i-1,postb,postb+i-inb-1);
	buildtree(tree[cur][1],i+1,ine,postb+i-inb,poste-1);
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
	post.resize(n+1);
	in.resize(n+1);
	for(int i=1;i<=n;++i)cin>>in[i];
	for(int i=1;i<=n;++i)cin>>post[i];
	buildtree(root,1,n,1,n);
	bfs();
	cout<<res[0][0];
	for(int i=1;i<35;++i)
		if(i&1)
			for(int j=0;j<res[i].size();++j)
				cout<<" "<<res[i][j];
		else
			for(int j=res[i].size()-1;j>=0;--j)
				cout<<" "<<res[i][j];
	return 0;
}
