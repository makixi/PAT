#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	getchar();
	while(n--){
		string s;
		getline(cin,s);
		if(s.length()<6)cout<<"Your password is tai duan le.\n";
		else{
			bool zifu=false,shuzi=false,hefa=true;
			for(int i=0;i<s.length();++i)
				if(s[i]!='.'&&!isdigit(s[i])&&!isalpha(s[i])){
					hefa=false;
					break;
				}else if(isdigit(s[i]))shuzi=true;
				else if(isalpha(s[i]))zifu=true;
			if(!hefa)cout<<"Your password is tai luan le.\n";
			else if(zifu&&!shuzi)cout<<"Your password needs shu zi.\n";
			else if(!zifu&&shuzi)cout<<"Your password needs zi mu.\n";
			else cout<<"Your password is wan mei.\n";
		}
	}
	return 0;
}
