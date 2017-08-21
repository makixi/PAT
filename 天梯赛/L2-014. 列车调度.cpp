#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int n,tmp;
	cin>>n;
	set<int> s;
	s.insert(0);
	for(int i=0;i<n;++i){
		cin>>tmp;
		if(tmp<*s.rbegin())
			s.erase(*(s.upper_bound(tmp)));
		s.insert(tmp);
		cout<<s.size()-1<<endl;
	}
	cout<<s.size()-1;
	return 0;
}
