#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int n,a,cnt=0,res;
	set<int> s;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		res=0;
		do{
			res+=a%10;
			a/=10;
		}while(a);
		s.insert(res);	
	}
	cout<<s.size()<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();++it){
		if(it!=s.begin())cout<<" ";
		cout<<*it;
	}
	return 0;
}
