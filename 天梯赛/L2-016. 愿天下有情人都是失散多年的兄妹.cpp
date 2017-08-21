#include<iostream>
using namespace std;
struct node{
	int id;
	int fid;
	int mid;
	char sex;
};
bool res;
node v[100001];
void dfs(int a,int b,int cnt){
	if(cnt>=5)return;
	if(!a||!b)return;
	if(a==b&&a){
		res=false;
		return;
	}
	if(v[a].fid!=-1&&v[b].fid!=-1&&res){dfs(v[a].fid,v[b].fid,cnt+1);}
	if(v[a].fid!=-1&&v[b].mid!=-1&&res){dfs(v[a].fid,v[b].mid,cnt+1);}
	if(v[a].mid!=-1&&v[b].fid!=-1&&res){dfs(v[a].mid,v[b].fid,cnt+1);}
	if(v[a].mid!=-1&&v[b].mid!=-1&&res){dfs(v[a].mid,v[b].mid,cnt+1);}
}
int main(){
	int n,k,a,b,id;
	char sex;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>id;
		cin>>v[id].sex>>v[id].fid>>v[id].mid;
		v[id].id=id;
		if(v[id].fid!=-1)v[v[id].fid].sex='M';
		if(v[id].mid!=-1)v[v[id].mid].sex='F';
	}
	cin>>k;
	while(k--){
		cin>>a>>b;
		if(v[a].sex==v[b].sex)printf("Never Mind\n");
		else{
			res=true;
			dfs(a,b,0);
			if(!res)printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
