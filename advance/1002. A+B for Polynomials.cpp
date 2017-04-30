#include<iostream>
using namespace std;
#define MAX 1001
int main() {
	float  c[MAX] = {0},num;
	int k,j,count=0;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int l;
		cin >> l>>num;
		c[l]+=num;
	}
	cin >>j;
	for (int i = 1; i <= j; i++) {
		int l;
		cin >> l>>num;
		c[l]+=num;
	}
	for (int i = 0; i < 1001; i++) {
		if (c[i] != 0) {
			 ++count;
		}
	}
	cout << count ;
	if(count>0) cout<<" ";
	for (int i = 1001; i >= 0; --i) {
		if (c[i] != 0) { 
			printf("%d %.1f", i, c[i]); --count;
			if (count >= 1) 
				cout << " ";
		}
	}
	return 0;
}
