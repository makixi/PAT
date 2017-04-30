#include<iostream>
#include<string>

using namespace std;


int main() {
	string bad,dream;
	string reality;
	getline(cin, bad);
	getline(cin, dream);
	int i = 0,j=0;
	int flag = 0;
	for (int j = 0; j < dream.size(); j++) {
			for (int i = 0; i < bad.size(); i++) {
				if (bad[i] == '+') flag = 1;
			if ((dream[j] == bad[i]) || (flag == 1 && isupper(dream[j]))||(toupper(dream[j])==bad[i])) 
			{
				dream[j] = ' ';
			}
		}
			if (dream[j] != ' ') cout << dream[j];
	}

	return 0;
}
