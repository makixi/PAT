#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10000
int main() {
	string str;
	int find = 0;
	getline(cin, str);
	vector<char> temp;
	for (int i = 0; i < str.size(); i++) 
		if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't') {
			temp.push_back(str[i]);
		}
	int length = temp.size();
	while (length) {
		if (find == 0){
			for (int i = 0; i < temp.size(); i++)
				if (temp[i] == 'P'){
					temp[i] = '0';
					cout << "P";
					length--;
					break;
				}
			find++;
		}
		if (find == 1){
			for (int i = 0; i < temp.size(); i++)
				if (temp[i] == 'A'){
					temp[i] = '0';
					cout << "A";
					length--;
					break;
				}
			find++;
		}
		if (find == 2){
			for (int i = 0; i < temp.size(); i++)
				if (temp[i] == 'T'){
					temp[i] = '0';
					cout << "T";
					length--;
					break;
				}
			find++;
		}
		if (find == 3){
			for (int i = 0; i < temp.size(); i++)
				if (temp[i] == 'e'){
					temp[i] = '0';
					cout << "e";
					length--;
					break;
				}
			find++;
		}
		if (find == 4){
			for (int i = 0; i < temp.size(); i++)
				if (temp[i] == 's'){
					temp[i] = '0';
					cout << "s";
					length--;
					break;
				}
			find++;
		}
		if (find == 5){
			for (int i = 0; i < temp.size(); i++)
				if (temp[i] == 't'){
					temp[i] = '0';
					cout << "t";
					length--;
					break;
				}
			find=0;
		}
	}
	return 0;
}
