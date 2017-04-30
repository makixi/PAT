#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	int index=0;
	int j=1;
	cin >> a;
	if (a[0] == '-') cout << a[0];
	int n = a.size() - 1;
	while ((a[n] != '+')&&(a[n] != '-')) {
		index += a[n]-'0';
		j *= 10;
		n--;
	}
	if (a[n] == '-') index *= -1;
	if (index == 0) {
		if (int i = 1; i < n - 1; i++) {
			cout << a[i];
		}
	}
	else if (index < 0) {
		index *= -1;
		cout << "0.";
		for (int i = 1; i < index; i++)
			cout << "0";
		for (int i = 1; i < n - 1; i++) {
			if (a[i] != '.')cout << a[i];
		}
	}
	else {
		int s = 0;
		for (int i = 1; i < n - 1; i++) {
			if (a[i] != '.') { cout << a[i]; s++; }
			if ((s - 1) == index && (s != n - 3)) 
				cout << ".";
		}
		while (s <= index) {
			cout << "0";
			s++;
		}
	}
	return 0;
}
