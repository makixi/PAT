#include <iostream>  
#include <vector>  
#include <algorithm>  
#define MAX 1000  
using namespace std;
typedef struct {
	double save;
	double money;
	double price;
} Bing;
Bing bing[MAX];
int cmp(const void *a, const void *b) {
	if ((*(Bing *)a).price < (*(Bing *)b).price)
		return 1;
	else
		return 0;
}
int main() {
	int N;
	int D;
	cin >> N >> D;
	for (int i = 0; i < N; i++) 
		cin >> bing[i].save;
	for (int i = 0; i < N; i++) {
		cin >> bing[i].money;
		bing[i].price = bing[i].save / bing[i].money;
	}
	sort(bing,bing+sizeof(Bing),cmp );
	int now_save = 0;
	double sum = 0.0;
	int index = 0;
	while (now_save < D && index < N) {
		if (D >= bing[index].save) {
			D = D - bing[index].save;
			sum = sum + bing[index].money;
		}
		else {
			sum = sum + D * bing[index].price;
			D = 0;
		}
		index++;
	}
	printf("%.2lf", sum);
	return 0;
}
