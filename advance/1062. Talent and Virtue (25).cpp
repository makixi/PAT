#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int vg;
	int tg;
};
bool cmp(node a,node b){
	if(a.vg+a.tg!=b.vg+b.tg)return a.vg+a.tg>b.vg+b.tg;
	else if(a.vg!=b.vg)return a.vg>b.vg;
	else return a.id<b.id;
}
void print(vector<node> vec){
	for(vector<node>::iterator it=vec.begin();it!=vec.end();++it)
		printf("%d %d %d\n",it->id,it->vg,it->tg);
}
int main(){
	int n,l,h;
	cin>>n>>l>>h;
	node v;
	vector<node> sage;
	vector<node> nobleman;
	vector<node> fool;
	vector<node> other;
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&v.id,&v.vg,&v.tg);
		if(v.vg<l||v.tg<l)continue;
		else if(v.vg>=h&&v.tg>=h)sage.push_back(v);
		else if(v.vg>=h&&v.tg<h)nobleman.push_back(v);
		else if(v.vg>=v.tg)fool.push_back(v);
		else other.push_back(v);
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(nobleman.begin(),nobleman.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(other.begin(),other.end(),cmp);
	cout<<sage.size()+nobleman.size()+fool.size()+other.size()<<endl;
	print(sage);
	print(nobleman);
	print(fool);
	print(other);
	return 0;
}
