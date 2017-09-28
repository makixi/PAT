#include<iostream>
using namespace std;
const int maxn=1001;
int a[maxn],b[maxn];
int main(){
	int n,x;
	while(cin>>n>>x)a[x]=n;
	for(int i=maxn-1;i>=0;--i){
		b[i]=a[i+1]*(i+1);
	}
	bool first=true;
	for(int i=maxn-1;i>=0;--i)
		if(b[i]){
			if(!first)cout<<" ";
			first=false;
			cout<<b[i]<<" "<<i;
		}
	if(first)cout<<"0 0";
	return 0;
}
