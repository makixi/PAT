#include<iostream>
#include<string>
using namespace std;
int main() {
	string dream, reality;
	string bad;
	getline(cin, dream);
	getline(cin, reality);
	int i = 0,j=0;
	while (dream[i]) {
		int flag = 0;
		dream[i]=toupper(dream[i]);
		reality[j] = toupper(reality[j]);
		if (dream[i] != reality[j]) {
			for (int k = 0; k < bad.size(); k++) {
				if (bad[k] == dream[i]) flag = 1;
			}
			if(flag==0)bad.push_back(dream[i]);
			i++;
		}
		else {
			++i; ++j;
		}
	}
	cout << bad;
	return 0;
}
