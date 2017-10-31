#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const  int maxn = 1e6 + 1e5;
int N;
int n, m, w, k;	//n串长度	m等级阶数	w当前子串长度	
string s;
char str[maxn];
int rak[maxn];		//i位置的等级
int second[maxn];		//按第二关键字排序，第i名的位置
int tmp[maxn];		//基排用
int height[maxn];
int sa[maxn];		//第i名的位置

void init() {
	n = s.length();
	w = 1;
	m = 127;
	for (int i = 1; i <= n; ++i) {
		rak[i] = str[i] = s[i - 1];
		second[i] = i;
	}
}

void getsa() {//基排
	for (int i = 1; i <= m; ++i)tmp[i] = 0;
	for (int i = 1; i <= n; ++i)++tmp[rak[second[i]]];
	for (int i = 2; i <= m; ++i)tmp[i] += tmp[i - 1];
	for (int i = n; i >= 1; --i)sa[tmp[rak[second[i]]]--] = second[i];
}

bool cmp(int a, int b) {
	return second[a] == second[b] && second[a + w] == second[b + w];
}

void getrak(int flag) {
	swap(rak, second);//second暂存
	int p = 1;
	rak[sa[1]] = p;
	if (flag) for (int i = 2; i <= n; ++i)rak[sa[i]] = cmp(sa[i], sa[i - 1]) ? p : ++p;
	else for (int i = 2; i <= n; ++i)rak[sa[i]] = i;
	m = p;
}

void getsecond() {
	int p = 0;
	for (int i = (n - w + 1) < 1 ? 1 : n - w + 1; i <= n; ++i) second[++p] = i;
	for (int i = 1; i <= n; ++i) if (sa[i] > w) second[++p] = sa[i] - w;
}

void getheight() {
	k = 0;
	for (int i = 1; i <= n; height[rak[i++]] = k) {
		if (k)--k;
		for(int j=sa[rak[i]-1];str[i+k]==str[j+k];)
			if (++k >= N) {
				k = N; break;
			}
	}
}

int main() {
	cin >> N; getchar();
	getline(cin, s);
	init(); getsa();
	while (true) {
		getsecond();
		getsa();
		getrak(1);
		if (w >= N)break;
		w += w;
	}
	getrak(0); getheight();
	int g = 1, h = sa[1];
	int resg = 1, resh = 1;
	for (int i = 2; i <= n; ++i) {
		if (height[i] >= N)++g;
		else {
			if (g > resg || (g == resg && s[h - 1] < s[resh - 1])) {
				resg = g;resh = h;
			}
			g = 1; h = sa[i];
		}
	}
	if (g > resg || (g == resg && s[h - 1] < s[resh - 1])) {
		resg = g; resh = h;
	}
	cout << string(s, resh - 1, N) << " " << resg << endl;
	return 0;
}
