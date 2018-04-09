#include <iostream> 
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=110;
char maze[maxn][maxn];
bool legal(string s){
	if(s.find('-')!=string::npos||s.find('.')!=string::npos)return false;
	for(int i=0;i<s.length();++i)
		if(!isdigit(s[i]))return false;
	int tmp=stoi(s);
	if(tmp<1||tmp>1000)return false;
	return true;
} 
int main() {
    ios::sync_with_stdio(false);
    string all;
    getline(cin,all);
    int blank=all.find(' ');
    string a=all.substr(0,blank);
    string b=all.substr(blank+1,all.length()-blank-1);
    bool aa=legal(a),bb=legal(b);
    if(aa)cout<<a;
    else cout<<"?";
    cout<<" + ";
    if(bb)cout<<b;
    else cout<<"?";
	cout<<" = ";
	if(aa&&bb)cout<<stoi(a)+stoi(b);
	else cout<<"?"; 
	return 0;
}
