#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int m, n,a,b,exchange,*squ;
	cin >> m >> n>>a>>b>>exchange;
	squ = (int *)malloc(m*n * sizeof(int *));
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) {
			int value;
			cin >> value;
			if (value >= a&&value <= b) value = exchange;
			squ[i*n+j] = value;
		}
	for (int i = 0; i < m*n; i++) {
		cout << setfill('0') << setw(3) << squ[i];
		if (((i+1)%n == 0)) cout << endl;
		else cout << " ";
	}
	return 0;
} 
