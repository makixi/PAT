#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
void upadjust(int i){
	if(i==1)return;
	while(i!=1){
		if(v[i]<v[i/2]){
			swap(v[i],v[i/2]);
			i/=2;
		}else break;
	}
}
int main(){
	int n,m,a,b,ai,bi;
	string str;
	cin>>n>>m;
	v.resize(n+1);
	for(int i=1;i<=n;++i){
		cin>>v[i];
		upadjust(i);
	}
	while(m--){
		cin>>a>>str;
		if(str=="and"){//sibilings
			cin>>b>>str;cin>>str;
			for(int i=1;i<=n;++i){
				if(v[i]==a)ai=i;
				if(v[i]==b)bi=i;
			}
			if(ai>bi)swap(ai,bi);
			if(ai%2==0&&bi-ai==1)printf("T\n");
			else printf("F\n");
		}else{
			cin>>str;
			if(str=="a"){//child
				cin>>str>>str>>b;
				for(int i=1;i<=n;++i){
					if(v[i]==a)ai=i;
					if(v[i]==b)bi=i;
				}
				if(ai==bi*2||ai==bi*2+1)printf("T\n");
				else printf("F\n");
			}else{
				cin>>str;
				if(str=="root"){
					if(v[1]==a)printf("T\n");
					else printf("F\n");
				}else{
					cin>>str>>b;
					for(int i=1;i<=n;++i){
						if(v[i]==a)ai=i;
						if(v[i]==b)bi=i;
					}
					if(ai*2==bi||ai*2+1==bi)printf("T\n");
					else printf("F\n");
				}
			}
		}
	}
	return 0;
}
