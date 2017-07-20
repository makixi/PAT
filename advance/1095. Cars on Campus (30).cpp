#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
int n;//records
int k;//query
struct Node {
	char id[10];
	int time;
	int status=0;
};
bool cmp(Node a, Node b) {
	if (strcmp(a.id , b.id)!=0) return strcmp(a.id,b.id)<0;
	return a.time < b.time;
}
bool cmp2(Node a, Node b) {
	return a.time < b.time;
}
int main() {
	int i,j,hour,minute,second;
	char flag[5];
	cin >> n >> k;
	vector<Node> node(n);
	for (i = 0; i < n; ++i) {
		cin >> node[i].id;
		scanf("%d:%d:%d", &hour, &minute, &second);
		cin >> flag;
		if (strcmp(flag,"in")==0)node[i].status = 1;
		else  node[i].status = -1;
		node[i].time= second + minute * 60 + hour * 3600;
	}
	sort(node.begin(), node.end(), cmp);
	map<string, int> ma;
	vector<Node> car;
	int max = 0;
	for (i = 0; i < n-1; ++i) {
		if (strcmp(node[i].id,node[i + 1].id)==0&&node[i].status == 1 && node[i + 1].status == -1) {
			car.push_back(node[i]);
			car.push_back(node[i + 1]);
			ma[node[i].id] += (node[i + 1].time - node[i].time);
			if (ma[node[i].id] > max) {
				max = ma[node[i].id];
			}
		}
	}
	sort(car.begin(), car.end(), cmp2);
	int h, m, s,ttime;
	vector<int> cnt(n);
	for (i = 0; i < car.size(); ++i) {
		if (i == 0)cnt[i] = car[i].status;
		else cnt[i] = cnt[i - 1] + car[i].status;
	}
	int tmpindex = 0;
	for (i = 0; i < k; ++i) {
		scanf("%d:%d:%d", &h, &m, &s);
		ttime = h * 3600 + s + m * 60;
		j = tmpindex;
		for (; j < car.size(); ++j) {
			if (car[j].time > ttime) {
				cout << cnt[j - 1] << endl; break;
			}
			else if (j == car.size() - 1)
			cout << cnt[j] << endl;
		}
		tmpindex = j;
	}
	for (map<string, int>::iterator it = ma.begin(); it != ma.end(); it++) {
		if (it->second == max)
			cout << it->first.c_str() << " ";
	}
	printf("%02d:%02d:%02d", max / 3600, (max % 3600) / 60, max % 60);
	//cout << setfill('0') << setw(2) << max / 3600 << ":" <<setfill('0') << setw(2)<< (max % 3600) / 50 << ":"<<setfill('0') << setw(2)<<max % 60;
	return 0;
}
