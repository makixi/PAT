#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {
	int cnt=0,cntt=0,cntp=0;
	string str;
	cin>>str;
	int len=str.length();
	for(int i=0;i<len;++i)
		if(str[i]=='T')cntt++;
	for(int i=0;i<len;++i){
		if(str[i]=='P')cntp++;
		if(str[i]=='T')cntt--;
		if(str[i]=='A')cnt=(cnt+(cntp*cntt)%1000000007)%1000000007;
	}
	cout<<cnt;
	return 0;
}
