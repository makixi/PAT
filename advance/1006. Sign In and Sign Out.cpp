#include<iostream>
#include<string>
using namespace std;

int main() {
  int M;
  cin >> M;
  string unlocktime="24:00:00", lockedtime="00:00:00";
  string unlockname, lockedname;
  for (int i = 0; i < M; i++) {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    if (str2 < unlocktime) { unlocktime = str2; unlockname = str1; }
    if (str3 > lockedtime) { lockedname = str1; lockedtime = str3; }
  }
  cout << unlockname << " " << lockedname;
  return 0;
}
