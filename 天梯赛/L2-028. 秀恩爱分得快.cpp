#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int maxn=2005;
double e[maxn][maxn];
int change(char *s){
	int i=0,len=strlen(s);
	int f=1,sum=0;
	if(s[i]=='-')f=-1,++i;
	while(i<len){
		sum=sum*10+(s[i]-'0');
		++i;
	}
	return sum*f;
}
int main(){
	ios::sync_with_stdio(false);
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
    	int k;
    	scanf("%d",&k);
    	vector<int> boy,girl;
    	for(int i=0;i<k;++i){
    		char s[8];
    		scanf("%s",s);
    		int id=change(s);
    		if(s[0]=='-')id+=999;//female
    		else id+=1000;//male
    		if(id<1000)girl.push_back(id);
    		else boy.push_back(id);
		}
		for(int i=0;i<girl.size();++i)
			for(int j=0;j<boy.size();++j){
				e[girl[i]][boy[j]]+=1.0/k;
				e[boy[j]][girl[i]]+=1.0/k;
			}
	}
	char sa[8],sb[8];
	scanf("%s %s",sa,sb);
	int aa=change(sa),bb=change(sb),cuta,cutb;
	if(sa[0]=='-')aa+=999,bb+=1000,cuta=999,cutb=1000;
	else aa+=1000,bb+=999,cuta=1000,cutb=999;
	vector<int> a,b;
	double resa=0,resb=0;
	if(aa<1000){//find boy
		for(int i=1000;i<=1000+n;++i){
			if(e[aa][i]>resa){
				resa=e[aa][i];
				a.clear();
				a.push_back(i);
			}else if(e[aa][i]==resa){
				a.push_back(i);
			}
		}
		for(int i=999;i>=1000-n;--i){
			if(e[bb][i]>resb){
				resb=e[bb][i];
				b.clear();
				b.push_back(i);
			}else if(e[bb][i]==resb){
				b.push_back(i);
			}
		}
	}else{//find girl
		for(int i=999;i>=1000-n;--i){
			if(e[aa][i]>resa){
				resa=e[aa][i];
				a.clear();
				a.push_back(i);
			}else if(e[aa][i]==resa){
				a.push_back(i);
			}
		}
		for(int i=1000;i<=1000+n;++i){
			if(e[bb][i]>resb){
				resb=e[bb][i];
				b.clear();
				b.push_back(i);
			}else if(e[bb][i]==resb){
				b.push_back(i);
			}
		}
	}
	if(resa==resb&&e[aa][bb]==resa){
		//cout<<aa-cuta<<" "<<bb-cutb;
		if(aa==999)cout<<"-0";
		else cout<<aa-cuta;
		cout<<" ";
		if(bb==999)cout<<"-0";
		else cout<<bb-cutb;
		return 0;
	}
	for(int i=0;i<a.size();++i){
		if(aa==999)cout<<"-0";
		else cout<<aa-cuta;
		cout<<" ";
		if(a[i]==999)cout<<"-0";
		else cout<<a[i]-cutb;
		cout<<endl;
	}
	for(int i=0;i<b.size();++i){
		if(bb==999)cout<<"-0";
		else cout<<bb-cutb;
		cout<<" ";
		if(b[i]==999)cout<<"-0";
		else cout<<b[i]-cuta;
		cout<<endl;
	}
    return 0;
}s
