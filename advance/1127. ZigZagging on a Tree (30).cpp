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
//-=--------------------------------
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=500+10;
vector<int> in,post,level(1000000,-1);
void findlevel(int l,int r,int root,int index){
	if(r<l)return;
	level[index]=post[root];
	int i=l;
	while(i<=r&&in[i]!=post[root])++i;
	findlevel(l,i-1,root-r+i-1,index*2+1);
	findlevel(i+1,r,root-1,index*2+2);
}
int main(){
    int n;
    cin>>n;
    in.resize(n);post.resize(n);
    for(int i=0;i<n;++i)cin>>in[i];
    for(int i=0;i<n;++i)cin>>post[i];
    findlevel(0,n-1,n-1,0);
    cout<<level[0];
    for(int i=1,dep=1;i<1000000;++dep){
    	if(dep%2){
    		for(int j=i;j<=i*2&&j<1000000;++j)
    			if(level[j]!=-1)cout<<" "<<level[j];
		}else{
			for(int j=min(999999,i*2);j>=i;--j)
				if(level[j]!=-1)cout<<" "<<level[j];
		}
		i=i*2+1;
	}
    return 0;
} 
