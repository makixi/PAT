#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cntp=0,cntt=0,res=0;
	for(char c:s)if(c=='T')++cntt;
	for(char c:s)
		if(c=='P')++cntp;
		else if(c=='A')res=(res+cntt*cntp)%1000000007;
		else if(c=='T') --cntt;
	cout<<res;
	return 0;
}
