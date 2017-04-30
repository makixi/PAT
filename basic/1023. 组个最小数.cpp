#include<iostream>
using namespace std;
int main() {
	int count[10];
	for(int i = 0; i < 10; i++)
		cin >> count[i];
	for(int i = 1; i < 10; i++)
		if(count[i]) {
			cout << i;
			count[i]--;
			break;
		}
	for(int i = 0; i < 10; i++)
	while(count[i]--)
	cout << i;
	return 0;
}

