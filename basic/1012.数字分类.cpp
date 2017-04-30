#include<stdio.h>
#define MAX 1000
int main()
{
	int N;
	int a1=0, a2=0, a3=0,a5=0,count2=0;
	double a4 = 0.0,count4=0.0;
	int a[MAX],count[MAX];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 5 == 0 && a[i] % 2 == 0) a1 += a[i];
		if (a[i] % 5 == 1) {
			count[count2++]=a[i];
		}
		if (a[i] % 5 == 2) a3++;
		if (a[i] % 5 == 3) { a4 = a4 + a[i]; count4=count4+1.0; }
		if (a[i] % 5 == 4 && a[i] > a5)a5 = a[i];
	}
	for(int i=0;i<count2;i++){
		if(i%2==0) a2+=count[i];
		else a2-=count[i];
	}
	if(count4!=0.0) a4 = a4 / count4;
	if (a1 == 0) printf("N ");
	else printf("%d ", a1);
	if (count2 == 0) printf("N ");
	else printf("%d ", a2);
	if (a3 == 0) printf("N ");
	else printf("%d ", a3);
	if (a4 == 0) printf("N ");
	else printf("%.1f ", a4);
	if (a5 == 0) printf("N");
	else printf("%d", a5);
		return 0;
}
