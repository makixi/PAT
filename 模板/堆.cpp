//---------------大顶堆
//---------向上调整
void upAdjust(int i) {
	if(i == 1) return ;
	while(i != 1)
		if(heap[i] > heap[i / 2]) {
 			swap(heap[i], heap[i / 2]);
			i = i / 2;
		} else break;
}
for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    upAdjust(i);
}
//-------向下调整
const int maxn = 100;
int heap[maxn], n = 10;
void downAdjust(int low, int high) {
	int i = 1ow, j = i * 2;
	while(j <= high) {
		if(j + 1 <= high && heap[j + 1] > heap[j]) j = j + 1;
		if(heap[j] > heap[i]) {
			swap(heap[i], heap[j]);
			i = j; 
			j = i * 2;
		} else break;
	}
}
void createHeap() {
	for(int i = n / 2; i >= 1; i--)
		downAdjust(i, n);
}
//-----------堆排序
void heapSort() {
	createHeap();
	for(int i = n; i >= 2; i--) {
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
	}
}
//--------删除堆顶元素
void deleteTop() {
	heap[1] = heap[n--];
	downAdjust(1, n);
}
//--------增加一个元素
void insert(int x) {
	heap[++n] = x;
	downAdjust(1, n);
}
