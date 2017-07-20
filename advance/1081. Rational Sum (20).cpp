#include<iostream>
#include<cmath>
using namespace std;
long long gcd(long long a, long long b) {
	return b == 0 ? abs(a) : gcd(b, a%b);
}
int main() {
	long long n, a, b, suma=0, sumb=1, gcdvalue;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%lld/%lld", &a, &b);
		gcdvalue = gcd(a, b);
		a = a / gcdvalue; b = b / gcdvalue;
		suma = sumb*a+suma*b;
		sumb = sumb*b;
		gcdvalue = gcd(suma, sumb);
		suma = suma / gcdvalue;
		sumb = sumb / gcdvalue;
	}
	long long num = suma / sumb;//整数部分
	suma =suma- sumb*num;
	if (num != 0) {
		cout << num;
		if (suma != 0)cout << " ";
	}
	if (suma != 0) {
		cout << suma << "/" << sumb;
	}
	if (num == 0 && suma == 0)cout << "0";
	return 0;
}
