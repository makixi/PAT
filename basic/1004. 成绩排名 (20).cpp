#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	string name;
	string id;
	int score;
};
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	int n;
	cin>>n;
	vector<node> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i].name>>v[i].id>>v[i].score;
	} 
	sort(v.begin(),v.end(),cmp);
	cout<<v[0].name<<" "<<v[0].id<<endl<<v[n-1].name<<" "<<v[n-1].id;
	return 0;
}
