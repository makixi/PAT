#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int index;
	int rank;
	int Originindex;
	int weight;
};
vector<node> w;
bool cmp(node a,node b){
	return a.Originindex<b.Originindex;
}
int main(){
	int n,g,tmp;
	cin>>n>>g;
	vector<int> v(n);
	w.resize(n);
	for(int i=0;i<n;++i)cin>>v[i];
	for(int i=0;i<n;++i){
		cin>>tmp;
		w[i].Originindex=tmp;
		w[i].weight=v[tmp];
		w[i].index=i;
	}
	queue<node> q;
	for(int i=0;i<n;++i)q.push(w[i]);
	while(!q.empty()){
		int size=q.size();
		if(size==1){
			node temp=q.front();
			q.pop();
			w[temp.index].rank=1;
			break;
		}
		node maxnode;
		int group=size/g;
		if(size%g)group+=1;
		int maxn=0,cnt=0;
		for(int i=0;i<size;++i){
			node temp=q.front();q.pop();
			w[temp.index].rank=group+1;
			cnt++;
			if(temp.weight>maxn){
				maxn=temp.weight;
				maxnode=temp;
			}
			if(i==size-1||cnt==g){
				cnt=0;
				maxn=0;
				q.push(maxnode);
			}
		}
	}
	sort(w.begin(),w.end(),cmp);
	for(int i=0;i<n;++i){
		if(i)cout<<" ";
		cout<<w[i].rank;
	}
	return 0;
}
