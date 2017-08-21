#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;
const int maxn=21;
bool vis[maxn];
int root;
struct node{
	int lchild,rchild;
	string c;
};
vector<node> v;
string inTraverse(int curr){
	if(curr==-1)return "";
	if(v[curr].rchild!=-1){
		v[curr].c=inTraverse(v[curr].lchild)+v[curr].c+inTraverse(v[curr].rchild);
		if(root!=curr)return "("+v[curr].c+")";
	}
	return v[curr].c;
}
int main(){
	int n;
	cin>>n;
	v.resize(n+1);
	for(int i=1;i<=n;++i){
		cin>>v[i].c>>v[i].lchild>>v[i].rchild;
		if(v[i].lchild!=-1)vis[v[i].lchild]=true;
		if(v[i].rchild!=-1)vis[v[i].rchild]=true;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
			root=i;
	cout<<inTraverse(root);
	return 0;
} 
