#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const double eps = 1e-8;
const int maxn = 110;

int main() {
	int T, k, n1, b, t, n2;
	cin >> T >> k;
	while (k--) {
		cin >> n1 >> b >> t >> n2;
		if(T<t)printf("Not enough tokens.");
		else {
			if ((n2 > n1&&b) || (n2 < n1 && !b)) {
				printf("Win %d!", t); T += t;
			}
			else if (T >= t) {
				printf("Lose %d.", t); T -= t;
			}
		}
		printf("  Total = %d.\n", T);
		if (T <= 0) { printf("Game Over."); return 0; }
	}
	return 0;
}
