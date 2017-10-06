#include<iostream>  
#include<fstream>  
#include<string> 
#include<map>  
using namespace std;  
struct node  {  
    string ID;  
    int n1, n2;  
};  
map<int,node>Map;  
int main()  {  
    int N,n,M;  
    node Node;  
    cin>>N;  
    while(N--)  {  
        cin>>Node.ID>>Node.n1>>Node.n2;  
        map[Node.n1]=Node;  
    }  
    cin>>M;  
    while(M--)  {  
        int tmp;  
        cin>>tmp;  
        cout<<Map[tmp].ID<<" "<<Map[tmp].n2<<endl;  
    }  
    return 0;  
}  
