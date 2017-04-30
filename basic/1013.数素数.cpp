#include<stdio.h>
#include<math.h>
int main() {
void prime_num(int start, int end) {
	if (start <= end && end <= pow(10, 4)) {
	int i = 2;
	int count = 0, col = 0;
	int flag = 0;
	for (;; i++) {
	int j = 2;
	for (; j <= sqrt(i); j++) {
	if (i % j == 0) {
	flag = 1;
	break;
	}
	}
if (flag) {
flag = 0;
continue;
}
count++;
if (count >= start && count <= end - 1) {
if (++col % 10 == 0) {
printf("%d\n", i);
} else {
printf("%d ", i);
}
}
if (count == end) {
printf("%d", i);
break;
}
}
}
}
int M, N;
scanf("%d %d", &M, &N);
prime_num(M, N);
return 0;
}
