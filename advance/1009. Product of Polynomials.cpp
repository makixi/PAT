#include<iostream>
using namespace std;
#define MAX 2001
int main() {
	float a[1001]={0.0},b[1001]={0.0},c[MAX]={0.0};
	int k,l,count=0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int temp;
		float tvalue;
		cin >> temp>> tvalue;
		a[temp]+=tvalue;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int temp;
		float tvalue;
		cin >> temp >> tvalue;
		b[temp]+=tvalue;
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (a[i] && b[j]){
			c[i+j] += a[i] * b[j];
			}
		}
	}
	for (int i = 0; i < MAX; i++) {
			if (c[i]){
			++count;
			}
	}
	cout<<count;
	if(count) cout<<" ";
	for (int i = MAX; i >=0; i--) {
		if (c[i]) {
		printf("%d %.1f", i, c[i]);
		--count;
		if(count>0) cout<<" ";}
		
	}
	return 0;
}
