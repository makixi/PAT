#include<bits/stdc++.h>
using namespace std;
int book[50001];
struct node{
	int num,cnt;
	node(int a,int b):num(a),cnt(b){}
	bool operator < (const node &a)const{
		return (cnt!=a.cnt)?cnt>a.cnt:num<a.num;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	set<node> s;
	for(int i=0;i<n;++i){
		int tmp;
		cin>>tmp;
		if(i){
			cout<<tmp<<":";
			int cnt=0;
			for(auto it=s.begin();it!=s.end()&&cnt<k;++it,++cnt)
    			cout<<" "<<it->num;
			cout<<endl;
		}
		auto it=s.find(node(tmp,book[tmp]));
		if(it!=s.end())s.erase(it);
		book[tmp]++;
		s.insert(node(tmp,book[tmp]));
	}
	return 0;
}
