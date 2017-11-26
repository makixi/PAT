//÷«¡¶Ã‚∞…°£°£ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
char a[N], b[N];
int mx=0;
int main(){
	scanf("%s%s", a + 1, b + 1);
	int len = strlen(a + 1);
	for(int i=1;i<=len;++i)
		for (int j = 1, k = i; j <= len; j++){
			if (k <= len && a[j] == b[k]) k++;
			mx = max(mx, k - i);
		}
	cout<<(len-mx);
	return 0;
}
