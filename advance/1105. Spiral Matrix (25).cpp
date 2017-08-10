#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int solve(int N) {
	int res = sqrt(N);
	while (res >= 1) {
		if (!(N%res))
			return res;
		res--;
	}
	return 1;
}
int main() {
	int N,n,m;
	cin >> N;
	vector<int> val(N);
	n = solve(N), m = N / n;
	vector<vector<int>> matrix(m,vector<int>(n));	//m≈≈n¡–
	for (int i = 0; i < N; ++i)cin >> val[i];
	sort(val.begin(), val.end(), cmp);
	int curr = 0;
	for (int i = 0; i < m / 2 + m % 2; ++i) {
		for (int j = i; j < n - i&&curr < N; ++j)		//above
			matrix[i][j] = val[curr++];
		for (int j = i+1; j < m - i-1&&curr < N; ++j)		//right
			matrix[j][n-1-i] = val[curr++];
		for (int j = n - i - 1; j >= i&&curr < N; --j)		//below
			matrix[m - i - 1][j] = val[curr++];
		for (int j = m - i - 2; j > i&&curr < N; --j)		//left
			matrix[j][i] = val[curr++];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j)cout << " ";
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}
