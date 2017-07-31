#include<iostream>
#include<cstring>
using namespace std;
void CountBit(char *a,int &inta){
	for(int i=0;i<strlen(a);++i)
		if(a[i]=='.'){
			inta=i;break;
		}
}
int main(){
	int n;
	char a[10000],b[10000],A[10000],B[10000];
	scanf("%d%s%s",&n,a,b);
	int inta=strlen(a),intb=strlen(b);
	CountBit(a,inta);CountBit(b,intb);
	int p=0,q=0;
	while(a[p]=='0'||a[p]=='.')++p;	//Non zero point
	while(b[q]=='0'||b[q]=='.')++q;
	if(inta>=p)inta-=p;
	else  inta+=1-p;	//index
	if(intb>=q)intb-=q;
	else intb+=1-q;
	if(p==strlen(a))inta=0;	//The string is zero
	if(q==strlen(b))intb=0;
	int indexa=0,indexb=0;
	while(indexa<n){
		if(a[p]!='.'&&p<strlen(a))
			A[indexa++]=a[p];
		else if(p>=strlen(a))
			A[indexa++]='0';		//complete zero
		++p;		//ignore decimal point
	}
	while(indexb<n){
		if(b[q]!='.'&&q<strlen(b))
			B[indexb++]=b[q];
		else if(q>=strlen(b))
			B[indexb++]='0';
		q++;
	}
	if(strcmp(A,B)==0&&inta==intb)
		printf("YES 0.%s*10^%d",A,inta);
	else 
		printf("NO 0.%s*10^%d 0.%s*10^%d",A,inta,B,intb);
	return 0;
}
