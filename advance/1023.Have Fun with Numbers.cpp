#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char num[22];
	int book[10];
	fill(book, book + 10, 0);
	scanf("%s", num);
	int pre = 0;
	for (int i = strlen(num) - 1; i >= 0; --i) {
		int cur = num[i] - '0';
		book[cur]++;
		cur = cur * 2 + pre;
		pre = cur / 10;
		cur %= 10;
		num[i] = (cur + '0');
		book[cur]--;
	}
	int flag = 1;
	for (int i = 0; i < 10; ++i)
		if (book[i] != 0)flag = 0;
	if (flag == 0 || pre == 1)cout << "No" << endl;
	else cout << "Yes" << endl;
	if (pre)cout << "1";
	for (int i = 0; i < strlen(num); ++i)
		cout << num[i];
	return 0;
}
