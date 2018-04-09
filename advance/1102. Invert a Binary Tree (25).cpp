#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=11;
const int inf=0x3f3f3f3f;
bool exist[maxn]; 
int child[maxn][2];
bool first;
int n;
void inorder(int u){
	if(child[u][0]!=-1)inorder(child[u][0]);
	if(!first)cout<<" ";
	first=false;
	cout<<u;
	if(child[u][1]!=-1)inorder(child[u][1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i){
		string a,b;
		cin>>a>>b;
		int aa,bb;
		if(a=="-")aa=-1;
		else aa=stoi(a);
		if(b=="-")bb=-1;
		else bb=stoi(b);
		child[i][0]=bb;
		child[i][1]=aa;
		if(aa!=-1)exist[aa]=1;
		if(bb!=-1)exist[bb]=1;
	}
	int root;
	for(int i=0;i<n;++i)
		if(!exist[i]){
			root=i;
			break;
		}
	queue<int> q;
	q.push(root);
	first=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(!first)cout<<" ";
		first=false;
		cout<<u;
		if(child[u][0]!=-1)q.push(child[u][0]);
		if(child[u][1]!=-1)q.push(child[u][1]);
	}
	cout<<"\n";
	first=true;
	inorder(root);
	return 0;
}
