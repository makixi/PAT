#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1, s2,s="";
	getline(cin, s1);
	getline(cin, s2);
	for (auto c : s1) 
		if (s2.find(c) == string::npos)
			s += c;
	cout << s << endl;
	return 0;
}
