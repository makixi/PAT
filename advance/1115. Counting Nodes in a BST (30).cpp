#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	node *lchild,*rchild;
	int val;
	int level;
	node(){
		lchild=rchild=NULL;
	}
};
node* build(node *root,int tmp){
	if(root==NULL){
		root=new node();
		root->val=tmp;
	}else if(root->val>=tmp)
		root->lchild=build(root->lchild,tmp);
	else
		root->rchild=build(root->rchild,tmp);
	return root;
}
int main(){
	int n,tmp;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;++i){
		cin>>tmp;
		root=build(root,tmp);
	}
	vector<int> num;
	queue<node*> q;
	node *tree;
	root->level=1;
	q.push(root);
	int level=1;
	while(!q.empty()){
		int cnt=0;
		for(tree=q.front();tree->level==level;tree=q.front()){
			if(tree->level!=level)break;
			q.pop();
			if(tree->lchild!=NULL){
				tree->lchild->level=tree->level+1;
				q.push(tree->lchild);
			}
			if(tree->rchild!=NULL){
				tree->rchild->level=tree->level+1;
				q.push(tree->rchild);
			}
			++cnt;
			if(q.empty())break;
		}
		++level;
		num.push_back(cnt);
	}
	printf("%d + %d = %d",num[num.size()-1],num[num.size()-2],num[num.size()-2]+num[num.size()-1]);
	return 0;
} 
