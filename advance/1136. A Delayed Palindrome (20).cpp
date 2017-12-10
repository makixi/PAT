#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
bool check(char aa[]){
    int len = strlen(aa);
    for(int i=0;i<len-1-i;i++){
        if(aa[i]!=aa[len-1-i])return 0;
    }
    return 1;
}//回文检验
int main()
{
    gets(a);
    bool f=0;
    int c=0;
    while(!check(a)){
        if( c==10 ){
            printf("Not found in 10 iterations.");
            f=1;
            break;
        }
        int lena = strlen(a)-1,tag=0;
        for(int i=lena;i>=0;i--){
            b[tag++] = a[i];
        }//将原数逆序 
        b[tag] = '\0';

        printf("%s + %s",a,b);
        int i,y = 0;
        for(i=0;i<=lena;i++){//模拟加法
            int dig = (a[i]-'0')+(b[i]-'0')+y;
            a[i] = '0'+dig%10;
            if(dig>9)y=1;
            else y = 0;
        }
        if(y)a[i] = '0'+y,a[++i] = '\0';//余数处理
        else a[i] = '\0';//行尾结束控制
        i--;//找回重点
        for(int j=0;j<i-j;j++){//把顺序换回来
            swap(a[j],a[i-j]);
        }       
        printf(" = %s\n",a);
        c++;
    }
    if(!f)printf("%s is a palindromic number.",a);
    return 0;
}
