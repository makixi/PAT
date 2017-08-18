#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	vector<string> res,tmp;
	map<string,string> m;
	map<string,bool> attend;
	int n,q;
	string a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		m[a]=b;
		m[b]=a;
	}
	cin>>q;
	while(q--){
		cin>>a;
		attend[a]=true;
		tmp.push_back(a);
	}
	for(int i=0;i<tmp.size();++i)
		if(m[tmp[i]]==""||!attend[m[tmp[i]]])
			res.push_back(tmp[i]);
	cout<<res.size()<<endl;
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();++i){
		if(i)cout<<" ";
		cout<<res[i];
	}
	return 0;
}
