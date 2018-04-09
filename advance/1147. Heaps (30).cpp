#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> 
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f;
int n,level[maxn];
bool judgemax(){
	int low=1;
	while(low<=n&&low*2<=n){
		int child=low*2;
		if(child+1<=n&&level[child+1]>level[child])child+=1;
		if(level[child]>level[low])return false;
		++low;
	}
	return true;
}
bool judgemin(){
	int low=1;
	while(low<=n&&low*2<=n){
		int child=low*2;
		if(child+1<=n&&level[child+1]<level[child])child+=1;
		if(level[child]<level[low])return false;
		++low;
	}
	return true;
}
bool first;
void post(int u){
	if(u*2<=n)post(u*2);
	if(u*2+1<=n)post(u*2+1);
	if(!first)cout<<" ";
	first=false;
	cout<<level[u];
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t>>n;
    while(t--){
    	first=true;
    	for(int i=1;i<=n;++i)cin>>level[i];
    	if(judgemax())cout<<"Max Heap\n";
    	else if(judgemin())cout<<"Min Heap\n";
    	else cout<<"Not Heap\n";
    	post(1);
    	cout<<"\n";
	}
    return 0;
}
