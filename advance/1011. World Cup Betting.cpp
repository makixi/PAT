#include<iostream>
using namespace std;
char ch[] = { 'W','T','L' };
int main() {
	float num,sum=1.0;
	for (int j = 0; j < 3; ++j) {
		int pos;
		float maxnum = 0.0;
		for (int i = 0; i < 3; ++i) {
			cin >> num;
			if (num > maxnum) { maxnum = num; pos = i; }
		}
		cout << ch[pos]<<" ";
		sum *= maxnum;
	}
	printf("%.2f", (sum*0.65 - 1.0)*2.0);
	return 0;
}
