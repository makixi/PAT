#include<iostream>
#include<map>
#include<string>
using namespace std;
int n;		//number of phone calls
int k;		//the weight threthold
int index=0;
int allweight,nodenum,mark;
map<string,int> cti;
map<int,string> itc;
map<string,int> res;
const int maxnum=2010;
int table[maxnum][maxnum]={0};
int nodeweight[maxnum]={0};
bool vis[maxnum]={false};
//int membernum[maxnum]={0};
int StringtoInt(string s){
	if(cti[s]==0){
		index+=1;
		cti[s]=index;
		itc[index]=s;
	}
	return cti[s];
}
void dfs(int node,int &head){
	vis[node]=true;
	nodenum++;
	if(nodeweight[node]>nodeweight[head])
		head=node;
	for(int i=1;i<=n;++i){
		if(table[node][i]>0)
			{
			allweight+=table[node][i];
			table[node][i]=table[i][node]=0;	//·ÀÖ¹¶à´Î¼ÆËã
			if(!vis[i])
				dfs(i,head);
			}
	}
}
int main(){
	string name1,name2;
	int weight;
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>name1>>name2>>weight;
		int id1=StringtoInt(name1);
		int id2=StringtoInt(name2);
		table[id1][id2]+=weight;table[id2][id1]+=weight;
		nodeweight[id1]+=weight;nodeweight[id2]+=weight;
	}
	//int cnt=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			allweight=0,nodenum=0,mark=i;
			dfs(i,mark);
			if(allweight>k&&nodenum>2)
				{
					res[itc[mark]]=nodenum;
					//cnt++;
					//membernum[mark]=nodenum;
				}
		}
	}
	//cout<<cnt<<endl;
	cout<<res.size()<<endl;
	for(map<string,int>::iterator it=res.begin();it!=res.end();++it)
		cout<<it->first<<" "<<it->second<<endl;
	//for(int i=1;i<=n;++i)
	//	if(membernum[i]!=0)
	//		cout<<itc[i]<<" "<<membernum[i]<<endl;
	return 0;
}
