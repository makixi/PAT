#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int nc,np,value,max=0;
	vector<int> c,p;
	cin>>nc;
	for(int i=0;i<nc;++i){
		cin>>value;
		c.push_back(value);
	}
	cin>>np;
	for(int i=0;i<np;++i){
		cin>>value;
		p.push_back(value);
	}
	int index=np>nc?nc:np;
	sort(c.begin(),c.end());
	sort(p.begin(),p.end());
	for(int i=0;i<index;++i){
		if(c[i]<0&&p[i]<0){
			max+=c[i]*p[i];
		}
	}
	for(int i=0;i<index;++i){
		if(c[nc-1-i]>0&&p[np-1-i]>0)
			max+=c[nc-1-i]*p[np-1-i];
	}
	cout<<max;
	return 0;
}
