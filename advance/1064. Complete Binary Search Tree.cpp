//ÊÊÓÃÓÚÂú¶ş²æÊ÷ 
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
vector<int> in, level;
void seeklevel(int start, int end, int index) {
	if (start > end) return;
	int n = end-start+1;
	int l = log(n + 1) / log(2);
	int leave = n - (pow(2, l) - 1);
	int root=start+pow(2,l-1)-1+min(pow(2,l-1),leave);
	level[index] = in[root];
	seeklevel(start, root - 1, 2 * index + 1);
	seeklevel(root+1, end, 2 * index + 2);
}
int main() {
	int n;
	cin >> n;
	in.resize(n);
	level.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> in[i];
	sort(in.begin(), in.end());
	seeklevel(0, n - 1, 0);
	cout << level[0];
	for (int i = 1; i < n; ++i)
		cout << " " << level[i];
	return 0;
}
