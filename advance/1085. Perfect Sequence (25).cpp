#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100005;
long long a[maxn];  //最后一个测试点要求longlong
int main(){
	int n;
	long long p;
	cin>>n>>p;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	int len=1;
	int tmp;
	for(int i=0;i<n;++i)
		for(int j=i+len;j<n;++j)
			if(a[j]<=a[i]*p){
				tmp=j-i+1;
				len=max(tmp,len);
			}
			else  break;
	cout<<len;
	return 0;
}
