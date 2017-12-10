#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	string str,tmp="";
	getline(cin, str);
	map<string,int> m;
	for (int i = 0; i < str.length(); ++i) 
		if (isalnum(str[i])) {
			str[i] = tolower(str[i]);
			tmp += str[i];
		}
		else {
			if(!tmp.empty())m[tmp]++;
			tmp = "";
		}
	if (!tmp.empty())m[tmp]++;
	int max = 0;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) 
		if (it->second > max) {
			max = it->second;
			tmp = it->first;
		}
	cout << tmp << " " << max << endl;
	return 0;
}
