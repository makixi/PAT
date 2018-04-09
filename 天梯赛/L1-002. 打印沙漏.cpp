#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n==0){
		cout<<0;
		return 0;
	}
	int row=1,sum=1;
	do{
		row++;
		sum+=2*(2*row-1);
	}while(n>=sum);
	sum-=2*(2*row-1);
	row--;
	for(int i=row;i>=1;--i){
		for(int j=1;j<=row-i;++j)
			cout<<" ";
		for(int j=1;j<=i*2-1;++j)
			cout<<s;
		cout<<endl;
	}
	for(int i=2;i<=row;++i){
		for(int j=1;j<=row-i;++j)
			cout<<" ";
		for(int j=1;j<=i*2-1;++j)
			cout<<s;
		cout<<endl;
	}
	cout<<n-sum;
	return 0;
}
