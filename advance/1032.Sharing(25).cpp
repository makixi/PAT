#include<iostream>
using namespace std;
#define MAX 100000
int nex[MAX];
bool flag[MAX];
int main(){
	int ad1,ad2,n,address,common=-1;
	char value;
	cin>>ad1>>ad2>>n;
	while(n--){
		cin>>address>>value;
		cin>>nex[address];
	}
	int tmp1=ad1,tmp2=ad2;
	while(tmp1!=-1){
		flag[tmp1]=1;
		tmp1=nex[tmp1];
	}
	while(tmp2!=-1){
		if(flag[tmp2]==1){
			common=tmp2;
			break;
		}
		tmp2=nex[tmp2];
	}
	if(common!=-1)
		printf("%05d\n",common);
	else 
		printf("-1\n");
	return 0;
}
