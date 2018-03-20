#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> v(n+1,0);
	for(int i=1;i<=n;++i){
		int tmp;
		cin>>tmp;
		v[abs(tmp-i)]++;
	}
	for(int i=n;i>=0;--i)
		if(v[i]>1)cout<<i<<" "<<v[i]<<endl;
	return 0;
}
