#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void output(int num) {
	static int a = 0;
	if (a != 0) cout << ",";
	if (num >= 1000) { output(num / 1000); output(num % 1000); a=1;}
	else if (num <=99&&a!=0) cout <<setfill('0')<<setw(3)<< num;
	else cout <<num ;
	a=1;
}
int main() {
	int a, b;
	int sum;
	cin >> a >> b;
	sum = a + b;
	if (sum < 0) { cout << "-"; sum = abs(sum); }
	output(sum);
	return 0;
}
