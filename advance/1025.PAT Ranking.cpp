#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	long long id;
	int score;
	int location;
	int rank;
	int lrank;
};
bool cmp(node a, node b) {
	if (a.score != b.score)
		return a.score > b.score;
	return a.id < b.id;
}
int main() {
	int n, k;
	cin >> n;
	vector<node> res;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		vector<node> vec(k);
		for (int j = 0; j < k; ++j) {
			cin >> vec[j].id >> vec[j].score;
			vec[j].location = i;
		}
		sort(vec.begin(), vec.end(), cmp);
		vec[0].lrank = 1;
		res.push_back(vec[0]);
		for (int j = 1; j < k; ++j) {
			vec[j].lrank = (vec[j].score == vec[j - 1].score) ? (vec[j - 1].lrank) : (j + 1);
			res.push_back(vec[j]);
		}
	}
	sort(res.begin(), res.end(), cmp);
	res[0].rank = 1;
	for (int j = 1; j < res.size(); ++j)
		res[j].rank = (res[j].score == res[j - 1].score) ? (res[j - 1].rank) : (j + 1);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
		printf("%013lld %d %d %d\n", res[i].id, res[i].rank, res[i].location, res[i].lrank);
	return 0;
}
