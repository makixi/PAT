#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> post, in;
vector<int> ceng(100000,-1);
void seeklevel(int root,int start, int end,int index) {
	if (start > end) return;
	int j=start;
	while (j < end&&in[j] != post[root]) j++;
	ceng[index] = post[root]; 
	seeklevel(root-1-end+j,start, j -1,2*index+1);
	seeklevel(root-1, j+1,end,2*index+2);
}
int main() {
	cin >> n;
	int cnt = 0;
	post.resize(n);
	in.resize(n);
	for (int i = 0; i < n; ++i) cin >> post[i];
	for (int i = 0; i < n; ++i) cin >> in[i];
	seeklevel(n-1,0,n-1,0);
	for (int i = 0; i < ceng.size(); i++) {
		if (ceng[i] != -1 && cnt != n - 1) {
			cout << ceng[i]<<" "; cnt++;
		}
		else if(ceng[i]!=-1)
		 cout <<ceng[i];
	}
	return 0;
}
