#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define RED 1
#define BLACK 0
int res=0;//0 is yes    1 is no
int num;
struct node{
	int val;
	int color;//1 is red  0 is black
	node *lchild,*rchild;
	node(){
		lchild=rchild=NULL;
	}
};
void path(int pre,node *root,int cnt){
	if(res)return;
	if(root==NULL){
		if(num==-1)num=cnt;
		if(num!=cnt)res=1;
		return;
	}
	if(pre==RED&&root->color==RED){
		res=1;return;
	}
	if(root->color==BLACK){
		path(root->color,root->lchild,cnt+1);
		path(root->color,root->rchild,cnt+1);
	}else{
		path(root->color,root->lchild,cnt);
		path(root->color,root->rchild,cnt);
	}
}
node *insert(node *root,int val){
	if(root==NULL){
		root=new node();
		root->val=abs(val);
		if(val<0)root->color=RED;
		else if(val>0)root->color=BLACK;
		else root->color=-1;
	}else if(root->val>abs(val))
		root->lchild=insert(root->lchild,val);
	else root->rchild=insert(root->rchild,val);
	return root;
}
int main(){
	int k;cin>>k;
	while(k--){
		res=0;
		int n;cin>>n;
		node *root=NULL;
		for(int i=0;i<n;++i){
			int tmp;
			cin>>tmp;
			root=insert(root,tmp);
		}
		if(root->color==RED)res=1;
		if(!res){
			num=-1;
			path(-1,root,0);
		}
		if(res)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
