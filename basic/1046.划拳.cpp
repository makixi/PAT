#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	int n;
	int count1 = 0, count2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int han1, hua1;
		int han2, hua2;
		cin >> han1 >> hua1 >> han2 >> hua2;
		if (han1 + han2 == hua1&&han1+han2!=hua2)count2++;
		if (han1 + han2 == hua2&&han1+han2!=hua1)count1++;
	}
	cout << count1 << " " << count2;
	return 0;
}
