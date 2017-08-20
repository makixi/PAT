#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int book[50001];
struct node{
	int click;
	int val;
	node(int a,int b):val(a),click(b){}
	bool operator < (const node &a)const{
		return (click!=a.click)?click>a.click:val<a.val;
	}
};
int main(){
    int n,k,tmp;
    cin>>n>>k;
    set<node> s;
    for(int i=0;i<n;++i){
    	cin>>tmp;
    	if(i){
    		cout<<tmp<<":";
    		int cnt=0;
    		for(auto it=s.begin();it!=s.end()&&cnt<k;++it){
    			++cnt;
    			printf(" %d",it->val);
			}
			cout<<endl;
		}
		auto it=s.find(node(num,book[num]));
		if(it!=s.end())s.erase(it);
		book[tmp]++;
		s.insert(node(num,book[num]));
	}
    return 0;
}
