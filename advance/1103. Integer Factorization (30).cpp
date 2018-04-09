#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
#define mp(i,j) make_pair(i,j)
const int maxn=11;
const int inf=0x3f3f3f3f;
int p,num,ans=0,n;
bool flag=false;
vector<int> res,tmp;
void dfs(int u,int ind,int rest,int sum){
	if(rest<0)return;
	if(ind>num)return;
	tmp.push_back(u);
	if(rest==0&&ind==num){
		flag=true;
		if(sum>ans){
			ans=sum;
			res=tmp;
		}
		tmp.pop_back();
		return;
	}
	for(int st=u;st>=1;--st)
		dfs(st,ind+1,rest-pow(st,p),sum+st);
	tmp.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>num>>p;
	for(int st=pow(n,1.0/p);st>=1;--st)
		dfs(st,1,n-pow(st,p),st);
	if(!flag)cout<<"Impossible";
	else{
		cout<<n<<" = ";
		for(int i=0;i<res.size();++i){
			if(i)cout<<" + ";
			cout<<res[i]<<"^"<<p;
		}
	}
	return 0;
}
