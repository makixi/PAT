#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
int main() {
	int N, M;
	int choose, truenum;
	cin >> N >> M;
	vector<int> fullsocre(M),wrongtime(M);
	vector<set<char>> truechoose(M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &fullsocre[i], &choose, &truenum);
		for (int j = 0; j < truenum; j++) {
			char c;
			scanf(" %c", &c);
			truechoose[i].insert(c);
		}
	}
	for (int i = 0; i < N; i++) {
		int score = 0;
		scanf("\n");
		for (int j = 0; j < M; j++) {
			if(j!=0) scanf(" ");
			scanf("(%d",&truenum);
			set<char> ch;
			char c;
			for (int k = 0; k < truenum; k++) {
				scanf(" %c", &c);
				ch.insert(c);
			}
			scanf(")");
			if (ch == truechoose[j]) score += fullsocre[j];
			else	++wrongtime[j];
		}
		cout << score << endl;
	}
	int count=0;
	for(int i=0;i<M;i++)if(wrongtime[i]>count)count=wrongtime[i];
	if(count==0)printf("Too simple");  
	else{
		cout<<count;
		for(int i=0;i<M;i++)if(wrongtime[i]==count)cout<<" "<<i+1;
	}
	return 0;
}
