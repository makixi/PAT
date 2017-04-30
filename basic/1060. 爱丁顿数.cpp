#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main() {
	int n,e,day=0,flag=0;
	cin >> n;
	int *a;
	a = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n,cmp);
	int p=0;
	while(day<=n&&a[p]>p+1){
		day++;
		p++;
	}
	cout<<day;
	return 0; 
}
