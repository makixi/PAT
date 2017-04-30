#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> res;
	long long n, b;
	cin >> n >> b;
	while (n) {
		res.push_back(n%b);
		n = n / b;
	}
	int length = res.size();
	bool flag = 1;
	for (int i = 0; i < length; ++i) {
		if (res[i] != res[length - 1 - i]) flag = 0;
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	if (length == 0) cout << "0";
	if(length>=1)cout << res[length - 1];
	for (int i = length - 2; i >= 0; --i)
		cout << " " << res[i];
	return 0;
}
