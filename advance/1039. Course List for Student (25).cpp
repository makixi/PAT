//-------------------------------���һ�����Ե㳬ʱ 
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int n;//ѧ������
int k;//�γ�����
int main() {
	string stu;
	int index,num;
	cin >> n >> k;
	map<string, set<int>> ma;
	for (int i = 0; i < k; ++i) {
		cin >> index>>num;
		for (int j = 0; j < num; ++j) {
			cin >> stu;
			ma[stu].insert(index);
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> stu;
		cout << stu;
		cout << " " << ma[stu].size();
		if (ma.find(stu) != ma.end()) {
			for (set<int>::iterator it = ma[stu].begin(); it != ma[stu].end(); ++it)
				cout << " " << *it;
		}
		cout << endl;
	}
	return 0;
}
