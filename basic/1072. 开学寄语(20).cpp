#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	string name;
	vector<int> thing;
};
int main(){
	int n,m,cnt=0;
	cin>>n>>m;
	map<int,bool> mark;
	vector<node> res;
	for(int i=0;i<m;++i){
		int tmp;
		cin>>tmp;
		mark[tmp]=true;
	}
	while(n--){
		bool flag=false;
		string name;int k;
		cin>>name>>k;
		node no;
		no.name=name;
		while(k--){
			int tmp;
			cin>>tmp;
			if(mark[tmp]){
				no.thing.push_back(tmp);++cnt;
			}
		}
		if(no.thing.size())res.push_back(no);
	}
	for(int i=0;i<res.size();++i){
		cout<<res[i].name<<":";
		for(int j=0;j<res[i].thing.size();++j)
			printf(" %04d",res[i].thing[j]);
		cout<<endl;
	}
	cout<<res.size()<<" "<<cnt;
	return 0;
}
