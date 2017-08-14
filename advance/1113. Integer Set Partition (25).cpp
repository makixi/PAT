#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100001;
int val[maxn];
int main() {
	int n,n1,n2,sum=0,tmp=0;
	cin >> n;
	n1 = n / 2; n2 = n - n1;
	for (int i = 0; i < n; ++i) { cin >> val[i]; sum += val[i]; }
	sort(val, val + n);
	for (int i = 0; i < n1; ++i)tmp += val[i];
	cout << n2 - n1 << " "<<sum-2*tmp;
	return 0;
}
