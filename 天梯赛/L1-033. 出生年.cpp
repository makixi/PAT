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
    //ios::sync_with_stdio(false);
    int y,n,x=0;
    cin>>y>>n;
    for(;true;++x){
    	int tmp=y+x;
    	int a=tmp/1000,b=tmp/100%10,c=tmp/10%10,d=tmp%10;
    	set<int> s;
    	s.insert(a);s.insert(b);s.insert(c);s.insert(d);
    	if(s.size()==n){
			//cout<<x<<" "<<tmp;
			printf("%d %04d",x,tmp);
			break;
		}	
	}
    return 0;
}
