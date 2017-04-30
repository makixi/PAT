#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
struct Node {
	char name[11];
	char id[11];
	int grade;
};
vector<Node> stu;
bool cmp(Node a, Node b) {
	return a.grade > b.grade;
}
int main() {
	int low, high;
	cin >> n;
	Node *node = (Node*)malloc(sizeof(Node)*n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", node[i].name);
		scanf("%s %d", node[i].id,&node[i].grade);
	}
	cin >> low >> high;
	for (int i = 0; i < n; ++i) {
		if (node[i].grade >= low&&node[i].grade <= high)
			stu.push_back(node[i]);
	}
	sort(stu.begin(), stu.end(), cmp);
	if (stu.size() == 0) cout << "NONE" << endl;
	else {
		for (int i = 0; i < stu.size(); ++i) {
			cout << stu[i].name << " " << stu[i].id << endl;
		}
	}
	return 0;
}
