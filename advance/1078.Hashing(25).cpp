#include<iostream>
using namespace std;
bool ha[10010];
bool isprime(int a) {
	if (a <= 1)return false;
	for (int i = 2; i*i <= a; ++i)
		if (a%i == 0)return false;
	return true;
}
int func(int a) {
	while (isprime(a) == false)a++;
	return a;
}
int main() {
	int m, n,key;
	cin >> m >> n;
	int size = func(m);
	for (int i = 0; i < n; ++i) {
		cin >> key;
		int index = key%size;
		if (ha[index] == false) {
			ha[index] = true;
			if (i != 0)cout << " ";
			cout << index;
		}
		else {
			bool flag = false;
			for (int step = 1; step < size; ++step) {
				index = (key + step*step) % size;
				if (ha[index] == false) {
					ha[index] = true;
					flag = true;
					if (i != 0)cout << " ";
					cout << index;
					break;
				}
			}
			if (flag == false) {
				if (i != 0)cout << " ";
				cout << "-";
			}
		}
	}
	return 0;
}
