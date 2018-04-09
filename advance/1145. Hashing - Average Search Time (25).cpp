#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm> 
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f;
int msize;
double res=0;
vector<int> v;
bool isprime(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;++i)
        if(n%i==0) return 0;
    return 1;
}
int getad(int x){
	return x%msize;
}
void insert(int x){
	int add=0;
	while(add<msize){
		int ad=getad(x+add*add);
		if(v[ad]==0){
			v[ad]=x;
			return;
		}
		++add;
	}
	cout<<x<<" cannot be inserted.\n";
}
int search(int x){
	int add=0,cnt=0;
	while(add<msize){
		++cnt;
		int ad=getad(x+add*add);
		if(v[ad]==x||v[ad]==0)return cnt;
		++add;
	}
	return cnt+1;
}
int main(){
    int n,m;
    cin>>msize>>n>>m;
    while(!isprime(msize))++msize;
    v.resize(msize); 
    for(int i=0;i<n;++i){
    	int tmp;
    	cin>>tmp;
    	insert(tmp);
	}
	for(int i=0;i<m;++i){
		int tmp;
    	cin>>tmp;
    	res+=search(tmp);
	}
	printf("%.1lf",res/m);
    return 0;
}
