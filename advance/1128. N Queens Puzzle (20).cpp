#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1010;
int pos[maxn];
int main(){
    int k,n;
	cin>>k;
	while(k--){
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;++i)cin>>pos[i];
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
				if(pos[i]==pos[j]||abs(pos[i]-pos[j])==abs(i-j)){
					flag=false;
					break;
				}
		if(flag)cout<<"YES";
		else cout<<"NO";
		if(k)cout<<endl;
	} 
    return 0;
}
