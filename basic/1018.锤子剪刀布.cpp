#include<iostream>
using namespace std;

typedef struct result {
	int success=0;
	int ping=0;
	int fail=0;
	int c=0;
	int j=0;
	int b=0;
	char ges;
}res;
res jia, yi;
int x[3][3] = { 0,-1,1,1,0,-1,-1,1,0 };
int change(char k) {
	switch (k) {
	case 'C':return 0; 
	case 'J':return 1; 
	case 'B':return 2;
	default:exit(0);
	}
	return 0;
}
void write(int k,res &bing) {
	switch (k) {
	case 1:bing.j++; break;
	case 2:bing.b++; break;
	case 0:bing.c++; break;
	default:break;
	}
}
void judge(int a, int b) {
	switch (x[a][b]){
	case -1:jia.success++; yi.fail++; write(a,jia); break;
	case 0:jia.ping++; yi.ping++; break;
	case 1:jia.fail++; yi.success++; write(b,yi); break;
	default:break;
	}
}
void compare(res &bing) {
	if (bing.b >= bing.c&&bing.b >= bing.j) bing.ges = 'B';
	else if (bing.c >= bing.b&&bing.c >= bing.j) bing.ges = 'C';
	else bing.ges = 'J';
}
void output(res &bing) {
	cout << bing.success << " " << bing.ping << " " << bing.fail << endl;
	compare(bing);
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char a, b;
		cin >> a >> b;
		int a1=change(a);
		int b2=change(b);
		judge(a1, b2);
	}
	output(jia);
	output(yi);
	cout << jia.ges << " " << yi.ges;
	return 0;
}
