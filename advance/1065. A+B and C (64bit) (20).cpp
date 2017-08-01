#include<iostream>
using namespace std;
int main(){
	long long a,b,c,sum; 
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;++cnt){
		scanf("%lld %lld %lld",&a,&b,&c);
		sum=a+b;		//Using variable sum 
		printf("Case #%d: ",cnt);
		if(a>0&&b>0&&sum<0)		//overflow
			printf("true\n");
		else if(a<0&&b<0&&sum>=0)
			printf("false\n");
		else  if(sum>c)
			printf("true\n");
		else 
			printf("false\n");
	}
	return 0;
}
