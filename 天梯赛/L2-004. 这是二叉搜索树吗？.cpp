#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int val;
	node *lchild,*rchild;
	node(){
		lchild=rchild=NULL;
	}
};
node* buildTree(node* root,int val){
	if(root==NULL){
		root =new node();
		root->val=val;
	}else if(root->val>val){
		root->lchild=buildTree(root->lchild,val);
	}else
		root->rchild=buildTree(root->rchild,val);
	return root;
}
node* buildMirrorTree(node* root,int val){
	if(root==NULL){
		root =new node();
		root->val=val;
	}else if(root->val>val){
		root->rchild=buildMirrorTree(root->rchild,val);
	}else
		root->lchild=buildMirrorTree(root->lchild,val);
	return root;
}
void preTraverse(node *root,vector<int> &v){
	v.push_back(root->val);
	if(root->lchild!=NULL)preTraverse(root->lchild,v);
	if(root->rchild!=NULL)preTraverse(root->rchild,v);
}
void postTraverse(node *root,vector<int> &v){
	if(root->lchild!=NULL)postTraverse(root->lchild,v);
	if(root->rchild!=NULL)postTraverse(root->rchild,v);
	v.push_back(root->val);
}
int main(){
	int n,tmp;
	cin>>n;
	node *root=NULL;
	node *rootMirror=NULL;
	vector<int> origin,pre,preMirror;
	vector<int> post,postMirror;
	for(int i=0;i<n;++i){
		cin>>tmp;
		origin.push_back(tmp);
		root=buildTree(root,tmp);
		rootMirror=buildMirrorTree(rootMirror,tmp);
	}
	preTraverse(root,pre);
	preTraverse(rootMirror,preMirror);
	if(pre==origin){
		postTraverse(root,post);
		cout<<"YES"<<endl;
		for(int i=0;i<n;++i){
			if(i)cout<<" ";
			cout<<post[i];
		}
		return 0;
	}else{
		if(preMirror==origin){
			postTraverse(rootMirror,post);
			cout<<"YES"<<endl;
			for(int i=0;i<n;++i){
				if(i)cout<<" ";
				cout<<post[i];
			}
			return 0;
		}else
			cout<<"NO";
	}
	return 0;
}

//--------------------------------------------------
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre;
vector<int> post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
} 
