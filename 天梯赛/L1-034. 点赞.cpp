#include <iostream> 
#include <cstdio>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    map<int,int> cnt;
    int n,id=0,times=0;
    cin>>n;
    for(int i=0;i<n;++i){
    	int k;
    	cin>>k;
    	while(k--){
    		int tmp;
    		cin>>tmp;
    		cnt[tmp]++;
		}
	}
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it)
		if(it->second>times){
			times=it->second;
			id=it->first;
		}else if(it->second==times&&it->first>id){
			id=it->first;
		}
	cout<<id<<" "<<times;
    return 0;
}
