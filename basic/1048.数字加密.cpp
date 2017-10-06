#include <iostream>  
#include <string>  
using namespace std;  
int main() {  
  string A,B,sum;  
  cin>>A>>B;  
  int i = A.length()-1, j = B.length()-1,count = 1;  
  if(i<j){  
    int c = j - i;  
    while(c){  
        A = '0'+A;  
        c--;  
    }  
  }  
  else{  
    int c = i - j;  
    while(c){  
        B = '0'+B;  
        c--;  
    }  
  }  
  i = A.length()-1, j = B.length()-1;  
  while(i!=-1&&j!=-1)  {  
    if(count%2==1)   
      sum = "0123456789JQK"[(A[i]+B[j]-'0'-'0')%13]+sum;  
	else sum = "1234567890123456789"[(B[j]-'0'-(A[i]-'0'))+9] +sum;   
    i--;j--;count++;  
  }   
  cout<<sum<<endl;  
  return 0;  
}  
