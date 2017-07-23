#include<iostream>
using namespace std;
const int maxnum=100001;
int cnt[maxnum];
int ran[maxnum];
int main(){
	int n,tmp,mark=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>tmp;
		cnt[tmp]++;
		ran[i]=tmp;
	}
	for(int i=0;i<n;++i){
		if(cnt[ran[i]]==1){
			mark=ran[i];break;
		}
	}
	if(mark==0)cout<<"None"<<endl;
	else cout<<mark<<endl;
	return 0;
}
