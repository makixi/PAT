#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int cmp(const int &a, const int &b) {
	if (a > b)
		return 1;
	else
		return 0;
}
int cmp1(const int &a, const int &b) {
	if (a < b)
		return 1;
	else
		return 0;
}
int main() {
	int num;
	int a[4];
	cin >> num;
	while (1) {
		a[0] = num / 1000;
		a[1] = (num / 100) % 10;
		a[2] = (num / 10) % 10;
		a[3] = num % 10;
		sort(a, a+4, cmp);
		int bei = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		sort(a, a + 4, cmp1);
		int chu = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		 num = bei - chu;
		cout << setw(4) << setfill('0')<<bei << " - " << setw(4)<<setfill('0')<< chu << " = " << setw(4) << setfill('0')<<num;
		if (num == 6174||num==0) 
			break;
		cout << endl;
	}
	return 0;
}
