#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
	int n;
	double pu=0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; double temp;
		cin >> a >> b;
		temp = sqrt(a*a + b*b);
		if (temp > pu) pu = temp;
	}
	cin>>pu;
		printf("%.2f", pu );
	return 0;
}
