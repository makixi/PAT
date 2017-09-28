#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> v(n+m);
	while(m>n)m-=n;
	for(int i=m;i<n+m;++i)cin>>v[i];
	for(int i=0;i<m;++i)v[i]=v[n+i];
	for(int i=0;i<n;++i){
		if(i)cout<<" ";
		cout<<v[i];
	}
	return 0;
}
