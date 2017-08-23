#include<iostream>
#include<stack>
#include<string>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int maxn=100001;
int c[maxn];
stack<int> s;
void update(int x,int v){
	for(int i=x;i<maxn;i+=lowbit(i))
		c[i]+=v;
}
int getsum(int x){
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i))
		sum+=c[i];
	return sum;
}
void PeekMedian(){
	int left=1,right=maxn,mid,k=(s.size()+1)/2;
	while(left<right){
		mid=(left+right)/2;
		if(getsum(mid)>=k)right=mid;
		else  left=mid+1;
	}
	printf("%d\n",left);
}
int main(){
	int n,a;
	//string str;
	char str[15];
	scanf("%d",&n);
	while(n--){
		//cin>>str;
		scanf("%s",str);
		if(str[1]=='o'){//pop
			if(s.empty())printf("Invalid\n");
			else{
				update(s.top(),-1);
				printf("%d\n",s.top());
				s.pop();
			}
		}else if(str[1]=='e'){//peekmedian
			if(s.empty())printf("Invalid\n");
			else PeekMedian();
		}else{//push
			cin>>a;
			s.push(a);
			update(a,1);
		}
	}
	return 0;
}
