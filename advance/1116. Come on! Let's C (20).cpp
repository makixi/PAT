#include<iostream>
#include<map>
using namespace std;
bool isprime(int num){
	if(num<=1)return false;
	for(int i=2;i*i<=num;++i)
		if(num%i==0)return false;
	return true;
}
int main(){
	int n,k,tmp;
	cin>>n;
	map<int,int> m;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		m[tmp]=i;
	}
	cin>>k;
	while(k--){
		cin>>tmp;
		if(m[tmp]==1){printf("%04d: Mystery Award\n",tmp);m[tmp]=-1;}
		else if(isprime(m[tmp])){printf("%04d: Minion\n",tmp);m[tmp]=-1;}
		else if(m[tmp]==-1)printf("%04d: Checked\n",tmp);
		else if(m[tmp]==0) printf("%04d: Are you kidding?\n",tmp);
		else {printf("%04d: Chocolate\n",tmp);m[tmp]=-1;}
	}
	return 0;
}
