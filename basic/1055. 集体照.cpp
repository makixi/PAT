#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int height;
};
int cmp(struct node a, struct node b) {
    if(a.height != b.height)return a.height > b.height;
    return a.name < b.name;
}
int main() {
    int n, k, m;
    cin >> n >> k;
    struct node *stu = new struct node [n];
    for(int i = 0; i < n; i++) {
        cin >> stu[i].name;
        cin >> stu[i].height;
    }
    sort(stu, stu + n, cmp);
    int t = 0;
    int row = k;
    while(row) {
        if(row == k) m = n - n / k * (k - 1);
        else m = n / k;
        string *stemp = new string [m];
        stemp[m / 2] = stu[t].name;
        // 左边一列
        int j = m / 2 - 1;
        for(int i = t + 1; i < t + m; i = i + 2) stemp[j--] = stu[i].name;
        // 右边一列
        j = m / 2 + 1;
        for(int i = t + 2; i < t + m; i = i + 2) stemp[j++] = stu[i].name;
        // 输出当前排
        cout << stemp[0];
        for(int i = 1; i < m; i++)  cout << " " << stemp[i];
        cout << endl;
        t = t + m;
        row--;
        delete [] stemp;//这句话很重要。。。一开始没写，输出结果都是各种ASCII码。。
    }
    delete [] stu;
    return 0;
}
