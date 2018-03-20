#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	int d,n;
	cin>>d>>n;
	string pre="";
	pre+=('0'+d);
	//cout<<(char)('0'+d)<<endl;
	while(--n){
		//cout<<pre<<endl;
		string tmp="";
		int cnt=1;
		for(int i=1;i<pre.length();++i){
			if(pre[i]==pre[i-1])++cnt;
			else{
				tmp+=pre[i-1];
				tmp+=('0'+cnt);
				cnt=1;
			}
		}
		tmp+=pre[pre.length()-1];
		tmp+=('0'+cnt);
		pre=tmp;
	}
	cout<<pre;
	return 0;
}
