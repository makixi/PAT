#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	string name;
	int cnt;
	double ave;
};
bool cmp(node a,node b){
	if(a.cnt!=b.cnt)return a.cnt>b.cnt;
	return a.ave>b.ave;
}
int main(){
	int n,k,tmp;
	cin>>n;
	string str;
	vector<node> v;
	node nod;
	for(int i=0;i<n;++i){
		cin>>str;
		set<int> s;
		cin>>k;
		for(int j=0;j<k;++j){
			cin>>tmp;
			s.insert(tmp);
		}
		nod.name=str;
		nod.cnt=s.size();
		nod.ave=(double)s.size()/(double)k;
		v.push_back(nod);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<3;++i){
		if(i)cout<<" ";
		if(v.size()-1<i)cout<<"-";
		else cout<<v[i].name;
	}
	return 0;
}
