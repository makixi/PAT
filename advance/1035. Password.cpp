#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main() {
	int n; 
	int cnt = 0;
	cin >> n;
	vector<pair<string,string>> res;
	for (int i = 0; i < n; ++i) {
		int flag = 0;
		string name, pass;
		cin >> name >> pass;
		//cout << pass.length();
		for (int j = 0; j < pass.length(); ++j) {
			if (pass[j] == '1') { pass[j] = '@'; flag = 1; }
			if (pass[j] == '0') { pass[j] = '%'; flag = 1;}
			if (pass[j] == 'l') { pass[j] = 'L'; flag = 1;}
			if (pass[j] == 'O') { pass[j] = 'o'; flag = 1;}
		}
		if (flag) { cnt++; res.push_back(make_pair(name,pass)); }
	}
	if (!cnt&&n==1) {
		cout << "There is "<<n<<" account and no account is modified";
	}
	else if (!cnt) {
		cout << "There are " << n << " accounts and no account is modified";
	}
	else {
		cout << cnt << endl;
		vector<pair<string, string>>::iterator iter;
		for (iter = res.begin(); iter != res.end(); iter++) {
			cout << iter->first << " " << iter->second << endl;
		}
	}
	return 0;
}
