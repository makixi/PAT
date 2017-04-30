#include<iostream>
using namespace std;

int main() {
	int n,sum=0;
	cin >> n;
	int *a;
	a = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(n>0)
	sum += 6 * a[0]+5;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1])sum += 6 * (a[i] - a[i - 1]);
		if (a[i] < a[i - 1]) sum += 4 * (a[i - 1] - a[i]);
		sum += 5;
	}
	cout << sum;
	return 0;
}
