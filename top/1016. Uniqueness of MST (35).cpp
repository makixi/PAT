#include <cstdio>
#include <algorithm>
#include <vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define intwo(i,j) scanf("%d%d",&i,&j)
#define inthree(i,j,k) scanf("%d%d%d",&i,&j,&k)
using namespace std;
const int maxn = 3e5 + 10;
int n, m;
int fa[maxn];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
typedef struct e {
	int x, y, w;
	bool friend operator < (struct e a, struct e b) {
		return a.w < b.w;
	}
}E;
E es[maxn];
int main(){
	intwo(n, m);
	int mCost = 0, tot = 0, nCompt = n; //tot 可出现在最小生成树中的边的个数
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) inthree(es[i].x, es[i].y, es[i].w);
	sort(es + 1, es + m + 1);
	for (int i = 1, j; i <= m; i = j){
		for (j = i; j <= m&&es[i].w == es[j].w; j++){
			int fx = find(es[j].x), fy = find(es[j].y);
			if (fx == fy) continue; 
			tot++;
		}
		for (j = i; j <= m&&es[i].w == es[j].w; j++){
			int fx = find(es[j].x), fy = find(es[j].y);
			if (fx == fy) continue; 
			fa[fx] = fy; mCost += es[j].w; nCompt--;
		}
	}
	if (nCompt == 1) printf("%d\n%s\n", mCost, tot < n ? "Yes" : "No");
	else printf("No MST\n%d\n", nCompt);
    return 0;
}
