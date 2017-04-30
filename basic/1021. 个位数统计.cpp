#include <iostream>
#include<string>
using namespace std;
#define MAX 1000
int a[MAX];
int main()
{
	int countall = 0;
	string str;
	cin >> str;
	int length=str.length();
	for (int i = 0; i < length; i++) {
		a[i] = str[i]-'0';
	}
	for (int num = 0; num <=9; num++) {
		int count = 0;
		for (int j = 0; j < length; j++) 
		{
			if (num == a[j]) count++;
		}
		if (count != 0)
		{
			if (countall != 0) cout << endl;
			cout << num<< ":" << count;
			countall++;
		}
	}
	return 0;
}

