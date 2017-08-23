#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10010;
double a[maxn],b[maxn];
double res[maxn];
int main(){
	int n,m,x,y,resa=0,resb=0,xa=0,xb=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x>>y;
		a[x]=y;
		xa=max(xa,x);
	}
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>x>>y;
		b[x]=y;
		xb=max(xb,x);
	}
	for(int i=xa;i>=xb;--i){
		res[i-xb]=a[i]/b[xb];
		for(int j=xb;j>=0;j--)
			a[i-xb+j]-=b[j]*res[i-xb];
	}
	for(int i=xa;i>=0;--i)
		if(fabs(res[i])<0.05)
			res[i]=0;
		else resa++;
	for(int i=xa;i>=0;--i)
		if(fabs(a[i])<0.05)
			a[i]=0;
		else resb++;
	if(resa==0)
		printf("0 0 0.0\n");
	else{
		cout<<resa;
		for(int i=xa;i>=0;i--)
			if(fabs(res[i])>=0.05)
				printf(" %d %.1f", i, res[i]);
		cout<<endl;
	}
	if(resb==0)
		printf("0 0 0.0\n");
	else{
		cout<<resb;
		for(int i=xa;i>=0;i--)
			if(fabs(a[i])>=0.05)
				printf(" %d %.1f", i, a[i]);
		cout<<endl;
	}
	return 0;
}
