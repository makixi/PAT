#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n = 0;
	scanf("%d", &n);
	vector<int> val(n + 1), up(n + 1, 0), down(n + 1, 0);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 2; i <= n; i++) 
		for (int j = i - 1; j >= 1; j--) //以i为结尾的最长上升子序列长度 
			if (val[i] > val[j])up[i] = max(up[i], up[j] + 1);
	for (int i = n - 1; i >= 1; i--) 
		for (int j = i + 1; j <= n; j++) //以i为开头的最长下降子序列长度 
			if (val[i] > val[j])down[i] = max(down[i], down[j] + 1);
	int maxLen = 0, index = 0, value = 0, diff = 100000;
	for (int i = 2; i < n; i++) 
		if (up[i] && down[i]) 
			if (up[i] + down[i] + 1 > maxLen) {
				maxLen = up[i] + down[i] + 1;
				index = i;
				value = val[i];
				diff = abs(up[i] - down[i]);
			}
			else if (up[i] + down[i] + 1 == maxLen && diff > abs(up[i] - down[i])) {
				index = i;
				value = val[i];
				diff = abs(up[i] - down[i]);
			}
	if (maxLen) cout<<maxLen<<" "<<index<<" "<<value;
	else cout<<"No peak shape";
	return 0;
}
