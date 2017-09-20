#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long int ll;
int main(){
	int n;
	cin>>n;
	while(n--){
		bool flag=true;
		string z;cin>>z;
		int len=z.length();
		if(len&1)flag=false;
		if(flag){
			ll a,b;
			a=stol(z.substr(0,len/2));
			b=stol(z.substr(len/2,len));
			if(a*b==0)flag=false;//两个测试点在这里 
			else {
				long double res=stol(z)*1.0/a/b;
				if(res!=round(res))flag=false;
			}
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
