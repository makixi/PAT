#include <iostream>  
#include <iomanip>  
#include <vector>  
using namespace std;  
int main()  
{  
  int N, i;  
  cin>>N;  
  vector<double> Nums(N);  
  double sum = 0;  
  for(i = 0; i < N; i++)  
    cin>>Nums[i];  
  for(i = 0; i < N; i++)  
    sum += (N - i)*Nums[i]*(i + 1);  
  cout<<fixed<<setprecision(2)<<sum;  
  
  system("pause");  
  return 0;  } 
