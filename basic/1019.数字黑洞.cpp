#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a,b;
	int num;
	cin>>num;
	do{
		a=to_string(num);
		while(a.length()<4)a.insert(0,1,'0');
		sort(a.begin(),a.end());
		b=a;
		reverse(a.begin(),a.end());
		int aa=stoi(a);
		int bb=stoi(b);
		num=aa-bb;
		printf("%04d - %04d = %04d\n",aa,bb,num);
	}while(num!=6174&&num!=0);
	return 0;
}
