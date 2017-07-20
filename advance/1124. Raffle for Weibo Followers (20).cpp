#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	int m, n, s;
	bool flag = 0;
	string tmp;
	map<string, int> ma;
	cin >> m >> n >> s;//total number of forwards, the skip number of winner, the index of the first winner
	for (int i = 1; i <= m; ++i) {
		//getline(cin, tmp);
		cin>>tmp;
		if (ma[tmp]==1) {
			s += 1;
		}
		if (i==s&&ma[tmp]==0) {
			ma[tmp]=1;
			cout << tmp<< endl;
			flag = 1;
			s+=n; 
		}
	}
	if (!flag)cout << "Keep going..." << endl;
	return 0;
}
