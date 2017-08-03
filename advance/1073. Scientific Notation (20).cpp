#include<iostream>
#include<string>
using namespace std;
int main() {
	bool negative = false;
	int point;	//Location of decimal point
	int index=0,i;
	string str;
	cin >> str;
	for (point= 0; str[point] != '.'&&str[point]!='E'; ++point);
	for (i = point; str[i]!='E'; ++i);
	if (str[i + 1] == '-')negative = true;
	for (i = i + 2; i < str.length(); ++i) 
		index = index * 10 + str[i] - '0';
	if (negative)index = -index;
	for (i = 0; str[i] != 'E'; ++i);
	str.erase(i, str.length() - i);
	if (index < 0) {
		while (index + point <= 1) {
			str.insert(1, 1, '0');
			point++;
		}
		point += index;
		for (i = point-index-1; i >=point; --i)str[i+1] = str[i];
		str[point] = '.';
	}
	else {
		for (i = str.length()-point-1; i < index; ++i) 
			str.insert(str.length(), 1, '0');
		for (i = point; i < point+index; ++i)str[i] = str[i + 1];
		str[i] = '.';
		if (i == str.length() - 1)str.erase(i, 1);
	}
	if (str[0] == '+')str.erase(0, 1);
	cout << str;
	return 0;
}
