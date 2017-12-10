#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int Max=101;
int Graph[Max][Max], Indegree[Max], Outdegree[Max], Earliest[Max];

int Earliest_Time(int N){
	queue<int> q;
	for (int i = 0; i < N; i++)
		if (Indegree[i] == 0){
			q.push(i);
			Indegree[i]--;
		}
	int cnt = 0, v;
	while (!q.empty()){
		v = q.front();q.pop();
		cnt++;
		for (int i = 0; i < N; i++){
			if (Graph[v][i] >= 0){
				Indegree[i]--;
				Earliest[i] = max(Earliest[i], Earliest[v] + Graph[v][i]);
			}
			if (Indegree[i] == 0){
				q.push(i);
				Indegree[i]--;
			}
		}
	}
	int res = 0;
	if (cnt != N) return -1;
	else {
		for (int i = 0; i < N; i++)
			if (Outdegree[i] == 0)res = max(res, Earliest[i]);
		return res;
	}
}
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			Graph[i][j] = -1;
		Indegree[i] = 0;
		Outdegree[i] = 0;
		Earliest[i] = 0;
	}
	int s, e, c;
	for (int i = 0; i < M; i++){
		scanf("%d %d %d", &s, &e, &c);
		Graph[s][e] = c;
		Outdegree[s]++;
		Indegree[e]++;
	}
	int res=Earliest_Time(N);
	if (res != -1)printf("%d", res);
	else printf("Impossible");
	return 0;
}
