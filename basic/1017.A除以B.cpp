#include<iostream>
#include<string>
using namespace std;

int main() {
	string a,q;
	int b=0,r=0;
	cin >> a >> b;
	int length = a.length();
	int temp = a[0] - '0';
	if (temp >= b)
		q.push_back(temp / b + '0');
	for (int i = 0; i < length; i++) {
		r = temp%b;
		temp = r * 10 + a[i] - '0';
		q.push_back(temp / b + '0');
	}
	r = temp%b;
	if (length == 1 && a[0] - '0' < b)
		cout << "0 " << a[0] - '0';
	else
		cout << q << " " << r;
	return 0;
	
}
