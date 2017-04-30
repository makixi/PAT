#include<iostream>
#include<stdlib.h>
#include<map>
#include<cmath>
using namespace std;
int main() {
	int c[8][2] = { 1,0, -1,0, 0,1, 0,-1, 1,1, 1,-1, -1,1, -1,-1 };
	map<int, int> cnt;
	int m, n, tol, count = 0, row, col, value;
	cin >> m >> n >> tol;
	int **a = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		a[i] = (int *)malloc(sizeof(int)*m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			int temp = a[i][j], flag = 1;
			if (cnt[a[i][j]] == 1) {
				for (int k = 0; k<8; k++) {
					int x,y;
					x = i + c[k][0];y = j + c[k][1];
					if (x >= 0 && x<n && y<m && y >= 0 && abs(a[x][y] - a[i][j]) <= tol) flag = 0;
				}
				if (flag) {
					count++;
					row = i;
					col = j;
					value = a[i][j];
				}
			}
		}
	}
	if (count == 0)cout << "Not Exist";
	else if (count > 1) cout << "Not Unique";
	else {
		cout << "(" << col + 1 << ", " << row + 1 << "): " << value;
	}
	return 0;
}
