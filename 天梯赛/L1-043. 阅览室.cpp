#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=105;
const int inf=0x3f3f3f3f;
map<int,char> key;
map<int,int> tim;
int main(){
	//ios::sync_with_stdio(false);
	int n,id,h,m,cnt=0,read=0;
	char c;
	cin>>n;
	while((cin>>id>>c)&&n){
		scanf("%d:%d",&h,&m);
		int tmp=h*60+m;
		if(id==0){//输入一天的 
			if(cnt)cout<<cnt<<" "<<round(read*1.0/cnt)<<endl;
			else cout<<0<<" "<<0<<"\n";
			cnt=0;read=0;
			key.clear();
			tim.clear();
			n--;
		}
		if(c=='E'&&key[id]!='S')continue;
		if(c=='E'){
			read+=tmp-tim[id];
			cnt++;
			key[id]=c;
		}else if(c=='S'){
			tim[id]=tmp;
			key[id]=c;
		}
	}
	return 0;
}
