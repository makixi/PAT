#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 1020;
const int inf = 0x3f3f3f3f;
int n;	//number of hourses;
int m;	//number of candidate locations		G1 to GM
int k;	//number of roads connecting hourses and gas station
int Ds;		//maximum service range
int dis[maxn];	//distance from gas stations to hourses
int table[maxn][maxn];	//every path
bool vis[maxn];
int main() {
	fill(table[0], table[0] + maxn*maxn, inf);
	int tmpdis, a, b;
	string p1, p2;
	cin >> n >> m >> k >> Ds;
	for (int i = 0; i<k; ++i) {
		cin >> p1 >> p2 >> tmpdis;
		if (p1[0] == 'G') {
			p1 = p1.substr(1);
			a = n + stoi(p1);
		}
		else a = stoi(p1);
		if (p2[0] == 'G') {
			p2 = p2.substr(1);
			b = n + stoi(p2);
		}
		else b = stoi(p2);
		table[a][b] = table[b][a] = tmpdis;
	}
	int res = -1;
	double resdis=-1, resave=inf;
	for (int index = n+1; index <= n + m; ++index) {
		double ave = 0,mindis=inf;
		fill(vis, vis + maxn, false);
		fill(dis, dis + maxn, inf);
		dis[index] = 0;
		//find smallest distance from gas station to hourses
		for (int i = 1; i <= n+m; ++i) {
			int minn = inf, u = -1;
			for (int j = 1; j <= n+m; ++j)
				if (!vis[j] && dis[j] < minn) {
					minn = dis[j]; u = j;
				}
			if (u == -1)break;
			vis[u] = true;
			for (int j = 1; j <= n + m; ++j)
				if (!vis[j] && dis[j] > dis[u] + table[u][j])
					dis[j] = dis[u] + table[u][j];
		}
		for (int i = 1; i <= n; ++i) {
			if (dis[i] > Ds) {
				mindis = -1;
				break;
			}
			mindis = min(mindis, dis[i]*1.0);
			ave += dis[i] * 1.0;
		}
		if (mindis == -1)continue;
		ave /= n;
		//as far away as possible
		if (mindis > resdis) {
			res = index;
			resdis = mindis;
			resave = ave;
		}
		else if (mindis == resdis&&ave < resave) {
			res = index;
			resave = ave;
		}
	}
	if (res == -1)
		cout << "No Solution";
	else {
		printf("G%d\n%.1f %.1f", res - n, resdis, resave);//res-n!!!!
	}
	return 0;
}
