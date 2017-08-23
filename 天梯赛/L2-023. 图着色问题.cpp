#include<iostream>
#include<set>
using namespace std;
const int maxn=510;
bool e[maxn][maxn]={false};
int color[maxn];
int main(){
	int m,n,k,a,b,q;
	cin>>n>>m>>k;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		e[a][b]=e[b][a]=true;
	}
	cin>>q;
	while(q--){
		bool flag=true;
		set<int> s;
		for(int i=1;i<=n;++i){
			cin>>color[i];
			s.insert(color[i]);
		}
		if(k!=s.size())flag=false;
		for(int i=1;i<=n;++i){
			if(!flag)break;
			for(int j=i+1;j<=n;++j){
				if(e[i][j]&&color[i]==color[j]){
					flag=false;
					break;
				}
			}
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
