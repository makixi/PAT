#include<iostream>
#define MAX 100000
using namespace std;
int main() {
	int n;
	int position = 0,maxscore=0;
	cin >> n;
	int a[MAX] = {0};
	for (int i = 0; i < n; i++) {
		int type,score;
		cin >> type>>score;
		a[type - 1] += score;
		if (a[type - 1] > maxscore) {
			maxscore=a[type-1];
			position = type - 1;
		}
	}
	cout << position + 1 << " " << maxscore;
	return 0;
}
