#include<iostream>
#include<algorithm>
using namespace std;
int *origin, *now,*as;
void DownAdjust(int high) {
    int i = 0, j = i * 2+1;
    while (j <= high) {
        if (j + 1 <= high&&now[j] < now[j+1])j += 1;
        if (now[i] < now[j]) {
            swap(now[i], now[j]);
            i = j; 
			j = i * 2 + 1;
        }
        else break;
    }
}
int main() {
    int n,i,j;
    cin >> n;
    origin = new int[n];
    now = new int[n];
    as=new int[n];//after sort
    for (i = 0; i < n; ++i) {cin >> origin[i];as[i]=origin[i];}
    for (i = 0; i < n; ++i) cin >> now[i];
    for (i = 0; i < n - 1 && now[i] <= now[i + 1]; ++i);
    for (j = i + 1; origin[j] == now[j] && j < n; ++j);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(now, now + i + 2);
    }
    else {
        cout << "Heap Sort" << endl;
        sort(as,as+n);
        int p = n;
        while (p >= 2 && now[p-1] == as[p-1])p--; //从后面找到第一个无序的点
		swap(now[0], now[p-1]); 
        DownAdjust(p - 2);
    }
    for (i = 0; i < n-1; ++i)cout << now[i] << " ";
    cout << now[n - 1];
    return 0;
}
