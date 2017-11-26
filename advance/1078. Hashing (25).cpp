#include<iostream>
#include<vector>
using namespace std;
bool is_prime(int n){
	if(n<=1)return false;	//很重要~别忘了~ 第二个测试点
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
int find_prime(int n){
	for(int i=n+1;;++i)
		if(is_prime(i))return i;
}
int main(){
	int m,n,step;
	cin>>m>>n;
	if(!is_prime(m))m=find_prime(m);
	vector<bool> v(m,false);
	for(int i=0;i<n;++i){
		if(i)cout<<" ";
		int tmp,key;
		cin>>key;
		tmp=key%m;
		if(v[tmp]){
			for(step=1;step<m;++step){
				int a=key+step*step;
				if(!v[a%m]){
					v[a%m]=true;
					cout<<a%m;
					break;
				}
			}
			if(step==m)cout<<"-";
		}
		else{
			v[tmp]=true;
			cout<<tmp;
		}
	}
	return 0;
}
