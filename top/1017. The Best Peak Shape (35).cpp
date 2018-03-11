#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int val[maxn],dpu[maxn],dpd[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	fill(dpu+1,dpu+1+n,1);
	fill(dpd+1,dpd+1+n,1);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(val[j]>val[i])
				dpu[j]=max(dpu[j],dpu[i]+1);
	for(int i=n;i>=1;--i)
		for(int j=i-1;j>=1;--j)
			if(val[j]>val[i])
				dpd[j]=max(dpd[j],dpd[i]+1);
	int pos=-1,len=0;
	for(int i=n;i>=1;--i)
		if(dpu[i]>1&&dpd[i]>1&&len<dpu[i]+dpd[i]-1){
			len=dpu[i]+dpd[i]-1;
			pos=i;
		}
	if(pos==-1) cout<<"No peak shape";
	else cout<<len<<" "<<pos<<" "<<val[pos];
	return 0;
}
