#include<iostream>
#include<string>
using namespace std;
int main() {
	int n,ade=0;
	cin >> n;
	string name,oldname="",youngname="";
	string begin = "1814/09/05";
	string end = "2014/09/07";
	string age,oldage=begin,youngage=end;
	for (int i = 0; i < n; i++) {
		cin >> name >> age;
		if (age > begin&&age < end) {
			++ade;
			if (age > oldage) {
				oldage = age;
				oldname = name;
			}
			if (age < youngage) {
				youngage = age;
				youngname = name;
			}
		}
	}
	if (ade > 0) 
		cout << ade << " " << youngname << " " << oldname;
	else cout << "0";
	return 0;
}
