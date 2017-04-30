#include<iostream>
#include<string>
using namespace std;

int main() {
	string str,temp;
	int n,flag=0,i=0;
	cin >> str ;
	cin >> n;
	getchar();
	while (++i) {
		getline(cin, temp);
		if (temp == "#") break;
		else if(i<=n&&temp==str ) { cout << "Welcome in" << endl; break; }
		else if(temp!=str&&i<=n)cout << "Wrong password: " << temp << endl; 
		if(i==n) 
			cout << "Account locked" << endl;
	}
	return 0;
}
