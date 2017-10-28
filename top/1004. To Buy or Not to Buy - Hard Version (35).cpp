#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ver(a) a>=97?a-61:(a>=65?a-55:a-48)
int minn,n;
bool vis[100]={false};

struct node{
	int cnt[62];
	int used,total;//能被用的 和 总共的 
}bead[100],want,curr;

bool cmp(const node &a,const node &b) {
	return a.used>b.used;
}

node add(node a, node b) {
	node c;
	for (int i = 0; i < 62; i++) c.cnt[i] = a.cnt[i] + b.cnt[i];
	return c;
}

int num(node no) {
	int x = 0;
	for (int i = 0; i < 62; i++) x += max(0 , no.cnt[i] - want.cnt[i]);
	return x;//多了多少 
}

bool check(node no) {
	for (int i = 0; i < 62; i++) if (no.cnt[i] < want.cnt[i]) return false;
	return true;
}
int cnt=0;
void dfs(node no) {
	++cnt;
	if(cnt>1000)return;	//凑出来的强行剪枝。。 
	if (minn <= num(no)) return; 
	if (check(no)) {
		minn = num(no);
		return;
	}
	for (int i = 0; i < n; i++) 
		if (!vis[i]) {
			vis[i] = 1;
			dfs(add(no, bead[i]));
			vis[i] = 0;
		}
	return;
}
int main(){
	for(int i=0;i<62;++i){
		for(int j=0;j<100;++j)bead[j].cnt[i]=0;
		want.cnt[i]=0;
		curr.cnt[i]=0;
	}
	for(int i=0;i<100;++i)bead[i].used=0,bead[i].total=0;
	char c;
	while((c=getchar())&&c!='\n'){
		want.cnt[ver(c)]++;
		want.total++;
	}
	scanf("%d",&n);getchar();
	for(int i=0;i<n;++i)
		while((c=getchar())&&c!='\n'){
			bead[i].cnt[ver(c)]++;
			bead[i].total++;
		}
	for (int i = 0; i < 100; i++) 
		for (int j = 0; j < 62; j++) 
			if (bead[i].cnt[j] && want.cnt[j]) bead[i].used += min(bead[i].cnt[j],want.cnt[j]);
	sort(bead,bead+n,cmp);
	minn = 0;
	for (int i = 0; i < 62; i++) 
		if (want.cnt[i]) {
			int x = 0;
			for (int j = 0; j < n; j++) {
				x += bead[j].cnt[i];//可以收集到最多的这种颜色的珠子 
				if (x >= want.cnt[i]) break;
			}
			if (x < want.cnt[i]) minn += (want.cnt[i] - x);//所有串加起来 这种颜色都不够
		}
	if (minn) cout << "No " << minn;//珠子不够 
	else {
		minn = 0x7fffffff;
		dfs(curr);
		cout << "Yes " << minn;
	}
	return 0;
}
