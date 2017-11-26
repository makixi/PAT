#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n,num,cnt=0,ans=0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> num;
		v[num] =i;
		if (num!=i&&num!=0)cnt++;
	}
	int i = 1;
	while (cnt) {
		if (v[0] == 0) {
			while(i<n) {
				if (v[i] != i){
					swap(v[i], v[0]);
					ans++;
					break;
				}
				i++;
			}
		}
		else {
			swap(v[v[0]], v[0]);
			cnt--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

