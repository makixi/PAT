#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	int score[101] = { 0 };

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if ((temp >= 0) && temp <= 100) {
			score[temp]++;
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		if (i) cout << " " << score[temp];
		else
			cout << score[temp];
	}
	return 0;
	}

