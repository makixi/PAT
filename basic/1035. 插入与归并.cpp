#include "iostream"  
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX 101
int main() {
	int n,i,j;
	cin >> n;
	int origin[MAX], temp[MAX];
	for ( i = 0; i < n; i++)cin >> origin[i];
	for ( i = 0; i < n; i++)cin >> temp[i];
	for (i = 0; temp[i] <= temp[i + 1] && i < n - 1; i++);
	for (j=++i; origin[j] == temp[j]; ++j);
	if (j == n) {
		cout << "Insertion Sort" << endl;
		sort(origin, origin + i + 1);
	}
	else {
		cout << "Merge Sort" << endl;
		int k = 1;
		int flag = 1;
		while (flag) {
			flag=0;
			for (i = 0; i < n; i++) {
				if (origin[i] != temp[i])
					flag = 1;
			}
			k *= 2;
			for (i = 0; i < n / k; i++)
				sort(origin + i*k, origin + (i + 1)*k);
			sort(origin + k*(n / k), origin + n);
		}
	}
	cout << origin[0];
	for (i = 1; i < n; i++)
		cout << " " << origin[i];
	return 0;
}
