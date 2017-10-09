#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int *a,*b;
	a = (int *)malloc(sizeof(int *)*m);
	b = (int *)malloc(sizeof(int *)*m);
	for (int i = 0; i < m; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	for (int j = 0; j < n; j++) {
		int score=0;
		for (int i = 0; i < m; i++) {
			int key;
			cin >> key;
			if (key == b[i]) score += a[i];
		}
		cout << score << endl;
	}
	return 0;
}
