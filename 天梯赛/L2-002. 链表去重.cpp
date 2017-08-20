#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100001;
const int inf=0x3f3f3f3f;
struct Node{
	int ad;
	int val;
	int nex;
}node[100001];
bool vis[maxn]={false};
int main(){
	int fad,n,tmp;
	cin>>fad>>n;
	vector<Node> v1,v2;
	for(int i=0;i<n;++i){
		scanf("%d",&tmp);
		scanf("%d %d",&node[tmp].val,&node[tmp].nex);
		node[tmp].ad=tmp;
	}
	while(fad!=-1){
		if(!vis[abs(node[fad].val)]){
			vis[abs(node[fad].val)]=true;
			v1.push_back(node[fad]);
		}else
			v2.push_back(node[fad]);
		fad=node[fad].nex;
	}
	for(int i=0;i<v1.size();++i)
		if(i!=v1.size()-1)
			printf("%05d %d %05d\n",v1[i].ad,v1[i].val,v1[i+1].ad);
		else
			printf("%05d %d -1\n",v1[i].ad,v1[i].val);
	for(int i=0;i<v2.size();++i)
		if(i!=v2.size()-1)
			printf("%05d %d %05d\n",v2[i].ad,v2[i].val,v2[i+1].ad);
		else
			printf("%05d %d -1\n",v2[i].ad,v2[i].val);
	return 0;
} 
