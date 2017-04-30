#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 0x6FFFFFFF 
int n, m, k, q;//windows capcity customer query
typedef struct node {
	int process;
	int leave;
}node;

int main() {
	//input
	cin >> n >> m >> k >> q;
	vector<node> cus(k);
	for (int i = 0; i < k; ++i) {
		cin >> cus[i].process;
		cus[i].leave = MAX;
	}
	//process
	vector<queue<int>> winQueue(n);
	vector<int> timeBase(n, 0);
	int p;
	for (p = 0; p < n*m&&p < k; ++p) {
		cus[p].leave = timeBase[p%n] + cus[p].process;
		timeBase[p%n] = cus[p].leave;
		winQueue[p%n].push(p);
	}
	//for somebody out of the normal queue
	for (; p < k; ++p) {
		int mmin = MAX;
		int index = -1;
		for (int j = 0; j < n; ++j) {
			int top = winQueue[j].front();
			if (mmin > cus[top].leave) {
				index = j;
				mmin = cus[top].leave;
			}
		}
		//pop
		cus[p].leave = timeBase[index] + cus[p].process;
		timeBase[index] = cus[p].leave;
		winQueue[index].pop();
		winQueue[index].push(p);
	}
	//query
	for (int i = 0; i < q; ++i) {
		int query;
		cin >> query;
		query--;
		if (cus[query].leave - cus[query].process >= 540)
			cout << "Sorry" << endl;
		else
			printf("%02d:%02d\n", 8 + cus[query].leave / 60, cus[query].leave % 60);
	}
	return 0;
}
