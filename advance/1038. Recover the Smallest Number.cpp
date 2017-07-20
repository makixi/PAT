#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b) {
	return a + b < b + a;
}
string str[10010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> str[i];
	sort(str, str + n, cmp);
	string res = "";
	for (int i = 0; i < n; ++i)
		res += str[i];
	while(res.length()!=0&& res[0]=='0')
		res.erase(res.begin());
	if (res.length() == 0)//没这句的话第三个测试点过不了。。
		cout << 0 << endl;
	else cout << res << endl;
	return 0;
}
