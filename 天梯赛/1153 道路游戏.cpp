#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,p,a,b,cnt;
int dp[1005],gold[1005][1005],need[1005];
int main() {
	cin>>n>>m>>p;
	for (i=1;i<=n;i++) 
   		for (j=1;j<=m;j++) cin>>gold[i][j];
  	for (i=1;i<=n;i++) cin>>need[i];
  	for (i=1;i<=m;i++) 
    	for (j=1;j<=n;j++) {
     		a=i; b=j; cnt=0;
     		for (k=1;k<=p;k++) {
        		cnt+=gold[b][a];//Ë³Ê±ÕëÏÂÈ¥ 
        		if (i<k) break;
       			dp[i]=max(dp[i],dp[i-k]-need[b]+cnt);
       			a--; b--;
       			if (b==0) b=n;
     		}
    	} 
  	cout<<dp[m]<<endl;
  	return 0;
}
