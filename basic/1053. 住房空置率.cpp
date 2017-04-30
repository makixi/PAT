#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int N, D,K;
	double e;
	cin >> N >> e >> D;
	int empty = 0, may = 0;
	for (int i = 0; i < N; i++) {
		int count = 0;
		double temp;
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> temp;
			if (temp < e)++count;
		}
		if (K > D&&count>K/2) {
			++empty;
		}
		else if(count>K/2) {
			++may;
		}
	}
	cout << setiosflags(ios::fixed)<<setprecision(1)<<double(may)/double(N)*100 << "% " << double(empty)/double(N)*100<<"%";
	return 0;
}
