#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
map<int,bool> m;
int main(){
	//ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		int k,tmp;
		cin>>k;
		if(k==1)cin>>tmp;
		else
			for(int j=0;j<k;++j){
				cin>>tmp;
				m[tmp]=true;
			}
	}
	int q;
	cin>>q;
	bool first=true;
	while(q--){
		int tmp;
		cin>>tmp;
		if(!m[tmp]){
			if(!first)cout<<" ";
			first=false;
			printf("%05d",tmp);
		}
	}
	if(first){
		cout<<"No one is handsome";
	}
	return 0;
}
