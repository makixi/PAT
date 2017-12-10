#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		double g1,g2=0;
		int cnt=0;
		double maxn=-inf,minn=inf;
		cin>>g1;
		for(int j=0;j<n-1;++j){
			double tmp;cin>>tmp;
			if(tmp>=0&&tmp<=m){
				g2+=tmp;++cnt;
				maxn=max(maxn,tmp);
				minn=min(minn,tmp);
			}
		}
		g2=(g2-maxn-minn)/(cnt-2);
		cout<<(int)((g1+g2)/2+0.5)<<endl;
	}
	return 0;
} 
