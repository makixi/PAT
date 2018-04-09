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

int main(){
	//ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		float height, weight;
		cin >> height >> weight;
		float stan = (height - 100) * 0.9 * 2;
		if(abs(stan - weight) < stan * 0.1) {
			cout << "You are wan mei!" << endl;
		} else if(stan > weight) {
			cout << "You are tai shou le!" << endl;
		} else {
			cout << "You are tai pang le!" << endl;
		}
	}
	return 0;
}
