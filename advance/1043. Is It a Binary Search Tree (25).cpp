#include<iostream>
#include<vector>
bool isMirror;
using namespace std;
struct tree{
	int val;
	struct tree *lchild,*rchild;
	tree(){
		lchild=rchild=NULL;
	}
};
void insertTree(tree *&root,int val){
	if(root==NULL){
		root=new tree;
		root->val=val;
		return;
	}
	if(val<root->val)
		insertTree(root->lchild,val);
	else
		insertTree(root->rchild,val);
}
void insertMirror(tree *&root,int val){
	if(root==NULL){
		root=new tree;
		root->val=val;
		return;
	}
	if(val<root->val)
		insertMirror(root->rchild,val);
	else
		insertMirror(root->lchild,val);
}
void preTranverse(tree *root,vector<int> &v){
	v.push_back(root->val);
	if(root->lchild!=NULL)preTranverse(root->lchild,v);
	if(root->rchild!=NULL)preTranverse(root->rchild,v);
}
void postTranverse(tree *root,vector<int> &v){
	if(root->lchild!=NULL)postTranverse(root->lchild,v);
	if(root->rchild!=NULL)postTranverse(root->rchild,v);
	v.push_back(root->val);
}
int main() {
	int n,tmp;
	vector<int> origin,v2,v3;
	cin>>n;
	tree *root=new tree();
	tree *rootMirror=new tree();
	root=NULL;rootMirror=NULL;
	for(int i=0;i<n;++i){
		cin>>tmp;origin.push_back(tmp);
		insertTree(root,tmp);
		insertMirror(rootMirror,tmp);
	}
	preTranverse(root,v2);
	preTranverse(rootMirror,v3);
	if(v2!=origin&&v3!=origin)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		if(v2==origin){
			origin.clear();
			postTranverse(root,origin);
			for(int i=0;i<n;++i){
				cout<<origin[i];
				if(i!=n-1)cout<<" ";
			}
		}else if(v3==origin){
			origin.clear();
			postTranverse(rootMirror,origin);
			for(int i=0;i<n;++i){
				cout<<origin[i];
				if(i!=n-1)cout<<" ";
			}
		}
	}
	return 0;
}
