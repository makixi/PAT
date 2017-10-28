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
	for (;first != -1;first=next[first])
		list[cnt++] = first;
	for (int i = 0; i < cnt; ++i)
		res[i] = list[i];
	for (int i = 0; i < (cnt - cnt % k); ++i)
		res[i] = list[i / k * k + k - 1 - i % k];
	for (int i = 0; i < cnt; ++i) {
		if (i == cnt - 1) {
			printf("%05d %d -1",res[i],add[res[i]]);
			break;
		}
		printf("%05d %d %05d\n",res[i],add[res[i]],res[i+1]);
	}
	return 0;
}
