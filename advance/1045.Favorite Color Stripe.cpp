#include<iostream>
#include<algorithm>
using namespace std;
#define COLORNUM 201
#define MAXNUM 10010
int color[COLORNUM];
int origin[MAXNUM],d[MAXNUM];
int main() {
	int n, m, l, tmp, maxlength = 0, num = 0;
	cin >> n >> m;
	fill(color, color + COLORNUM, 0);
	fill(d, d + MAXNUM, 0);
	for (int i = 1; i <= m; ++i) {
		cin >> tmp;
		color[tmp] = i;//出现并记录其重要地位
	}
	cin >> l;
	for (int i = 0; i < l; ++i) {
		cin >> tmp;
		if (color[tmp] >= 1)
			origin[num++] = color[tmp];
	}
	for (int i = 0; i < num; ++i) {
		d[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (origin[i] >= origin[j])
				d[i] = max(d[i], d[j] + 1);
		}
		maxlength = max(maxlength, d[i]);
	}
	cout << maxlength;
	return 0;
}
