#include<iostream>
using namespace std;
int main() {
	int n, cnt = 0,x=1,left=0,right=0,now=1;
	cin >> n;
	while (n / x) {
		right = n %x;
		left = n/(x*10);
		now = n / x % 10;
		if (now == 0)cnt += left*x;
		else if (now == 1)cnt += left*x + right + 1;
		else cnt += (left+1)*x;
		x *= 10;
	}
	cout << cnt << endl;
	return 0;
}
