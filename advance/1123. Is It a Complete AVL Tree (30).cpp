#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=10005;
const int inf=0x3f3f3f3f;
int n;
struct node{
	node *lchild,*rchild;
	int val;
	node(){lchild=rchild=NULL;}
};
int getheight(node *root){
	if(root==NULL)return 0;
	return max(getheight(root->lchild),getheight(root->rchild))+1;
}
node *rotateLeft(node *root){
	node *t=root->rchild;
	root->rchild=t->lchild;
	t->lchild=root;
	return t;
}
node *rotateRight(node *root){
	node *t=root->lchild;
	root->lchild=t->rchild;
	t->rchild=root;
	return t;
}
node *rotateLeftRight(node *root){
	root->lchild=rotateLeft(root->lchild);
	return rotateRight(root);
}
node *rotateRightLeft(node *root){
	root->rchild=rotateRight(root->rchild);
	return rotateLeft(root);
}
node* insert(node *root,int val){
	if(root==NULL){
		root=new node();
		root->val=val;
	}else if(root->val>val){
		root->lchild=insert(root->lchild,val);
		if(getheight(root->lchild)-getheight(root->rchild)>=2)
			if(val<root->lchild->val)	
				root=rotateRight(root);
			else 
				root=rotateLeftRight(root);
			
	}else{
		root->rchild=insert(root->rchild,val);
		if(getheight(root->rchild)-getheight(root->lchild)>=2)
			if(val>root->rchild->val)	
				root=rotateLeft(root);
			else 
				root=rotateRightLeft(root);
	}
	return root;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;++i){
		int val;
		cin>>val;
		root=insert(root,val);
	}
	queue<node *> q;
	bool flag=true;
	int cnt=1;
	q.push(root);
	cout<<root->val;
	while(!q.empty()){
		node* u=q.front();q.pop();
		if(u->val!=root->val)cout<<" "<<u->val;
		if(u->lchild!=NULL){
			q.push(u->lchild);
			cnt++;
		}else if(cnt<n)flag=false;
		if(u->rchild!=NULL){
			q.push(u->rchild);
			++cnt;
		}else if(cnt<n)flag=false;
	}
	if(!flag)cout<<endl<<"NO";
	else cout<<endl<<"YES";
	return 0;
}
