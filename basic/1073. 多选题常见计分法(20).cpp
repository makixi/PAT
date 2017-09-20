#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct ques{
	int fal;//false cnt
	int full;//full score
	int c;//choose
	int rc;//right choose
	vector<char> r;//right
};
struct node{
	int index;
	char c;
	int cnt=0;
};
bool cmp(node a,node b){
	if(a.cnt!=b.cnt)return a.cnt>b.cnt;
	if(a.index!=b.index)return a.index<b.index;
	return a.c<b.c;
}
int main(){
	int n,m,i,j;
	cin>>n>>m;
	vector<ques> v(m);
	vector<node> res;
	for(int i=0;i<m;++i){
		cin>>v[i].full>>v[i].c>>v[i].rc;
		v[i].r.resize(v[i].rc);
		for(int j=0;j<v[i].rc;++j){
			cin>>v[i].r[j];
		}
	}
	vector<double> score;
	map<pair<int,char>,int> count;
	for(i=0;i<n;++i){
		int num;
		double s=0;
		for(j=0;j<m;++j){
			int rr=-2;//1->fullscore 0->half -1->0
			while(cin.peek()==')'||cin.peek()=='('||cin.peek()=='\n'||cin.peek()==' ')
				cin.get();
			map<char,int> mm;
			for(int k=0;k<v[j].r.size();++k)
				mm[v[j].r[k]]=1;//exist
			scanf("%d",&num);
			for(int k=0;k<num;++k){
				char cc;
				cin>>cc;
				if(!mm[cc]){//cc在v[j]里没有 
					rr=-1;//选了不该选的  
					count[make_pair(j+1,cc)]++;
				}else{
					mm[cc]=2;//选对了 
				}
			}
			if(rr!=-1&&num==v[j].rc)rr=1;//选全了 
			else{
				if(rr!=-1)rr=0;
				for(auto it:mm){
					if(mm[it.first]==1)//该选却没选 
						count[make_pair(j+1,it.first)]++;
				}
			}
			if(rr==1)s+=v[j].full;
			else if(rr==0)s+=(v[j].full*1.0)/2;
		}
		score.push_back(s);
	}
	for(int i=0;i<n;++i){
		printf("%.1lf\n",score[i]);
	}
	int maxcnt=0;
	for(auto it:count){
		node nn;
		nn.cnt=it.second;
		maxcnt=max(maxcnt,nn.cnt);
		nn.index=it.first.first;
		nn.c=it.first.second;
		res.push_back(nn);
	}
	sort(res.begin(),res.end(),cmp);
	if(res.size()==0)cout<<"Too simple";
	else{
		for(int i=0;i<res.size()&&res[i].cnt==maxcnt;++i)
			cout<<res[i].cnt<<" "<<res[i].index<<"-"<<res[i].c<<endl;
	}
	return 0;
}
