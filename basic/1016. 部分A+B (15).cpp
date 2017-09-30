#include<iostream>
#include<string> 
using namespace std;

int main(){
	string a,b;
	long aa=0,bb=0;
	int da,db;
	cin>>a>>da>>b>>db; 
	for(int i=0;i<a.length();++i)
		if(a[i]==da+'0')aa=aa*10+da;
	for(int i=0;i<b.length();++i)
		if(b[i]==db+'0')bb=bb*10+db;
	cout<<(aa+bb);
	return 0;
} 
