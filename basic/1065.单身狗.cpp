#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
#define MAX 100000
int main() {
	int n, m;
	vector<int> dog;
	cin >> n;
	int a[MAX];
	for (int i = 0; i<MAX; i++)a[i] = -1;
	int *all;
	for (int i = 0; i < n; i++){
		int num;
		cin >> num;
		cin >> a[num];
		a[a[num]] = num;
	}
	cin >> m;
	all = (int *)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)cin >> all[i];
	for (int i = 0; i < m; i++){
		if (a[all[i]] == -1) dog.push_back(all[i]);
		else {
			int flag = 0;
			for (int j = 0; j < m; j++) 
				if (all[i] == a[all[j]]) {
					flag = 1; break;
				}
			if (flag == 0) dog.push_back(all[i]);
		}
	}
	sort(dog.begin(), dog.end());
	cout << dog.size() << endl;
	vector<int>::iterator iter;
	for (iter = dog.begin(); iter != dog.end(); iter++){
		cout << setfill('0')<<setw(5)<<*iter;
		if (iter != dog.end() - 1)cout << " ";
	}
	return 0;
}
