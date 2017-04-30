#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 100005
int main() {
	int n, k;
	int res[MAX], add[MAX],next[MAX],list[MAX],first,temp;
	cin >> first>>n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		cin >> add[temp] >> next[temp];
	}
	int cnt = 0;
	while (first != -1) {
		list[cnt++] = first;
		first = next[first];
	}
	for (int i = 0; i < cnt; ++i) {
		if (i < (cnt - cnt % k)) {
			res[i] = list[i / k * k + k - 1 - i % k];
		}
		else {
			res[i] = list[i];
		}
	}
	for (int i = 0; i < cnt; ++i) {
		if (i == n - 1) {
			cout << setw(5) << setfill('0') << res[i];
			cout << " " << add[res[i]] << " ";
			cout << "-1";
			break;
		}
		cout << setw(5) << setfill('0') << res[i];
		cout << " " << add[res[i]]<<" ";
		cout << setw(5) << setfill('0') << res[i+1];
		cout << endl;
	}
}
