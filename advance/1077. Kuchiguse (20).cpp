#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n,j;
	cin >> n;
	string curr, pre;
	getchar();
	getline(cin, pre);
	reverse(pre.begin(), pre.end());
	for (int i = 0; i < n-1; ++i) {
		getline(cin, curr);
		reverse(curr.begin(), curr.end());
		for (j = 0; j < (curr.length() <= pre.length()) ? curr.length() : pre.length(); ++j) {
			if (pre[j] != curr[j])break;
		}
		pre = pre.substr(0, j);
	}
	if (pre.length()) { reverse(pre.begin(),pre.end()); cout << pre; }
	else cout << "nai";
	return 0;
}
