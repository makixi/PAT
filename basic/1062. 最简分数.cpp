#include<iostream>
#include<stdlib.h>
using namespace std;

bool judge(int a, int b) {
	if(a==1||b==1) return 1;
	for (int i = 2; i <= a; i++)
		if (b%i == 0 && a%i == 0) return 0;
	return 1;
}
int main() {
	int n1, n2, m1, m2, k,count=0;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	double temp1, temp2;
	temp1 = double(n1*k) / m1; temp2 = double(n2*k) / m2;
	if(temp1>temp2) swap(temp1,temp2);
	for (int i = temp1 + 1; i < temp2; i++) {
		if (judge(i, k)) { 
			if(count==0) cout<< i << "/" << k;
			else
			cout <<" "<< i << "/" << k ; 
			++count;
		}
	}
	return 0;
}
