#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 999999;
struct players {
	int arrive;
	int playtime;
	int starttime;
	bool vip;
};
struct tables {
	int endtime = 8 * 3600;
	int num;
	bool vip;
};
bool cmpArrive(players a, players b) {
	return a.arrive < b.arrive;
}
bool cmpStartTime(players a, players b) {
	return a.starttime < b.starttime;
}
vector<players> player;
vector<tables> table;
int findvip(int vipnum) {
	++vipnum;
	while (vipnum < player.size() && !player[vipnum].vip)
		vipnum++;
	return vipnum;
}
void allocate(int playerindex, int tableindex) {
	if (player[playerindex].arrive <= table[tableindex].endtime)
		player[playerindex].starttime = table[tableindex].endtime;
	else
		player[playerindex].starttime = player[playerindex].arrive;
	table[tableindex].endtime = player[playerindex].starttime + player[playerindex].playtime;
	++table[tableindex].num;
}
int main() {
	int n;//number of players
	int k;
	int h, m, s, tag, pt, viptable;
	int closetime = 3600 * 21;
	players tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d:%d:%d %d %d", &h, &m, &s, &pt, &tag);
		tmp.arrive = h * 3600 + m * 60 + s;
		if (tmp.arrive >= closetime)continue;	//无视关门后才来的运动员
		tmp.playtime = min(2 * 3600, pt * 60);
		tmp.vip = ((tag == 1) ? true : false);
		player.push_back(tmp);
	}
	cin >> k >> m;//number of tables and number of vip tables
	table.resize(k + 1);
	for (int i = 0; i < m; ++i) {
		cin >> viptable;
		table[viptable].vip = true;
	}
	sort(player.begin(), player.end(), cmpArrive);
	int index = 0;
	int vipnum = -1;
	vipnum = findvip(vipnum);
	while (index < player.size()) {
		int minEndtime = INF,tableindex=-1;
		for (int j = 1; j <= k; ++j) {
			if (table[j].endtime < minEndtime) {
				minEndtime = table[j].endtime;
				tableindex = j;
			}
		}
		if (minEndtime >= closetime)break;
		if (player[index].vip&&index < vipnum) {
			index++;
			continue;
		}
		if (table[tableindex].vip) {
			if (player[index].vip) {
				allocate(index, tableindex);
				if (vipnum == index)
					vipnum = findvip(vipnum);
				++index;
			}
			else {
				if (vipnum < player.size() && player[vipnum].arrive <= table[tableindex].endtime) {
					allocate(vipnum, tableindex); vipnum = findvip(vipnum);
				}
				else {
					allocate(index, tableindex);
					index++;
				}
			}
		}
		else {
			if (player[index].vip) {
				int vipindex = -1, mintime = INF;
				for (int j = 1; j <= k; ++j) {
					if (table[j].vip&&table[j].endtime < mintime) {
						mintime = table[j].endtime;
						vipindex = j;
					}
				}
				if (vipindex != -1 && player[index].arrive >= table[vipindex].endtime) {
					allocate(index, vipindex);
					if (vipnum == index)
						vipnum = findvip(vipnum);
					index++;
				}
				else {
					allocate(index, tableindex);
					if (vipnum == index)
						vipnum = findvip(vipnum);
					index++;
				}
			}
			else {
				allocate(index, tableindex);
				index++;
			}
		}
	}
	sort(player.begin(), player.end(), cmpStartTime);
	for (int i = 0; i < player.size() && player[i].starttime <closetime; ++i) {
		if (player[i].starttime <= 0)continue;
		printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
		printf("%02d:%02d:%02d ", player[i].starttime / 3600, player[i].starttime % 3600 / 60, player[i].starttime % 60);
		printf("%.0f\n", round((player[i].starttime - player[i].arrive) / 60.0));
	}
	for (int i = 1; i <= k; ++i) {
		if (i != 1)cout << " ";
		cout << table[i].num;
	}
	return 0;
}
