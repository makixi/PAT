#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ot=8*3600;
int ct=17*3600;
struct node{
	int at;
	int pt;
}tempnode;

bool cmp(node a,node b){
	return a.at<b.at;
}

int main(){
	vector<node> cos;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;++i){
		int hour,minute,second,time;
		scanf("%d:%d:%d",&hour,&minute,&second);
		tempnode.at=hour*3600+minute*60+second;
		cin>>time;
		tempnode.pt=time*60;
		if(tempnode.at>ct) continue;
		cos.push_back(tempnode);
	}
	sort(cos.begin(),cos.end(),cmp);
	vector<int> window(k,28800);
	double result=0.0;
	for(int i=0;i<cos.size();++i){
		int tempindex=0,minfinish=window[0];
		for(int j=1;j<k;++j){
			if(minfinish>window[j]){
				minfinish=window[j];
				tempindex=j;
			}
		}
		if(window[tempindex]<=cos[i].at){
			window[tempindex]=cos[i].at+cos[i].pt;
		}else{
			result+=(window[tempindex]-cos[i].at);
			window[tempindex]+=cos[i].pt;
		}
	}
	if(cos.size()==0) cout<<"0.0";
	else printf("%.1f", result / 60.0 / cos.size());
	return 0;
}
