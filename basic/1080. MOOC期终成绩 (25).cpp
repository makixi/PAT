#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct nod{
	string id;
	int poins;
	int mid=-1,fin=-1,g=-1;
}nod;
nod nods[10001];
map<string,int>mp;
int p,m,n;
bool cmp(nod a,nod b){
	if(a.g!=b.g) return a.g>b.g;
	if(a.g==-1) return false;
	return a.id<b.id;
}
int main(){
	char tid[21];
	int ts,cnt=1;
	scanf("%d %d %d",&p,&m,&n);
	for(int i=0;i<p;i++){
		scanf("%s %d",tid,&ts);
		if(ts>=200){
			nods[cnt].id=tid;
			mp[tid]=cnt++;
			nods[cnt-1].poins=ts;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%s %d",tid,&ts);
		if(mp[tid]!=0)
			if(ts>nods[mp[tid]].mid)
				nods[mp[tid]].mid=ts;
	}
	for(int i=0;i<n;i++){
		scanf("%s %d",tid,&ts);
		if(mp[tid]!=0){
			if(ts>nods[mp[tid]].fin){
				nods[mp[tid]].fin=ts;
			}
		}
	}
	for(int i=1;i<cnt;i++){
		if(nods[i].fin>=nods[i].mid)nods[i].g=nods[i].fin;
		else{
			double t=nods[i].mid*4+nods[i].fin*6;
			t=t/10;t+=0.5;
			nods[i].g=t;
		}
		if(nods[i].g<60) nods[i].g=-1;
	}
	sort(nods+1,nods+cnt,cmp);
	for(int i=1;i<cnt;i++){
		if(nods[i].g==-1) break;
		printf("%s %d %d %d %d\n",nods[i].id.c_str(),nods[i].poins,nods[i].mid,nods[i].fin,nods[i].g);
	}
	
	return 0;
}
