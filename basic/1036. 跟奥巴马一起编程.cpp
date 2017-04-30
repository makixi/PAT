#include<iostream>
using namespace std;

int main() {
	int n,row,col;
	char c;
	cin >> n >> c;
	col = n;
	n *= 10;
	if ((n/2) % 10 >= 5) n += 10;
	n /= 10;
	row = n / 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == 0 || i == row - 1)cout << c;
			else {
				if (j == 0 || j == col - 1) cout << c;
				else cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
