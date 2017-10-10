#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	string temp;
	map<string, int> award;
	int m, n, s,flag=0;
	cin >> m >> n >> s;
	getchar();
	for (int i = 1; i <= m; i++) {
		getline(cin, temp);
		if(award[temp]==1) ++s;
		if(i==s&&award[temp]==0){
			award[temp]=1;
			cout<<temp<<endl;
			flag=1;
			s+=n;
		}
	}
	if (!flag) cout << "Keep going...";
	return 0;
}
