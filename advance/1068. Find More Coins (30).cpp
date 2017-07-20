#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10010
int n; //the number of coins
int m;//money has to pay
int money[MAX];
bool flag[MAX][MAX];
int dp[MAX];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> money[i];
	sort(money+1, money +1+ n,cmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= money[i]; j--) {
			if (dp[j] <= dp[j - money[i]] + money[i]) {
				flag[i][j] = true;
				dp[j] = dp[j - money[i]] + money[i];
			}
		}
	}
	if (dp[m] != m) cout << "No Solution";
	else {
		vector<int> v;
		int temp = m,index=n;
		while (temp>0) {
			if (flag[index][temp] == true) {
				v.push_back(money[index]);
				temp -= money[index];
			}
			index--;
		}
		for (int i = 0; i < v.size(); ++i) {
			if (i != 0) cout << " ";
			cout << v[i];
		}
	}
	return 0;
}
