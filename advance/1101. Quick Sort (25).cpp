#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a,b;
vector<int> res;
int n;
void findPivot(int low,int high){
	int maxn=0;
	for(int mid=low;mid<=high;++mid){
		if(a[mid]==b[mid]&&b>maxn)res.push_back(b[mid]);
		if(b[mid]>maxn)maxn=b[mid];
	}
}
int main() {
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;++i)cin>>a[i];
	b=a;
	sort(a.begin(),a.end());
	findPivot(0,n-1);
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();++i){
		if(i)cout<<" ";
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}
