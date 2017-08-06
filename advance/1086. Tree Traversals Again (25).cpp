//给出前序中序，求后序 
#include<iostream>
#include<stack>
#include<vector> 
#include<algorithm>
using namespace std;
vector<int> pre,post,in;
void print(vector<int> v){
	for(int i=0;i<v.size();++i){
		if(i)cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
}
void topost(int root,int left,int right){
	if(right<left)return;
	int i;
	//找到中序中root的index 
	for(i=left;i<right&&in[i]!=pre[root];++i);
	topost(root+1,left,i-1);
	topost(root+1+i-left,i+1,right);
	post.push_back(pre[root]);
}
int main(){
	int n,tmp;
	string str;
	stack<int> s;
	cin>>n;
	for(int i=0;i<2*n;++i){
		cin>>str;
		if(str[1]=='u'){	//前序 
			cin>>tmp;
			s.push(tmp);
			pre.push_back(tmp);
		}else if(str[1]=='o'){	//中序 
			in.push_back(s.top());
			s.pop();
		}
	} 
	topost(0,0,n-1);
	print(post);
	return 0;
}
