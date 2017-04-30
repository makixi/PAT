#include<iostream>  
#include<cstring>  
#include<map>  
#include<string>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
  
int main()  
{  
    int P_G, P_S, P_K;  
    int A_G, A_S, A_K;  
    char c;  
    while(cin>>P_G>>c>>P_S>>c>>P_K)  
    {  
        cin>>A_G>>c>>A_S>>c>>A_K;  
        int P_Sum = P_G*17*29 + P_S*29 + P_K;  
        int A_Sum = A_G*17*29 + A_S*29 + A_K;  
        int K = ( abs(P_Sum - A_Sum) )%29;  
        int S = ( abs(P_Sum - A_Sum) )/29%17;  
        int G =  ( abs(P_Sum - A_Sum) )/29/17;  
        if( P_Sum<=A_Sum )  
            cout<<G<<'.'<<S<<'.'<<K<<endl;  
        else  
            cout<<'-'<<G<<'.'<<S<<'.'<<K<<endl;  
    }  
    return 0;  
}  
