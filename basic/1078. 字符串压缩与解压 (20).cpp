#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	char c;
	cin>>c;
	getchar();
	string str;
	getline(cin,str);
	if(c=='C'){
		char pre=str[0];
		int cnt=1;
		for(int i=1;i<str.length();++i)
			if(str[i]==pre)++cnt;
			else{
				if(cnt>1)cout<<cnt<<pre;
				else cout<<pre;
				cnt=1;
				pre=str[i];
			}
		if(cnt>1)cout<<cnt<<pre;
		else cout<<pre;
	}else{//D
		int cnt=0;
		for(int i=0;i<str.length();++i)
			if(isdigit(str[i]))
				cnt=cnt*10+str[i]-'0';
			else{
				if(cnt==0)cout<<str[i];
				else while(cnt--)cout<<str[i];
				cnt=0;
			}
	}
	return 0;
} 
