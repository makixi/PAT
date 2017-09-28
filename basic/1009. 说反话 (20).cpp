#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
	string s,a;
	getline(cin,s);
	stringstream l(s);
	vector<string> res;
	for(;l>>a;)res.push_back(a);
	for(int i=res.size()-1;i>=0;--i){
		cout<<res[i];
		if(i)cout<<" ";
	}
	return 0;
}
