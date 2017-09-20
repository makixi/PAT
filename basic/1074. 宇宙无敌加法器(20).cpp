#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a,b,n,res="";
	int c=0,tmp;//carry
	cin>>n>>a>>b;
	int lena=a.length(),lenb=b.length();
	reverse(n.begin(),n.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0;i<n.length();++i){//第一个数 
		int m=n[i]-'0';//m进制
		tmp=0;
		if(i<a.length())tmp+=a[i]-'0';
		if(i<b.length())tmp+=b[i]-'0';
		tmp+=c;
		if(m==0)m=10;
		c=tmp/m;
		tmp%=m;
		res+=tmp+'0';
	}
	while(c){
		tmp=c%10;
		c/=10;
		res+=tmp+'0';
	}
	reverse(res.begin(),res.end());
	while(res[0]=='0')res.erase(0,1);
	if(res.length()==0)cout<<0;//辣鸡测试点毁我青春 
	else cout<<res;
	return 0;
}
