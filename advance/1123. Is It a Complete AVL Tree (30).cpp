#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int val;
	node *lchild,*rchild;
	node(){
		lchild=NULL;
		rchild=NULL;
	}
};
int height(node *root){
	if(root==NULL)return 0;
	return max(height(root->lchild),height(root->rchild))+1;
}
node *rotateRight(node *root){
	node *tmp=root->lchild;
	root->lchild=tmp->rchild;
	tmp->rchild=root;
	return tmp;
}
node *rotateLeft(node *root){
	node *tmp=root->rchild;
	root->rchild=tmp->lchild;
	tmp->lchild=root;
	return tmp;
}
node *rotateRightLeft(node *root){
	root->rchild=rotateRight(root->rchild);
	return rotateLeft(root);
}
node *rotateLeftRight(node *root){
	root->lchild=rotateLeft(root->lchild);
	return rotateRight(root);
}
node *build(node *root,int val){
	if(root==NULL){
		root=new node();
		root->val=val;
	}else if(root->val>val){
		root->lchild=build(root->lchild,val);
		if(height(root->lchild)-height(root->rchild)>=2)
			if(val<root->lchild->val)	
				root=rotateRight(root);
			else 
				root=rotateLeftRight(root);
	}else{
		root->rchild=build(root->rchild,val);
		if(height(root->rchild)-height(root->lchild)>=2)
			if(val>root->rchild->val)	
				root=rotateLeft(root);
			else 
				root=rotateRightLeft(root);
	}
	return root;
}
int main(){
	int n,val,cnt=0;
	bool flag=true;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;++i){
		cin>>val;
		root=build(root,val);
	}
	queue<node*> q;
	q.push(root);
	node *t;
	while(!q.empty()){
		t=q.front();q.pop();
		if(t==NULL)
			if(cnt==n)
				break;
			else{
				flag=false;
				continue;
			}
		else{
			if(cnt!=0)cout<<" ";
			cnt++;
			cout<<t->val;
		}
		q.push(t->lchild);
		q.push(t->rchild);
	}
	cout<<endl;
	if(flag)cout<<"YES";
	else cout<<"NO";
	return 0;
}
