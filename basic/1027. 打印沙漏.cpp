#include<iostream>
using namespace std;

int main() {
	int n,maxnum=1,i;
	char sym;
	cin >> n;
	cin >> sym;

	for (i = 3;maxnum<=n; i+=2) {
		maxnum+= i * 2;
	}
	maxnum -= (i-2) * 2;
	i -= 4;
	for (int hang = 0; hang < i; hang++) {
		for (int lie = 0; lie < i; lie++) {
			if ((hang > lie&&hang <i-1 - lie)||(hang<lie)&&(hang>i-1-lie))cout << " ";
			else cout << sym;
		}
		cout << endl;
	}
	cout << n - maxnum;
	return 0;
}
