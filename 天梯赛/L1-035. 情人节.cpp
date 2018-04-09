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
    string tmp,a="",b="";
    int cnt=0;
    while(cin>>tmp&&tmp!="."){
    	++cnt;
    	if(cnt==2)a=tmp;
    	else if(cnt==14)b=tmp;
	}
	if(a.length()&&b.length())cout<<a<<" and "<<b<<" are inviting you to dinner...\n";
	else if(a.length())cout<<a<<" is the only one for you...\n";
	else cout<<"Momo... No one is for you ...\n";
    return 0;
}
