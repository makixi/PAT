#include <iostream>
#include <cstring>
#include <stack> 
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
#define lowbit(i) ((i)&(-i))
int c[maxn];
stack<int> s;
void update(int x,int v){
	for(;x<maxn;x+=lowbit(x))c[x]+=v;
}
int getsum(int x){
	int res=0;
	for(;x>=1;x-=lowbit(x))res+=c[x];
	return res;
}
int getmedium(){
	int l=1,r=maxn,k=(s.size()+1)>>1;
	while(l<r){
		int mid=(l+r)>>1;
		if(getsum(mid)>=k)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	string ss;
	int n;
	cin>>n;
	while(n--){
		cin>>ss;
		if(ss[1]=='o'){
			if(s.empty())cout<<"Invalid\n";
			else{
				update(s.top(),-1);
				cout<<s.top()<<"\n";
				s.pop();
			}
		}else if(ss[1]=='e'){
			if(s.empty())cout<<"Invalid\n";
			else cout<<getmedium()<<"\n";
		}else{//push
			int v;
			cin>>v;
			s.push(v);
			update(v,1);
		}
	}
	return 0;
}
