#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    double R1,P1,R2,P2;
    scanf("%lf%lf%lf%lf",&R1,&P1,&R2,&P2);
    double P=R1*R2*(cos(P1+P2));
    double R=R1*R2*(sin(P1+P2));
    if(P>-0.005&&P<0)
        printf("0.00");
    else 
        printf("%.2lf",P);
    if(R>-0.005&&R<0)
        printf("+0.00i");
    else if(R<=-0.005) 
        printf("%.2lfi",R);
    else printf("+%.2lfi",R);
    return 0;
}
