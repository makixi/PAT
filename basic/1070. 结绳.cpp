#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	float *a;
	cin >> n;
	a = (float *)malloc(n * sizeof(float *));
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	float temp;
	if(n>=2)
	 temp = (a[0] + a[1]) / 2.0;
	for (int i = 2; i < n; i++) {
		temp = (temp + a[i]) / 2.0;
	}
	cout << floor(temp);
	return 0;
}
