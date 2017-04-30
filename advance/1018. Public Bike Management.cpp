#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 99999999
int cmax, n, sp, m;
int minNeed = MAX, minBack = MAX;
int weight[510],e[510][510],dis[510];
bool vis[510];
vector<int> pre[510];
vector<int> path,temppath;
void dfs(int v) {
    if(v == 0) {
        temppath.push_back(v);
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
        //	cout<<temppath[i]<<endl;
            int id = temppath[i];
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        //cout<<endl;
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    else
	{
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
     {
     //	cout<<"dfs:"<<pre[v][i]<<endl;
        dfs(pre[v][i]);
	}
    temppath.pop_back();
	}
}

int main() {
	fill(e[0], e[0] + 510 * 510, MAX);
	fill(dis, dis + 510, MAX);
	cin >> cmax >> n >> sp >> m;
	for (int i = 1; i<=n; ++i) {
		cin >> weight[i];
		weight[i] = weight[i] - cmax / 2;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cin>> e[a][b];
		e[b][a] = e[a][b];
	}
	dis[0] = 0;
	for (int i = 0; i <= n; ++i) {
		int u = -1, minn = MAX;
		for (int j = 0; j <= n; ++j) {
			if (vis[j] == false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = true;
		for (int j = 0; j <= n; ++j) {
			if (vis[j] == false && e[u][j] != MAX) {
				if (dis[j] > dis[u] + e[u][j]) {
					dis[j] = dis[u] + e[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if (dis[j] == dis[u] + e[u][j])
					pre[j].push_back(u);
			}
		}
	}
	dfs(sp);
    cout << minNeed << " 0";
	for (int i = path.size() - 2; i >= 0; i--)
		cout << "->" << path[i];
	cout << " " << minBack;
	return 0;
}
