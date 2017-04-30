#include<iostream>
#include<string>
const long long int LLMAX = 0x7fffffffffffffff;
using namespace std;
int char2int(char c) {
	if (isdigit(c)) return c - '0';
	if (islower(c)) return c - 'a' + 10;
}
long long str2int(const string & str, long long radix)
{
	long long num = 0;
	for (long long i = 0; i<str.size(); i++)
	{
		num = num*radix + char2int(str[i]);
		if (num < 0)
			return LLMAX;
	}
	return num;
}
long long find_lower(string str) {
	long long max = -1;
	for (long long i = 0; i<str.size(); ++i) {
		long long t = char2int(str[i]);
		if (t>max) max = t;
	}
	return max;
}
int main() {
	string n1, n2;
	long long tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2) {
		string temp = n1;
		n1 = n2;
		n2 = temp;
	}
	if (n1 == n2 && n1 == "0") {
		cout << "1";
	}
	else {
		long long result1 = str2int(n1, radix);
		long long lower = find_lower(n2) + 1;
		long long upper = result1>lower ? result1 : lower;
		long long l = lower, r = upper;
		long long result2, mid;
		while (l<r) {
			mid = (l + r) / 2;
			result2 = str2int(n2, mid);
			if (result2<result1)l = mid + 1;
			else r = mid;
		}
		result2 = str2int(n2, r);
		if (result2 == result1) cout << r << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}
