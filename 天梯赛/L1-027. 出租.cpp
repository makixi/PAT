#include <iostream> 
#include <cstdio>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
	return a>b;
}
int main() {
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    vector<int> index,arr2;
    set<int> arr;
    for(int i=0;i<s.length();++i)
    	arr.insert(s[i]);
    for(set<int>::iterator it=arr.begin();it!=arr.end();++it)
    	arr2.push_back(*it);
    sort(arr2.begin(),arr2.end(),cmp);
    for(int i=0;i<s.length();++i)
    	for(int j=0;j<arr2.size();++j)
    		if(arr2[j]==s[i]){
    			index.push_back(j);
    			break;
			}
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<arr2.size();++i){
    	if(i)cout<<",";
    	cout<<(char)arr2[i];
	}
	cout<<"};\n";
	cout<<"int[] index = new int[]{";
	for(int i=0;i<index.size();++i){
    	if(i)cout<<",";
    	cout<<index[i];
	}
	cout<<"};";
	return 0;
}
