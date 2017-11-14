#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=100005;
ll dp[maxn],base[maxn];
char str[maxn];
int main(){
    ll res=0;
    for(int i=1;i<maxn-1;i++){
        res=res*10+1;
        if(res>=mod)res%=mod;
        base[i]=res;
    }
    scanf("%s",str+1);
    int len=strlen(str+1);
    reverse(str+1,str+len+1);
    for(int i=1;i<=len;i++)dp[i]=(dp[i-1]+((str[i]-'0')*base[i])%mod)%mod;
    res=0;
    for(int i=1;i<=len;i++)if(str[i]!='0')res=(res+dp[i])%mod;
    printf("%lld\n",res);
    return 0;
}

