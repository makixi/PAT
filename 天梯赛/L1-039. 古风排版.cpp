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
typedef long long ll;
const int maxn=110;
char maze[maxn][maxn];
int main() {
    //ios::sync_with_stdio(false);
    int row;
    string s;
    //getchar();
    cin>>row;getchar();
    getline(cin,s);
    int len=s.length();
    int col=ceil(len*1.0/row);
    //cout<<len<<" "<<row<<" "<<col<<endl;
    int index=0;
    for(int j=col-1;j>=0;--j){
    	for(int i=0;i<row;++i){
    		if(index>=len)maze[i][j]=' ';
    		else maze[i][j]=s[index++];
		}
		//cout<<j<<endl;
	}
	for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
			cout<<maze[i][j];
		}
		cout<<endl;
	}
    return 0;
}
