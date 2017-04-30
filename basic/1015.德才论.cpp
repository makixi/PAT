#include<iostream>
#include<string>
#include<vector>
#include <algorithm>  
using namespace std;
#define CDQJ 1
#define DSC 2
#define CDJW 3
#define QT 4
#define WLQ 5
 typedef struct student{
	string id;
	int de;
	int cai; 
	int sum;
	int type;
 }stu;
 bool compare(stu a, stu b) {
	 if (a.type < b.type) return true;
	 else if (a.type == b.type) {
		 if (a.sum > b.sum) return true;
		 else if (a.sum == b.sum&&a.de > b.de) return true;
		 else if (a.sum == b.sum&&a.de == b.de&&a.id < b.id)
			 return true;
	 }
	 return false;
}
int main()
{
	int N, L, H;
	int i, j;
	int count=0;
	stu student;
	vector<stu> list;
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++) {
		cin >> student.id >> student.de >> student.cai;
		student.sum = student.de + student.cai;
		if ((student.de < L) || (student.cai < L))
			student.type = WLQ;
		else if (student.de >= H&&student.cai >= H)
			student.type = CDQJ;
		else if (student.de >= H && student.cai<H)
			student.type = DSC;
		else if (student.de<H && student.cai<H && student.de >= student.cai)
			student.type = CDJW;
		else
			student.type = QT;
		list.push_back(student);
		if (student.type != WLQ) count++;
	}
	sort(list.begin(), list.end(), compare);
	cout << count << endl;

	vector<stu>::iterator iter;
	for ( iter = list.begin(); iter != list.end(); iter++)
		if (iter->type != WLQ)
			cout << iter->id << " " << iter->de << " " << iter->cai << endl;
	return 0;
}
