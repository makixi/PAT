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
int main() {
    //ios::sync_with_stdio(false);
    double a,b;
    cin>>a>>b;
    //if(b==0)cout<<"Error";
    //else{
    	cout<<a<<"/";
    	if(b<0){
    		cout<<"("<<b<<")"<<"=";
		}else if(b>0){
			cout<<b<<"=";
		}else {
			cout<<b<<"=Error";
			return 0;
		}
		printf("%.2lf",a/b);
	//}
    return 0;
}
