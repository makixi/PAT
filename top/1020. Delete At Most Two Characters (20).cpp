#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	map<string,bool> m;
	string str;
	cin>>str;
	m[str]=true;
	for(int i=0;i<str.length();++i){
		string tmp=str;
		tmp.erase(i,1);
		m[tmp]=true;
		for(int j=0;j<tmp.length();++j){
			string tmp2=tmp;
			tmp2.erase(j,1);
			m[tmp2]=true;
		}
	}
	cout<<m.size();
	return 0;
} 
