#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> res,sum;
void Func(int i,int &j,int &tmpsum){
	int left=i,right=n;
	while(left<right){
		int mid=(left+right)>>1;
		if(sum[mid]-sum[i-1]>=m)right=mid;
		else left=mid+1;
	}
	j=right;
	tmpsum=sum[j]-sum[i-1];
}
int main(){
	cin>>n>>m;
	sum.resize(n+1);
	for(int i=1;i<=n;++i){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int minn=sum[n];
	for(int i=1;i<=n;++i){
		int j,tmpsum;
		Func(i,j,tmpsum);
		if(tmpsum>minn)continue;
		if(tmpsum>=m){
			if(tmpsum<minn){
				minn=tmpsum;
				res.clear();
			}
			res.push_back(i);
			res.push_back(j);
		}
	}
	for(int i=0;i<res.size();i+=2)
		printf("%d-%d\n", res[i], res[i+1]);
	return 0;
}
