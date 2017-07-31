#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int coin[maxn] = {0};
int main() {
	int n, m,tmp;
	cin >> n >> m;//total number of coins	money she has to pay
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		coin[tmp]++;
	}
	for (int i = 0; i < maxn; ++i) {
		if (coin[i]) {
			coin[i]--;
			if (m > i&&coin[m - i]) {
				printf("%d %d", i, m - i);
				return 0;
			}
			coin[i]++;
		}
	}
	cout << "No Solution" << endl;
	return 0;
}
