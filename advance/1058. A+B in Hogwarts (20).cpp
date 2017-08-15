#include<iostream>
using namespace std;
int main() {
	long long a1, a2, a3, b1, b2, b3;
	long long whole = 0;
	scanf("%lld.%lld.%lld", &a1, &a2, &a3);
	scanf("%lld.%lld.%lld", &b1, &b2, &b3);
	whole = (a1 + b1) * 17 * 29 + (a2 + b2) * 29 + (a3 + b3);
	printf("%lld.%lld.%lld\n", whole/29/17,whole/29%17 ,whole%29 );
	return 0;
}
