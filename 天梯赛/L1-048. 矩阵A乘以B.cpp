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
int a[1010][1010],b[1010][1010],c[1010][1010];
int main(){
	ios::sync_with_stdio(false);
	int ra,ca,rb,cb;
	cin>>ra>>ca;
	for(int i=0;i<ra;++i)
		for(int j=0;j<ca;++j)
			cin>>a[i][j];
	cin>>rb>>cb;
	for(int i=0;i<rb;++i)
		for(int j=0;j<cb;++j)
			cin>>b[i][j];
	if(ca!=rb)cout<<"Error: "<<ca<<" != "<<rb;
	else{
		for(int i=0;i<ra;++i)
			for(int j=0;j<cb;++j)
				for(int k=0;k<rb;++k)
					c[i][j]+=a[i][k]*b[k][j];
		cout<<ra<<" "<<cb<<endl;
		for(int i=0;i<ra;++i){
			for(int j=0;j<cb;++j){
				if(j)cout<<" ";
				cout<<c[i][j];
			}
			cout<<"\n";
		}
	}
	return 0;
}
