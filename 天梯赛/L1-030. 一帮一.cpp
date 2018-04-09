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
struct node{
	int sex;
	string name;
};
bool vis[55];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<node> v(n);
	for(int i=0;i<n;++i)cin>>v[i].sex>>v[i].name;
	int wg=n-1,wb=n-1;//worst girl;worst boy
	for(int i=0;i<n;++i){
		if(!vis[i]){
			vis[i]=true;
			int s=v[i].sex;
			if(v[i].sex==0){
				for(int j=wb;j>=0;--j){
					if(!vis[j]&&v[j].sex==1){
						vis[j]=true;
						wb=j-1;
						cout<<v[i].name<<" "<<v[j].name<<endl;
						break;
					}
				}
			}else{
				for(int j=wg;j>=0;--j){
					if(!vis[j]&&v[j].sex==0){
						vis[j]=true;
						wg=j-1;
						cout<<v[i].name<<" "<<v[j].name<<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
