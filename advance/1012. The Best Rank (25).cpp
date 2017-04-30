#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
struct student {
	int id;
	int bestnum;
	int score[4], rank[4];
}stu[2005];
int flag = -1;
int exist[10000000];
bool cmp(student a, student b) {
	return a.score[flag] > b.score[flag];
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
		stu[i].score[0] = round((float)(stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0);
	}
	for (flag = 0; flag <= 3; flag++) {
		sort(stu, stu + n, cmp);
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; ++i) {
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag])
				stu[i].rank[flag] = stu[i - 1].rank[flag];
		}
	}
	for (int i = 0; i < n; ++i) {
		exist[stu[i].id] = i + 1;
		stu[i].bestnum = 0;
		int minn = stu[i].rank[0];
		for (int j = 1; j <= 3; j++) {
			if (stu[i].rank[j] < minn) {
				minn = stu[i].rank[j];
				stu[i].bestnum = j;
			}
		}
	}
	char c[] = { 'A','C','M','E' };
	int id;
	for (int i = 0; i < m; i++) {
		cin >> id;
		int temp = exist[id];
		if (temp) {
			int best = stu[temp - 1].bestnum;
			cout << stu[temp - 1].rank[best] << " " << c[best]<<endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
	return 0;
}
