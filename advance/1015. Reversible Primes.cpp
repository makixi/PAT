#include<iostream>
using namespace std;
bool isprime(int num) {
	if (num == 1) return false;
	for (int i = 2; i*i <= num; ++i)
		if (num%i == 0) return false;
	return true;
}
int main() {
	int n, d;
	while (1) {
		cin >> n;
		if (n < 0) return 0;
		cin >> d;
		if (!isprime(n)) {
			cout << "No" << endl;
			continue;
		}
		int temp[100],len=0;
		int re=0;
		while (n) {
			temp[len++] = n%d;
			n /= d;
		}
		for (int i = 0; i < len; ++i)
			re = re * d + temp[i];
		if (isprime(re)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

