#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	int n=0,count1=0,count0=0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) 
		if (isalpha(str[i])) 
			if (isupper(str[i]))n+=str[i]-'A'+1;
			else n += str[i] - 'a'+1;
	while (n) {
		if (n % 2)++count1;
		else ++count0;
		n /= 2;
	}
	printf("%d %d", count0, count1);
	return 0;
}
