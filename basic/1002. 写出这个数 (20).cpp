#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string str[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
	string s;
	int res=0;
	cin>>s;
	for(auto c:s)res+=c-'0';
	vector<string> ans;
	while(res>0){
		int tmp=res%10;
		res/=10;
		ans.push_back(str[tmp]);
	}
	for(int i=ans.size()-1;i>0;--i)cout<<ans[i]<<" ";
	cout<<ans[0];
	return 0;
}
