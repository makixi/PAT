#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	double w, p;
	double v2, s = 0;
	cin >> w >> p;
	v2 = 2 * 1000 * 100 / w;
	while (v2 > 0.000001) {
		s += v2 / 9.8;
		v2 *= (100 - p) * 0.01;
	}
	printf("%.3f", s);
	return 0;
}
