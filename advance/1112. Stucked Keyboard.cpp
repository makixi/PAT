#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
	int k;
	string a, b;
	cin >> k; 
	cin >> a;
	set<char> bad,good,print;
	int cnt = 1;
	char pre = ' ';
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == pre)cnt++;
		else { 
			if(cnt%k!=0)
				good.insert(pre);
			cnt = 1; 
		}
		if(cnt%k==0)bad.insert(a[i]);
		pre = a[i];
	}
	for (set<char>::iterator it = good.begin(); it != good.end(); ++it) {
		if (bad.find(*it) != bad.end())bad.erase(*it);
	}
	for(int i=0;i<a.length();++i){
		if(bad.find(a[i])!=bad.end()&&print.find(a[i])==print.end()){
		cout<<a[i];
		print.insert(a[i]);
		}
	} 
	cout << endl;
	for (int i = 0; i < a.length(); ++i) {
		cout << a[i];
		if (bad.find(a[i]) != bad.end())i += k-1;
	}
	return 0;
}
