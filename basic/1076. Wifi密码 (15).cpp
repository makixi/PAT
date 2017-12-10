#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	string res=""; 
	while(n--){
		string a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a[2]=='T')res+=a[0]-'A'+'1';
		if(b[2]=='T')res+=b[0]-'A'+'1';
		if(c[2]=='T')res+=c[0]-'A'+'1';
		if(d[2]=='T')res+=d[0]-'A'+'1';
	} 
	cout<<res;
	return 0;
} 
