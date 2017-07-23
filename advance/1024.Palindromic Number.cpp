#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string num, rever;
	int uppercnt,cnt = 0,pre;
	cin >> num >> uppercnt;
	while (cnt < uppercnt) {
		rever = num;
		reverse(rever.begin(), rever.end());
		if (rever == num)break;
		int len = num.length();
		pre = 0;
		for (int i = 0; i <len; i++) {
			int tmpnum = (num[i] - '0') + (rever[i] - '0')+pre;
			pre = tmpnum / 10;
			tmpnum %= 10;
			num[i] = (tmpnum + '0');
		}
		if (pre) num += '1';
		reverse(num.begin(), num.end());
		cnt++;
	}
	cout << num<<endl<<cnt;
	return 0;
}
