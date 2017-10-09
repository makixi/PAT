#include<iostream>
#include<map>
using namespace std;
bool judge(int num){
	if(num<=1)return false;
	for(int i=2;i*i<=num;++i)
		if(num%i==0)return false;
	return true;
}
int main(){
	int n;
	cin>>n;
	map<int,int> IdtoRank;
	map<int,bool> mark;
	for(int i=1;i<=n;++i){
		int id;cin>>id;
		IdtoRank[id]=i;
	}
	int k;
	cin>>k;
	while(k--){
		int id;
		cin>>id;
		if(mark[id]){
			printf("%04d: Checked\n",id);
			continue;
		}
		if(IdtoRank[id]==0){
			printf("%04d: Are you kidding?\n",id);
			continue;
		}
		if(IdtoRank[id]==1){
			printf("%04d: Mystery Award\n",id);
			mark[id]=true;
			continue;
		}
		if(judge(IdtoRank[id])){
			printf("%04d: Minion\n",id);
			mark[id]=true;
			continue;
		}
		printf("%04d: Chocolate\n",id);
		mark[id]=true;
		
	}
	return 0;
}
