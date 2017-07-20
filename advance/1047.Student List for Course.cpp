#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;//student and course
char name[40010][5];
vector<int> course[2501];
bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}
int main() {
	int c,tmpc;
	string tmp;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		scanf("%s %d", name[i], &c);
		while (c--) {
			scanf("%d", &tmpc);
			course[tmpc].push_back(i);
		}
	}
	for (int i = 1; i <= k; ++i) {
		sort(course[i].begin(), course[i].end(),cmp);
		printf("%d %d\n", i, course[i].size());
		for (int j = 0; j < course[i].size(); ++j) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}
