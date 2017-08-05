#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string a, b, res = "";
	getline(cin, a);
	getline(cin, b);
	for (int i = 0, j = 0; i<a.length() && j<b.length();)
		if (a[i] != b[j]) {
			if (res.find(toupper(a[i])) == string::npos)
				res += toupper(a[i]);
			++i;
		}
		else {
			++i; ++j;
		}
	cout << res << endl;
	return 0;
}
