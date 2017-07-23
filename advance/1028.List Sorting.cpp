#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, c;
const int maxnum = 100001;
struct node {
	int id;
	char name[10];
	int grade;
};
node stu[maxnum];
bool cmp(node a,node b) {
	if (c == 1)
		return a.id < b.id;
	if (c == 2)
		return strcmp(a.name, b.name) <= 0;
	return a.grade <= b.grade;
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].grade);
	sort(stu, stu+n, cmp);
	for (int i = 0; i < n; ++i)
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	return 0;
}
