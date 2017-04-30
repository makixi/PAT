#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define right 1
#define down 2
#define left 3
#define up 4
int main() {
	int N,temp,m,n;
	vector<int> num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	m = sqrt(N);
	n = m;
	while (m*n != N) {
		m++;
		if (m*n > N) {
			n--;
		}
	}
	int **a;
	a = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
		a[i] = (int*)malloc(sizeof(int)*n);
	int count = N,cal=0,direction=right;
	while (count) {
		if (direction == right) {
			for (int i = cal; i < n-cal; i++) {
				if (count <= 0)break;
				a[cal][i] = num[count - 1];
				--count;
			}
			direction = down;
		}
		else if (direction == down) {
			for (int i = cal+1; i < m - cal; i++) {
				if (count <= 0)break;
				a[i][n-cal-1] = num[count - 1];
				--count;
			}
			direction = left;
		}
		else if (direction == left) {
			for (int i = n-2-cal ; i >=cal; i--) {
				if (count <=0)break;
				a[m-cal-1][i] = num[count - 1];
				--count;
			}
			direction = up;
		}
		else if (direction == up) {
			for (int i =m-2-cal; i >=cal+1; i--) {
				if (count <=0)break;
				a[i][cal] = num[count - 1];
				--count;
			}
			direction = right;
			++cal;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] ;
			if(j!=n-1) cout<<" ";
		}
		if(i!=m-1)cout << endl;
	}
	return 0;
}
