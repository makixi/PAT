#include<iostream>
#include<string> 
using namespace std;
int main(){
	string a,q="";
	int b,r=0,tmp;
	cin>>a>>b;
	for(int i=0;i<a.length();++i){
		tmp=r*10+a[i]-'0';
		q+=(tmp/b+'0');
		r=tmp%b;
	}
	while(q[0]=='0')q.erase(0,1);
	if(q.length()==0)cout<<0<<" "<<r;
	else cout<<q<<" "<<r; 
	return 0;
} 
