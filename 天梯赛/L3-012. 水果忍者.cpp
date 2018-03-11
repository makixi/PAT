#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10001;
struct node {long long x, y1, y2;}v[maxn],mark[maxn];
struct vec {
	long long x, y;
	vec(long long a, long long b) :x(a), y(b) {};
};
bool cmp(node a, node b) {
	return a.x < b.x;
}
int k(vec a, vec b) {
	long long tmp = a.x*b.y - a.y*b.x;//kb-ka
	if (tmp > 0)return 1;
	else if (!tmp)return 0;
	return -1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> v[i].x >> v[i].y1 >> v[i].y2;
	sort(v + 1, v + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		vec krmax = vec(1, inf);
		vec krmin = vec(1, -inf);
		vec klmax = vec(-1, -inf);
		vec klmin = vec(-1, inf);
		for (int j = i + 1; j <= n; ++j) {//to right
			vec v1(v[j].x - v[i].x, v[j].y1 - v[i].y2);
			vec v2(v[j].x - v[i].x, v[j].y2 - v[i].y2);
			if (k(krmax, v1) < 0) krmax = v1;//取小的
			if (k(krmin, v2) > 0) krmin = v2;//取大的
		}
		for (int j = i - 1; j >= 1; --j) {//to left
			vec v1(v[j].x - v[i].x, v[j].y1 - v[i].y2);
			vec v2(v[j].x - v[i].x, v[j].y2 - v[i].y2);
			if (k(klmin, v1) > 0) klmin = v1;//取大的
			if (k(klmax, v2) < 0) klmax = v2;//取小的
		}
		//不行
		if (k(krmax, krmin) > 0) continue;//krman>krmin
		if (k(klmax, klmin) > 0) continue;
		if (k(krmax, klmin) < 0) continue;
		if (k(klmax, krmin) < 0) continue;
		if (k(klmax, krmax) * k(klmax, krmin) <= 0) 
			printf("%d %d %d %d", v[i].x + klmax.x, v[i].y2 + klmax.y, v[i].x, v[i].y2);
		else if (k(klmin, krmax) * k(klmin, krmin) <= 0) 
			printf("%d %d %d %d", v[i].x + klmin.x, v[i].y2 + klmin.y, v[i].x, v[i].y2);
		else if (k(klmax, krmax) > 0 && k(klmin, krmin) < 0) 
			printf("%d %d %d %d", v[i].x + krmax.x, v[i].y2 + krmax.y, v[i].x, v[i].y2);
		else if (k(krmax, klmax) > 0 && k(krmin, klmin) < 0)
			printf("%d %d %d %d", v[i].x + klmin.x, v[i].y2 + klmin.y, v[i].x, v[i].y2);
		break;
	}
	return 0;
}
