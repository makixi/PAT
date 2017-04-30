#include<iostream>
using namespace std;

int main() {
	int N,sum=0,a[10];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			sum += a[i] * 10 + a[j];
			sum += a[j] * 10 + a[i];
		}
	}
	cout << sum;
	return 0;
}
