#include<iostream>
#include<string>
using namespace std;
#define MAX 1010
bool flag[MAX][MAX];//flag[i][j]标识从i到j是否对称
int main() {
	int max = 1,len;
	string str;
	getline(cin, str);
	len = str.length();
	for (int i = 0; i < len; ++i) {
		flag[i][i] = 1;
		if (i < len - 1 && str[i] == str[i + 1]) {
			max = 2;
			flag[i][i + 1] = 1;
		}
	}
	for (int L = 3; L <= len; L++) {
		for (int i = 0; i + L - 1 < len; ++i) {
			int j = i + L - 1;
			if (str[i] == str[j] && flag[i + 1][j - 1] == 1) {
				flag[i][j] = 1;
				max = L;
			}
		}
	}
	cout << max;
	return 0;
}
