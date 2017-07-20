#include<iostream>
#include<string>
using namespace std;
int main() {
	string a;
	getline(cin, a);
	int n = a.size()+2;
	int n1 = n / 3, n2 = n / 3 + n % 3;
	int i, j, k;
	for (i = 1; i < n1; ++i) {
			cout << a[i-1];
			for (k = 0; k < n2 - 2; ++k)
				cout << " ";
			cout << a[n-2 - i] << endl;
	}
	for(j=i;j<i+n2;j++)
	cout << a[j - 1];
	return 0;
}
