#include<iostream>
using namespace std;

int main() {
	int k,maxsum=-999999999,max=-999999999;
	int begin, end;
	//vector<int> vec;
	cin >> k;
	int *a;
	a = (int *)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++) {
		int sum = 0;
		if (a[i] > max) max = a[i];
		for (int j = i ; j < k; j++) {
			sum += a[j];
			if (sum > maxsum) { maxsum = sum; begin = a[i]; end = a[j]; }
		}
	}
	if (max < 0) cout << "0 " << a[0] << " " << a[k - 1];
	else
	cout << maxsum << " " << begin << " " << end;
	return 0;
}
