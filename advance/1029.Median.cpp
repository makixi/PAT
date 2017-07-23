#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long int array[2000000];
int main(){
	int n1,n2;
	long int tmp;
	scanf("%d",&n1);
	for(int i=0;i<n1;++i)
		scanf("%ld",&array[i]);
	scanf("%d",&n2);
	for(int i=n1;i<n1+n2;++i)
		scanf("%ld",&array[i]);
	sort(array,array+n1+n2);
	printf("%ld",array[(n1+n2+1)/2-1]);
	return 0;
}
