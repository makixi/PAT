#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main() {
	string huo1[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string huo2[13] = { "tam","hel","maa","huh","tou","kes","hel","elo","syy","lok","mer","jou" };
	int n,number=0;
	string temphuo = "";
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string str,temp;
		getline(cin, str);
		//int number = 0;
		if (isalpha(str[0])) {
			for (int j = 0; j < str.size(); j=j+4) {
				temphuo = temphuo + str[j] + str[j + 1] + str[j + 2];
				for (int k = 0; k < 13; k++) {
					if (temphuo == huo1[k])number = number + k;
					if (temphuo == huo2[k])number = number + (k + 1) * 13;
				}
				temphuo = "";
			}
			cout << number<<endl;
		}
		else {
			int tempnum=0;
			for (int j = 0; j < str.size(); j++) {
				tempnum = tempnum*10+str[j] - '0';
			}
			if (tempnum < 13) {
				cout << huo1[tempnum] << endl;
			}
			else {
				if ((tempnum % 13 == 0)) cout << huo1[tempnum / 13 - 1] << endl;
				else
					cout << huo2[tempnum / 13 - 1] << " " << huo1[tempnum % 13]<<endl;
			}
		}
		number = 0;
	}
	return 0;
}
