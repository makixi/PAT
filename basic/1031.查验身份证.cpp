#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	int z[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char m[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	cin >> n;
	vector<string> err;
	string id;
	for (int i = 0; i < n; i++) {
		int flag = 0,znum=0;
		cin >> id;
		for (int j = 0; j < 17; j++) {
			if (id[j]<'0' || id[j]>'9') flag = 1;
			znum += (id[j]-'0') * z[j];
		}
		znum = znum % 11;
		if (id[17] != m[znum]||flag==1) 
			 err.push_back(id);  
	}
	if (err.size() == 0)cout << "All passed";
	else {
		for (int i = 0; i < err.size(); i++){
			cout << err[i] ;
			if (i != err.size() - 1) cout << endl;
		}
	}
	return 0;
}
