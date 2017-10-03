#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	int M, m, p, N, temp;
	vector<ll> num;
	cin >> N >> p;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	int max = 0;
	int index = 0;
	for (int i = 0; i < num.size(); i++){
		for (int j = i + max; j < num.size(); j++) 
			if (p*num[i] < num[j]) {
				index = j - i; break;
			}
			else if (j == N - 1) 
				index = j - i + 1;
		if (max < index)max = index;
	}
	cout << max;
	return 0;
}
