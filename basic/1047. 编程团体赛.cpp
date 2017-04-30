#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1000
int main() {
	int n, ChamId, ChamScore;
	int qId, mId, score;
	int a[MAX] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d-%d %d", &qId, &mId, &score);
		a[qId] += score;
		if (a[qId] > ChamScore) {
			ChamScore = a[qId];
			ChamId = qId;
		}
	}
	cout << ChamId << " " << ChamScore;
	return 0;
}
