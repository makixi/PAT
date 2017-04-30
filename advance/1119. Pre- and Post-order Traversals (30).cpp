#include<iostream>
#include<vector>
using namespace std;
int n;
bool flag = 1;
vector<int> pre, post,in;

int FindLast(int start,int end,int value) {
	for (int i = start; i <= end; ++i) {
		if (pre[i] == value) return i;
	}
	return -1;
}

void In(int prel, int prer, int postl, int postr) {
	if (prel == prer) {
		in.push_back(pre[prer]);
		return;
	}
	else {
		if (pre[prel] == post[postr]) {
			int x = FindLast(prel+1, prer, post[postr - 1]);
			if (x - prel > 1) {
				In(prel + 1, x - 1, postl, postl + x - 2 - prel);
				in.push_back(post[postr]);
				In(x, prer, postl + x - 1 - prel, postr - 1);
			}
			else {
				flag = 0;
				in.push_back(post[postr]);
				In(x, prer, postl - prel + x - 1, postr - 1);
			}
		}
	}
}

int main() {
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for (int i = 0; i < n; ++i)cin >> pre[i];
	for (int i = 0; i < n; ++i)cin >> post[i];
	In(0,n-1,0,n-1);
	if (flag == 0) cout << "No" << endl;
	else cout << "Yes" << endl;
	cout << in[0];
	for (int i = 1; i < in.size(); ++i)
		cout << " " << in[i];
	cout<<endl;
	return 0;
}
