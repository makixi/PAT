#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int count = 0;
	string now, want;
	getline(cin, now);
	getline(cin, want);
	for (int i = 0; i < want.size(); i++) {
		int flag = 0;
		for (int j = 0; j < now.size(); j++) 
			if (want[i] == now[j]) {
				now[j] = '!';
				flag = 1;
				break;
			}
		if (flag == 0) count++;
	}
	if (count == 0) cout << "Yes "<<now.size()-want.size();
	else cout << "No " << count;
	return 0;
}

