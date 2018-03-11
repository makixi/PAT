#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long LL;
const int maxn = 5e2 + 10;
const int mod = 1e9 + 7;
int n;
LL f[maxn][maxn][2];//����i���ڵ�����Ϊj�ĸ�Ϊk����������
//�����ֻ���ǴӸ��ڵ㵽Ҷ�ӽڵ㣨����Ҷ�ӽڵ㣩�ĺڵ�������k��Ϊ0��1,0�Ǻ죬1�Ǻ� 
LL s[maxn][maxn];
int main(){
  	f[1][0][0] = f[0][0][1] = 1;
  	for (int i = 1; i < maxn; i++)
    	for (int j = 1; j <= min(i, 8); j++){
      		f[i][j][0] = f[i][j][1] = 0;
      		for (int k = 0; k < i; k++){
        		(f[i][j][1] += (f[k][j - 1][0] + f[k][j - 1][1]) * 
					(f[i - k - 1][j - 1][0] + f[i - k - 1][j - 1][1]) % mod) %= mod;
        		(f[i][j][0] += f[k][j][1] * f[i - k - 1][j][1] % mod) %= mod;
      		}
      		s[i][j] = (s[i][j - 1] + f[i][j][1]) % mod;
    	}
  	scanf("%d", &n); 
	printf("%d\n", s[n][min(n, 8)]);
  	return 0;
}
