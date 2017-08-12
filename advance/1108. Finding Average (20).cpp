#include<iostream>
#include<cstring> 
using namespace std;
void printError(string str) {
	printf("ERROR: ");
	cout << str;
	printf(" is not a legal number\n");
}
int main() {
	int n, cnt = 0;
	double sum = 0,tmp;
	char a[50], b[50];
	cin >> n;
	while (n--) {
		bool flag = true;
		int dotnum = 0;
		scanf("%s", a);
		sscanf(a, "%lf", &tmp);
		sprintf(b, "%.2lf", tmp);
		for (int j = 0; j < strlen(a);++j) {
			if (a[j] != b[j]) { flag = false; break; }
		}
		if (!flag||tmp < -1000 || tmp>1000) 
		{ printf("ERROR: %s is not a legal number\n", a); continue; }
		sum += tmp;
		cnt++;
	}
	if(cnt==1)printf("The average of 1 number is %.2lf", sum);
	else {
		printf("The average of %d numbers is ", cnt);
		if (!cnt)printf("Undefined");
		else printf("%.2lf", sum / cnt);
	}
	return 0;
}
