#include<iostream>
#include<iomanip> 
#include<algorithm>
using namespace std;
#define MAX 100000
struct Node {
	int add;
	int key;
	int next;
	bool flag;
}node[MAX];
bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}
int main() {
	int first,n,a,b,c,cnt=0;
	cin >> n >> first;
	for (int i = 0; i < n; ++i) {
		cin >> a>>b>>c;
		node[a].add = a;
		node[a].key = b;
		node[a].next = c;
	}
	for (int i = first; i != -1; i = node[i].next) {
		node[i].flag = true;
		cnt++;
	}
	if (cnt == 0) cout << "0 -1";
	else {
			sort(node, node + MAX, cmp);
			cout<<cnt<<" ";
			cout<<setfill('0')<<setw(5)<<node[0].add<<endl;
			for (int i = 0; i < cnt; i++) {
				cout<<setfill('0')<<setw(5)<<node[i].add;
				cout<<" "<<node[i].key<<" ";
				if (i != cnt - 1)
					cout<<setfill('0')<<setw(5)<<node[i+1].add<<endl;
				else
					cout<<"-1";
			}
		}
	
	return 0;
}
