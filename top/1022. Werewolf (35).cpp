#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define UNKNOW 0
#define ZHEN 1
#define JIA 2
const int maxn=105;
const int inf=0x3f3f3f3f;
int judge[maxn],hua[maxn];
int Stoi(string s){
	s.erase(0,1);
	int res=0;
	for(int i=0;i<s.length();++i)res=res*10+s[i]-'0';
	return res;
}
vector<int> v;
void update(vector<int> &tmp){
	if(v.empty()){
		v=tmp;
		return;
	}
	for(int i=0;i<v.size();++i)
		if(tmp[i]>v[i]){
			v=tmp;
			return;
		}
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,l;
	cin>>n>>m>>l;
	vector<string> state(n);
	for(int i=0;i<n;++i)cin>>state[i];
	for(int i=n-m;i<n;++i)judge[i]=1;
	bool solution=false;
	do{
		memset(hua,UNKNOW,sizeof(hua));
		bool flag=true;
		for(int i=0;i<n;++i){
			int wolf=(state[i][0]=='-')?1:0;
			int id=Stoi(state[i])-1;
			if(judge[id]==wolf){
				if(hua[i]==JIA){
					flag=false;
					break;
				}
				hua[i]=ZHEN;
			}else{
				if(hua[i]==ZHEN){
					flag=false;
					break;
				}
				hua[i]=JIA;
			}
		}
		if(!flag)continue;
		int cntwolf=0,cntlie=0,cntun=0,cntliewolf=0;
		for(int i=0;i<n;++i){
			if(hua[i]==JIA)++cntlie;
			if(hua[i]==UNKNOW)++cntun;
			if(judge[i]==1){
				++cntwolf;
				if(hua[i]==JIA)++cntliewolf;
			}
		}
		if(cntlie>l||cntliewolf==0||cntliewolf==m||!(cntlie+cntun>=l&&cntlie<=l))continue;
		solution=true;
		vector<int> tmp;
		for(int i=n-1;i>=0;--i)
			if(judge[i]==1)tmp.push_back(i+1);
		update(tmp);
	}while(next_permutation(judge,judge+n));
	if(!solution){
		cout<<"No Solution";
		return 0;
	}
	for(int i=0;i<v.size();++i){
		if(i)cout<<" ";
		cout<<v[i];
	}
	return 0;
}
