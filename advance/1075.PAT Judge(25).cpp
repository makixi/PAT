#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;//users id1toN
int k;//problem id1tok
int m;//submission
struct node {
	int id,total=0;
	vector<int> score;
	int rank;
	int passnum = 0;
	bool show=false;
};
bool cmp(node a, node b) {
	if (a.total != b.total)
		return a.total > b.total;
	else if (a.passnum != b.passnum)
		return a.passnum > b.passnum;
	else return a.id < b.id;
}
int main(){
	int id, num, score;
	cin >> n >> k >> m;
	vector<node> pat(n+1);
	vector<int> p(k+1);
	for (int i = 1; i <= n; ++i) {
		pat[i].score.resize(k + 1,-1);
	}
	for (int i = 1; i <= k; ++i)
		cin >> p[i];//full mark
	for (int i = 0; i < m; ++i) {
		cin >> id >> num >> score;
		pat[id].id = id;
		pat[id].score[num] = max(score, pat[id].score[num]);
		if (score != -1) pat[id].show = true;
		else if (pat[id].score[num] == -1)
			pat[id].score[num] = -2;
	}
	for (int i = 1; i <= n; ++i) {
		for(int j=1;j<=k;++j){
			if (pat[i].score[j] != -1&&pat[i].score[j]!=-2) {
				pat[i].total += pat[i].score[j];
			}
			if (pat[i].score[j] == p[j])pat[i].passnum++;
		}
	}
	sort(pat.begin()+1, pat.end(), cmp);
	//pat[1].rank = 1;
	for (int i = 1; i <= n; ++i) {
		pat[i].rank=i;
		if (i!=-1&&pat[i].total == pat[i - 1].total)
			pat[i].rank = pat[i - 1].rank;
	}
	for (int i = 1; i <= n; ++i) {
		if (pat[i].show == true) {
			printf("%d %05d %d", pat[i].rank, pat[i].id, pat[i].total);
			for (int j = 1; j <= k; ++j) {
				if (pat[i].score[j] != -1 && pat[i].score[j] != -2)
					cout << " " << pat[i].score[j];
				else if (pat[i].score[j] == -1)
					cout << " -";
				else cout << " 0";
			}
			cout << endl;
		}
	}
	return 0;
}
