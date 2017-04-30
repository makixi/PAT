#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000

int main() {
	string str;
	int max=0;
	char maxal;
	int num[MAX] = { 0 };
	getline(cin, str);
	for (int i = 0; i<str.size(); i++) {
		if (isalpha(str[i])) {
			if (isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
			num[str[i]]++;
		}
		
	}
	 for(int i='a';i<='z';i++)  
    {  
        if(num[i]>max)  
        {  
            max=num[i];  
            maxal=char(i);  
        }  
    } 
	cout << maxal << " " << max;
}
