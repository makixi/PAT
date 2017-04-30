#include<iostream>
using namespace std;
const int MAX = 99999999;
int main() {
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	int RescueTeam[510], RoadLength[510][510], temp[510], RescueNum[510], RoadNum[510];
	bool flag[510];
	fill(RoadLength[0], RoadLength[0] + 510*510, MAX);
	fill(temp, temp + 510, MAX);

	for (int i = 0; i < N; i++)
		cin >> RescueTeam[i];   //救援队伍数量
	for (int i = 0; i < M; i++) {
		int a, b, length;
		cin >> a >> b >> length;
		RoadLength[b][a] = length;
		RoadLength[a][b] = length; //城市之间道路长度
	}
	temp[C1] = 0;
	RoadNum[C1] = 1;
	RescueNum[C1] = RescueTeam[C1];
	for (int i = 0; i < N; i++) {
		int min = MAX, k = -1;
		for (int j = 0; j < N; j++) {
			if (!flag[j] && temp[j] < min)
			{
				k = j;
				min = temp[j]; 
			}
		}
		flag[k] = 1;
		for (int j = 0; j < N; j++) {
			if (!flag[j] && RoadLength[k][j] != MAX) {
				if (temp[k] + RoadLength[k][j] < temp[j]) {
					temp[j] = temp[k] + RoadLength[k][j];
					RoadNum[j] = RoadNum[k];
					RescueNum[j] = RescueNum[k] + RescueTeam[j];
				}
				else if (temp[k] + RoadLength[k][j] == temp[j]) {
					RoadNum[j]+= RoadNum[k];
					if (RescueNum[k] + RescueTeam[j] > RescueNum[j])
						RescueNum[j] = RescueNum[k] + RescueTeam[j];
				}
			}
		}
	}
	cout << RoadNum[C2] << " " << RescueNum[C2];
	return 0;
}
