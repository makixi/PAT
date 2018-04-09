#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
map<string,int> getid;
int tot=1;
struct node{
	string name;
	double score;
	int num;
	node(string nn,double ss,int uu):name(nn),score(ss),num(uu){}
	bool operator < (const node &oo)const{
		if((int)score!=(int)oo.score)return (int)score>(int)oo.score;
		if(num!=oo.num)return num<oo.num;
		return name<oo.name;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<node> v;
	for(int i=0;i<n;++i){
		string a,b;
		int c;
		cin>>a>>c>>b;
		transform(b.begin(),b.end(),b.begin(),::tolower);
		if(!getid[b]){
			getid[b]=tot++;
			v.push_back(node(b,0,0));
		}
		v[getid[b]-1].num++;
		if(a[0]=='A')v[getid[b]-1].score+=c;
		else if(a[0]=='B')v[getid[b]-1].score+=c*1.0/1.5;
		else v[getid[b]-1].score+=c*1.5;	
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	cout<<1<<" "<<v[0].name<<" "<<(int)v[0].score<<" "<<v[0].num<<endl;
	int pre=1;
	for(int i=1;i<v.size();++i){
		if((int)v[i].score==(int)v[i-1].score)
			cout<<pre;
		else{
			cout<<(i+1);
			pre=i+1;
		}
		cout<<" "<<v[i].name<<" "<<(int)v[i].score<<" "<<v[i].num<<endl;
	}
	return 0;
}
