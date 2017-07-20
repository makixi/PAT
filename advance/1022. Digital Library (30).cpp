#include<iostream>
#include<iomanip>
#include<set>
#include<map>
#include<string>
using namespace std;
map<string, set<int> > title, author, pub, key, year;

void find(map<string, set<int> > &ma, string &str) {
	if (ma.find(str) != ma.end()) {
		for (set<int>::iterator it = ma[str].begin(); it != ma[str].end(); ++it)
			cout <<setfill('0')<<setw(7)<< *it << endl;
	}
	else cout << "Not Found" << endl;
}

int main() {
	int n, m,id;
	string temptitle, tempauthor, tempkey, tempyear, temppub;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> id;
		getchar();
		getline(cin, temptitle);
		title[temptitle].insert(id);
		getline(cin, tempauthor);
		author[tempauthor].insert(id);
		while (cin >> tempkey) {
			key[tempkey].insert(id);
			if (getchar() == '\n')break;
		}
		getline(cin, temppub);
		pub[temppub].insert(id);
		getline(cin, tempyear);
		year[tempyear].insert(id);
	}
	cin >> m;
	int num; string tmp;
	for (int i = 0; i < m; ++i) {
		scanf("%d: ", &num);
		getline(cin, tmp);
		cout<<num<<": "<<tmp<<endl;
		switch (num) {
		case 1:find(title, tmp); break;
		case 2:find(author, tmp); break;
		case 3:find(key, tmp); break;
		case 4:find(pub, tmp); break;
		case 5:find(year, tmp); break;
		default:break;
		}
	}
	return 0;
}
