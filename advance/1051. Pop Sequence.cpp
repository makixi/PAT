#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int M;  
int N;  
int K;  
bool Check_Seq(vector<int> &v)
{
	int i = 0;
	int num = 1;
	int cap = M + 1;
	stack<int> sta;
	sta.push(0);
	while (i < N) {
		while (sta.size() < cap && v[i] > sta.top()) {
			sta.push(num++);
		}
		if (v[i++] == sta.top()) {
			sta.pop();
		}
		else {
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> M >> N >> K;
	vector<int> seq;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			seq.push_back(tmp);
		}
		if (Check_Seq(seq)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		seq.clear();
	}

	return 0;
}
