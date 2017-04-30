#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
vector<int> Relative[MAX];
int LeafEachLevel[MAX];
int MaxLevel = -1;
void FindDeep(int node,int deep) {
	if (Relative[node].size() == 0) {
		++LeafEachLevel[deep];
		MaxLevel = max(MaxLevel, deep);
		return;
	}
	else {
		for (int i = 0; i < Relative[node].size(); i++)
			FindDeep(Relative[node][i], deep+1);
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int myid, k;
		cin >> myid >> k;
		for (int j = 0; j < k; j++) {
			int id;
			cin >> id;
			Relative[myid].push_back(id);
		}
	}
	FindDeep(1, 0);
	//if (MaxLevel >= 0) 
		cout << LeafEachLevel[0];
	for (int i = 1; i <= MaxLevel; i++)
		cout << " " << LeafEachLevel[i];
	return 0;
}
