#include<iostream>
#include<string>
using namespace std;
int main(){
	int i,j,week,hour;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag1=false;
	for(i=0;i<(a.length()<=b.length()?a.length():b.length());++i)
		if(a[i]==b[i]&&('A'<=a[i]&&a[i]<='G')&&!flag1){flag1=true;week=i;}
		else if(a[i]==b[i]&&flag1&&(('A'<=a[i]&&a[i]<='N')||isdigit(a[i])))break;
	week=a[week]-'A'+1;
	if(isupper(a[i]))
		hour=a[i]-'A'+10;
	else
		hour=a[i]-'0';
	for(i=0;i<(c.length()<=d.length()?c.length():d.length());++i)
		if(c[i]==d[i]&&isalpha(c[i]))break;
	switch(week){
		case 1:cout<<"MON";break;
		case 2:cout<<"TUE";break;
		case 3:cout<<"WED";break;
		case 4:cout<<"THU";break;
		case 5:cout<<"FRI";break;
		case 6:cout<<"SAT";break;
		case 7:cout<<"SUN";break;
	}
	printf(" %02d:%02d",hour,i);
	return 0;
}
