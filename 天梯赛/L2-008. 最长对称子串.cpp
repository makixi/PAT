#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string str,a,b;
	getline(cin,str);
	int maxlen=str.length(),res=0;
	for(int i=0;i<maxlen;++i){//curr index
		int tmp=1;
		for(int j=1;j+i<maxlen&&j<=i;++j){//substr(i,j)
			if(str[i-j]!=str[i+j])
				break;
			tmp+=2;
		}
		res=max(res,tmp);
		tmp=0;
		for(int j=1;j+i<maxlen&&j<=i+1;++j){
			if(str[i-j+1]!=str[i+j])
				break;
			tmp+=2;
		}
		res=max(res,tmp);
	}
	cout<<res;
	return 0;
}
