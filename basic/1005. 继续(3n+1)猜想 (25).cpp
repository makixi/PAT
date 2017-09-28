#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=101;
bool num[maxn*100];
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
		int m=a[i];
		while(m!=1){
			if(m%2)m=m*3+1;
			m/=2;
			if(num[m])break;
			num[m]=true;
			//cout<<m<<endl;
		}
	}
	vector<int> res;
	for(int i=0;i<n;++i)
		if(!num[a[i]])res.push_back(a[i]);
	sort(res.begin(),res.end());
	for(int i=res.size()-1;i>=0;--i){
		if(i!=res.size()-1)cout<<" ";
		cout<<res[i];
	}
	return 0;
}
