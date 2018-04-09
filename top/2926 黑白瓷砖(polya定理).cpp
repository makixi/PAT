#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 300;
int p[MAXN + 10][MAXN + 10], ans[MAXN + 10];
void cheng(int flag) {
	for (int i = 1; i <= MAXN; i++)p[flag][i] = 2 * p[flag - 1][i];
	for (int i = 1; i <= MAXN; i++) {
		p[flag][i + 1] += p[flag][i] / 10;
		p[flag][i] %= 10;
	}
}
void jia(int* a, int* b) {
	for (int i = 1; i <= MAXN; i++)a[i] += b[i];
	for (int i = 1; i <= MAXN; i++) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
}
void chu(int* a) {
	for (int i = MAXN; i >= 1; i--) {
		while (i && a[i] < 6) {
			a[i - 1] += a[i] * 10;
			a[i] = 0;
			i--;
		}
		a[i - 1] += a[i] % 6 * 10;
		a[i] /= 6;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int tot = n * (n + 1) / 2;
	int x = (tot + 2) / 3;
	int y = (tot + n / 2 + 1) / 2;
	p[0][1] = 1;
	for (int i = 1; i <= tot; i++)cheng(i);
	jia(ans, p[tot]);
	jia(ans, p[x]), jia(ans, p[x]);
	jia(ans, p[y]), jia(ans, p[y]), jia(ans, p[y]);
	chu(ans);
	int len = 0;
	for (int i = MAXN; i >= 1; i--)
		if (ans[i]) {
			len = i;
			break;
		}
	for (int i = len; i >= 1; i--)printf("%d", ans[i]);
	return 0;
}
