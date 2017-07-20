#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	map<int, int> ma;
	int half = m*n / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			ma[num]++;
			if (ma[num] > half) {
				cout << num;
				return 0;
			}
		}
	}
	return 0;
}
