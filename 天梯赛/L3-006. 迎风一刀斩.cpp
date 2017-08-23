#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct node {
	int x, y;
	bool rightAngle;
};
void input(node *a, int &n) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
}
int dis(node a, node b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int tmp;
int solve(node *a, int n, int &L, int &W) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int pre = i == 1 ? n : i - 1;
		int next = i == n ? 1 : i + 1;
		//被旋转（逆时针90度、180度、或270度） 所以直接这样就可以数直角
		if ((a[i].x == a[pre].x && a[i].y == a[next].y) || (a[i].y == a[pre].y && a[i].x == a[next].x))
			a[i].rightAngle = true, cnt++;
	}
	if (n == 3 && cnt != 1)return -1;//没有直角的三角形
	if (n == 4 && cnt < 2)return -1;
	if (n == 4 && cnt == 4)return -2;//矩形
	if (n == 5 && cnt != 3)return -1;
	int up = -1, down = -1, h = -1;
	//开始算斜边
	for (int i = 1; i <= n; ++i) {
		int pre = i == 1 ? n : i - 1;
		int next = i == n ? 1 : i + 1;
		if (!a[i].rightAngle) {
			if (!a[pre].rightAngle) {
				tmp = dis(a[i], a[pre]);
				L = abs(a[i].x - a[pre].x);
				W = abs(a[i].y - a[pre].y);
				if (n == 4)
					if (up == -1) up = (int)sqrt(dis(a[i], a[next]));
					else down = (int)sqrt(dis(a[i], a[next]));
			}
			else if (!a[next].rightAngle) {
				tmp = dis(a[i], a[next]);
				L = abs(a[i].x - a[next].x);
				W = abs(a[i].y - a[next].y);
				if (n == 4)
					if (up == -1) up = (int)sqrt(dis(a[i], a[pre]));
					else down = (int)sqrt(dis(a[i], a[pre]));
			}
		}
		else if (a[i].rightAngle&&n == 4)
			if (a[pre].rightAngle)
				h = (int)sqrt(dis(a[i], a[pre]));
			else  h = (int)sqrt(dis(a[i], a[next]));
	}
	if (n == 4)
		W = abs(up - down), L = h;
	return tmp;
}
int main() {
	int t, ai, bi;
	node a[12], b[12];
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));//不加这两句就WA
		memset(b, 0, sizeof(b));
		input(a, ai);
		input(b, bi);
		if (ai + bi > 8 || ai > 5 || bi>5) {
			printf("NO\n");
			continue;
		}
		int L1, L2, W1, W2;
		int m = solve(a, ai, L1, W1);
		int n = solve(b, bi, L2, W2);
		if (m == -1 || n == -1)printf("NO\n");
		else {
			if (m == -2 && n == -2)//两个矩形
				if (dis(a[1], a[2]) == dis(b[1], b[2]) || dis(a[2], a[3]) == dis(b[1], b[2]))
					printf("YES\n");
				else printf("NO\n");
			else {
				if (bi == 4 && ai == 4) {
					if (m == n&&L1 == L2&&W1 == W2)
						printf("YES\n");
					else printf("NO\n");
					continue;
				}
				if (m == n && (L1 == L2 || L1 == W2))//斜面长度要对应
					printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}

