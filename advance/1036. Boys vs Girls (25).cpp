#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct stu{
	char name[11];
	char gender;
	char id[11];
	int grade;
};
bool cmp1(stu a,stu b){
	if(a.gender!=b.gender)
		return a.gender<b.gender;
	else return a.grade>b.grade;
}
bool cmp2(stu a,stu b){
	if(a.gender!=b.gender)
		return a.gender>b.gender;
	else return a.grade<b.grade;
}
int main(){
	cin>>n;
	stu *s=(struct stu*)malloc(n*sizeof(struct stu)); 
	for(int i=0;i<n;++i){
		cin>>s[i].name>>s[i].gender>>s[i].id>>s[i].grade;
	}
	bool flag=1;
	int gradef,gradem;
	sort(s,s+n,cmp1);
	if(s[0].gender!='F') {
	cout<<"Absent"<<endl;flag=0;
	}
	else {
	cout<<s[0].name<<" "<<s[0].id<<endl;
	gradem=s[0].grade;
	}
	sort(s,s+n,cmp2);
	if(s[0].gender!='M') {
	cout<<"Absent"<<endl;flag=0;
	}
	else {
	cout<<s[0].name<<" "<<s[0].id<<endl;
	gradef=s[0].grade;
	}
	if(!flag) cout<<"NA";
	else cout<<abs(gradef-gradem);
	return 0;
}
