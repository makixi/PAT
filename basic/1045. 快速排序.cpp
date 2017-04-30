
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	int n, temp;
	vector<int> a, b, result;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	b = a;
	int max = 0;
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > max)max = a[i];
		if (a[i] == b[i] && a[i] == max)result.push_back(a[i]);
	}
	int count = result.size();
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		if (!i)cout << result[i];
		else cout << " " << result[i];
	}
	cout << endl;
	return 0;
}

