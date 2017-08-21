#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,icnt,ocnt,sum=0,halfsum=0;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i){cin>>v[i];sum+=v[i];}
	sort(v.begin(),v.end());
	icnt=n/2;ocnt=n-icnt;
	for(int i=0;i<icnt;++i)halfsum+=v[i];
	printf("Outgoing #: %d\n",ocnt);
	printf("Introverted #: %d\n",icnt);
	printf("Diff = %d",sum-2*halfsum);
	return 0;
}
