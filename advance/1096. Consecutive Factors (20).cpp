#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int max=sqrt(n);
	for (int len = 12; len > 0;len--) {
		for (int start = 2; start <= max; ++start) {
			long long res = 1;
			for (int i = start; i - start <= len-1; i++)
				res *= i;
			if (n%res == 0) {
				cout << len << endl << start;
				for (int i = start+1; i - start <= len-1; i++)
					cout << "*" << i;
				return 0;
			}
		}
	}
	cout << "1" << endl<<n;
	return 0;
}
