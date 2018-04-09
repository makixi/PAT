#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int maxn=105;
int m[maxn];
bool mark[maxn];
int main(){
    int n,len=0,sum=0,len1=0;
    vector<int>a[105];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
        m[i]*=10;
        sum+=m[i];
    }
    for(int i=1;true;){
        int t=0;
        while(t<n){
            if(a[t].size()<m[t]){
                len1++;
                a[t].push_back(i);
                if(len+1==n) i+=2;
                else i+=1;
            }
            if(!mark[t]&&a[t].size()>=m[t]){
                mark[t]=1;
                len++;
            }
            t++;
        }
        if(len1==sum)break;
    }
    for(int i=0;i<n;i++){
        cout<<"#"<<(i+1)<<endl;
        for(int j=0;j<a[i].size();j++){
            if(j%10)cout<<" ";
            printf("%d",a[i][j]);
            if(j%10==9)cout<<endl;
        }
        if(a[i].size()%10)cout<<endl;
    }
    return 0;
}
