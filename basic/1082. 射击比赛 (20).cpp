#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
double dis(int x,int y){
	return sqrt(1.0*x*x+1.0*y*y);
}
int main(){
	//ios::sync_with_stdio(false);
	int n;
	cin>>n;
	double lihai=inf,caiji=-inf;
	int rlihai,rcaiji;
	while(n--){
		int id,x,y;
		cin>>id>>x>>y;
		double d=dis(x,y);
		if(d<lihai){
			lihai=d;
			rlihai=id;
		}
		if(d>caiji){
			caiji=d;
			rcaiji=id;
		}
	}
	printf("%04d %04d",rlihai,rcaiji);
	return 0;
}
