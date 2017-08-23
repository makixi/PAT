#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	double sum=0;
	cin>>n;
	string str;
	map<string,bool> m;
	map<string,int> zan;
	vector<string> v;
	for(int i=0;i<n;++i){
		cin>>str;m[str]=true;
	}
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>str;
		cin>>zan[str];
		sum+=zan[str];
	}
	sum/=n;
	for(map<string,int>::iterator it=zan.begin();it!=zan.end();++it){
		if(m[it->first])continue;
		if(it->second>sum)v.push_back(it->first);
	}
	if(v.size()==0)printf("Bing Mei You\n");
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl;
	return 0;
}
