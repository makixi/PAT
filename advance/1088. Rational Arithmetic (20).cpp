#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long a,b,c,d;
long long gcd(long long a,long long b){
	return (b==0)?a:gcd(b,a%b);
}
void solve(long long m,long long n){
	bool negative1=false,negative2=false;
	if(!n){
		cout<<"Inf";
		return;
	}
	if(!m){
		cout<<"0";
		return;
	}
	if(m<0){
		negative1=true;
		m=-m;
	}
	if(n<0){
		negative2=true;
		n=-n;
	}
	bool flag=false;
	if(negative1&&negative2)
		flag=false;
	else if(negative1||negative2)
		flag=true;
	if(m==n){
		if(flag)cout<<"(-1)";
		else cout<<"1";
		return;
	}
	long long x=m%n;
	long long y=m/n;
	if(x==0){
		if(!flag)cout<<y;
		else cout<<"(-"<<y<<")";
		return;
	}else{
		long long tmp1,tmp2,tmp;
		tmp1=m-y*n;
		tmp2=n;
		tmp=gcd(tmp1,tmp2);
		tmp1/=tmp;
		tmp2/=tmp;
		if(flag){
			cout<<"(-";
			if(y)
				cout<<y<<" "<<tmp1<<"/"<<tmp2;
			else
				cout<<tmp1<<"/"<<tmp2;
			cout<<")";
		}else{
			if(y)
				cout<<y<<" "<<tmp1<<"/"<<tmp2;
			else
				cout<<tmp1<<"/"<<tmp2;
		}
	}
}
void add(){
	long long m,n;
	m=a*d+b*c;
	n=b*d;
	solve(a,b);
	cout<<" + ";
	solve(c,d);
	cout<<" = ";
	solve(m,n);
	cout<<endl;
}
void substract(){
	long long m=a*d-b*c;
	long long n=b*d;
	solve(a,b);
	cout<<" - ";
	solve(c,d);
	cout<<" = ";
	solve(m,n);
	cout<<endl;
}
void multi(){
	long long m,n;
	m=a*c;
	n=b*d;
	solve(a,b);
	cout<<" * ";
	solve(c,d);
	cout<<" = ";
	solve(m,n);
	cout<<endl;
}
void division(){
	long long m=a*d,n=b*c;
	solve(a,b);
	cout<<" / ";
	solve(c,d);
	cout<<" = ";
	solve(m,n);
	cout<<endl;
}
int main(){
	scanf("%lld/%lld%lld/%lld",&a,&b,&c,&d);
	add();
	substract();
	multi();
	division();
	return 0;
}
