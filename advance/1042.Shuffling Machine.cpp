#include<iostream>
using namespace std;
int init[55],res[55];
int order[55];
int main(){
	int k;// the number of repeat times
	cin>>k;
	for(int i=1;i<=54;++i){
		cin>>order[i];init[i]=i;
	}
	while(k--){
		for(int i=1;i<=54;++i)
			res[order[i]]=init[i];
		for(int i=1;i<=54;++i)
			init[i]=res[i];
	}
	char c[6] = {"SHCDJ"};
    for(int i = 1; i <= 54; i++) {
        res[i] -= 1;
        cout<<c[res[i] / 13]<<(res[i] % 13 + 1);
        if(i != 54) cout<<" ";
    }
	return 0;
}
