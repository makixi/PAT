#include<bits/stdc++.h>
using namespace std;
int p[4];
int main() {
    ios::sync_with_stdio(false);
	int pa,pb;
	cin>>pa>>pb>>p[1]>>p[2]>>p[3];
	if(pa>pb&&(p[1]+p[2]+p[3]<=2))
		cout<<"The winner is a: "<<pa<<" + "<<(3-p[1]-p[2]-p[3]);
	else if(pb>pa&&(p[1]+p[2]+p[3]>0))
		cout<<"The winner is b: "<<pb<<" + "<<(p[1]+p[2]+p[3]);
	else if(pa<pb&&(p[1]+p[2]+p[3])==0){
		cout<<"The winner is a: "<<pa<<" + "<<(3-p[1]-p[2]-p[3]);
	else if(pb<pa&&(p[1]+p[2]+p[3])==3)
		cout<<"The winner is b: "<<pb<<" + "<<(p[1]+p[2]+p[3]);
    return 0; 
}
