#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100001;
struct node{
	int nad;
	int val;
	int ad;
	int num;
};
node v[maxn];
bool cmp(node a,node b){
	return a.num<b.num;
}
int main(){
	int fad,n,ad,num=2,cnt=0;
	cin>>fad>>n;
	for(int i=0;i<maxn;++i)v[i].num=maxn;
	for(int i=0;i<n;++i){
		cin>>ad;
		cin>>v[ad].val>>v[ad].nad;
		v[ad].ad=ad;
	}
	for(int i=fad;i!=-1;i=v[i].nad)cnt++;
	for(int i=1;fad!=-1;fad=v[fad].nad,++i){
		v[fad].num=num;
		if(i<cnt/2)
			num+=2;
		else if(i==cnt/2&&(cnt&1))
			num+=1;
		else if(i==cnt/2)
			num-=1;
		else num-=2;
	}
	sort(v,v+maxn,cmp);
	for(int i=0;i<cnt;++i){
		printf("%05d %d ",v[i].ad,v[i].val);
		if(i==cnt-1)printf("-1\n");
		else printf("%05d\n",v[i+1].ad);
	}
	return 0;
}
