#include<iostream>
#include<string>
#include<vector>
using namespace std;
string change[10] = { "zero", "one","two","three","four","five","six","seven","eight","nine" };
int main() {
	string word;
	vector<string> result;
	getline(cin, word);
	int sum=0;
	for (int i = 0; i < word.size(); i++) {
		sum += word[i]-'0';
	}
	if (sum == 0) result.push_back(change[0]);
	while (sum) {
		int temp = sum % 10;
		result.push_back(change[temp]);
		sum /= 10;
	}
	if (result.size() > 0) cout << result[result.size() - 1];
	for (int i = result.size() - 2; i >= 0; i--)
		cout << " "<<result[i];
	return 0;
}
