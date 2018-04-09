#include <cstdio>
using namespace std;
int N,sz[100010];
int main() {
	scanf("%d\n", &N);
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		if (t > 0 && t<100010) sz[t] = 1;
	}
	for (int i = 1; i < 100010; i++) 
		if (sz[i] == 0) {
			printf("%d", i);
			break;
		}
	return 0;
}
