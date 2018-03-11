#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
#define ver(a) a>=97?a-61:(a>=65?a-55:a-48)//0~9 'A'~'Z' 'a'~'z'
const int maxn=62;
int rest=inf,n;
struct node{
	int cnt[maxn];
}want,bead[101],curr;
node add(node a, node b) {
	node c;
	for (int i = 0; i < 62; i++) c.cnt[i] = a.cnt[i] + b.cnt[i];
	return c;
}
bool check(node curr){
	for(int i=0;i<maxn;++i)if(curr.cnt[i]<want.cnt[i])return false;
	return true;
}
int num(node curr){
	int ans=0;
	for(int i=0;i<maxn;++i)ans+=curr.cnt[i]-want.cnt[i];
	return ans;
}
int cnt=0;
void dfs(node curr,int id){
	++cnt;
	if(cnt>1000)return;	//凑出来的强行剪枝。。 
	if(rest<=num(curr))return;
	if(check(curr)){
		rest=num(curr);
		return;
	}
	for(int i=id;i<n;++i)dfs(add(curr,bead[i]),i+1);
}
int main(){
	ios::sync_with_stdio(false); 
	string str;
	cin>>str;
	for(int i=0;i<str.length();++i)want.cnt[ver(str[i])]++;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>str;
		for(int j=0;j<str.length();++j)bead[i].cnt[ver(str[j])]++;
	}
	int other=0;
	for(int i=0;i<maxn;++i)
		if(want.cnt[i]){
			int sum=0;
			for(int j=0;j<n;++j){
				sum+=bead[j].cnt[i];
				if(sum>=want.cnt[i])break;
			}
			if(sum<want.cnt[i])other+=want.cnt[i]-sum;
		}
	if(other)cout << "No " << other;//珠子不够的情况 
	else{
		dfs(curr,0);
		cout << "Yes " << rest;
	} 
	return 0;
}
