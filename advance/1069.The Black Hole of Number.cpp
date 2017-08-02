#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(const char a,const char b){
	return a-b>0;
}
int main(){
	string str;
	cin>>str;
	int res,a,b;
	do{
		str.insert(0,4-str.length(),'0');
		sort(str.begin(),str.end(),cmp);
		a=stoi(str);
		for(int i=0;i<2;++i)
			swap(str[i],str[3-i]);
		b=stoi(str);
		res=a-b;
		str=to_string(res);
		printf("%04d - %04d = %04d\n",a,b,res);
	}while(res!=0&&res!=6174);
	return 0;
}
