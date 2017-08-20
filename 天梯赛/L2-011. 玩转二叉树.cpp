#include<iostream>
using namespace std;
const int maxn=35;
int in[maxn],pre[maxn];
int level[100001]={0};
void toMirrorLevel(int start,int end,int root,int index){
	if(end<start)return;
	int i=start;
	while(in[i]!=pre[root]&&i<end)++i;
	level[index]=pre[root];
	toMirrorLevel(start,i-1,root+1,index*2+2);
	toMirrorLevel(i+1,end,root+i+1-start,index*2+1);
}
int main(){
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>in[i];
	for(int i=1;i<=n;++i)cin>>pre[i];
	toMirrorLevel(1,n,1,0);
	for(int i=0;i<=100000;++i){
		if(level[i]){
			cnt++;
			cout<<level[i];
			if(cnt!=n)cout<<" ";
		}
	}
	return 0;
}
