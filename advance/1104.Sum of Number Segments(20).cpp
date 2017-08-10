#include<iostream>
using namespace std;
const int maxn = 100005;
double val[maxn];
int main() {
	int n;
	double res = 0.0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		res += val[i] * i*(n - i + 1);
	}
	printf("%.2lf\n", res);
	return 0;
}
