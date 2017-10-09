#include<iostream>
#include<algorithm>
using namespace std;
int sum(int num) {
	int whole = 0;
	while (num) {
		whole += num % 10;
		num /= 10;
	}
	return whole;
}
int main() {
	int n;
	cin >> n;
	int *a, *b;
	a = (int *)malloc(n * sizeof(int *));
	b = (int *)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i]=sum(a[i]);
	}
	sort(b, b + n);
	int count = 0;
	if (n >= 1) ++count;
	for (int i = 1; i < n; i++)if (b[i] != b[i - 1]) ++count;
	cout << count << endl;
	if (n >= 1)cout << b[0];
	for (int i = 1; i < n; i++)if (b[i] != b[i - 1]) cout << " " << b[i];
	return 0;
} 
