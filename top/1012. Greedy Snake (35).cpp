#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 17;
int board[maxn][maxn]; //1 and n is the wall
int n, k;
const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int dfs(int x, int y, int cnt) {
	int i,nx,ny,ans=0;
	bool deadEnd = true;
	for (i = 0; i < 4;i++){
		int steps = 1;
		while (board[x + dir[i][0] * steps][y + dir[i][1] * steps] != 2) steps++;
		steps--;
		if (steps == 0) continue;
		deadEnd = false;
		for (int j = 0; j <= steps; j++) board[x + dir[i][0] * j][y + dir[i][1] * j] = 2;
		ans = max(ans, dfs(x + dir[i][0] * steps, y + dir[i][1] * steps, cnt + steps));
		for (int j = 0; j <= steps; j++) board[x + dir[i][0] * j][y + dir[i][1] * j] = 0;
	}
	if (deadEnd) return cnt;
	return ans;
}
int main(){
	int a, b, ans = 0, nAns = 0;
	scanf("%d %d", &n, &k);
	memset(board, 0, sizeof(board));
	for (int i = 1; i <= n; i++)
		board[1][i] = board[n][i] = board[i][1] = board[i][n] = 2;
	for (int i = 0; i < k; i++){
		scanf("%d %d", &a, &b);
		board[a][b] = 2;
	}
	for (int i = 2; i <= n - 1; i++)
		for (int j = 2; j <= n - 1; j++) {
			if (board[i][j] == 2) continue;
			int res = dfs(i, j, 1);
			if (ans == res) nAns++;
			else if (ans < res) { ans = res; nAns = 1; }
		}
	printf("%d %d\n",(n-2)*(n-2)-k-ans,nAns);
	int newAns = 0 , nNewAns = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++) {
			if (board[i][j] == 2) continue;
			board[i][j] = 2;
			int res = 0;
			for (int ii = 2; ii <= n; ii++)
				for (int jj = 2; jj <= n; jj++)
					if (board[ii][jj] != 2) 
						res = max(res, dfs(ii, jj, 1));
			board[i][j] = 0;
			if (newAns == res) nNewAns++;
			else if (newAns < res) { newAns = res; nNewAns = 1; }
		}
	if(newAns>=ans)
	printf("%d %d\n",(n-2)*(n-2)-k-1-newAns,nNewAns) ;
	else printf("-1\n");
    return 0;
}
