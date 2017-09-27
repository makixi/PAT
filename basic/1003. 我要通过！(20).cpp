#include <iostream>
#include <string>
using namespace std;
bool judge(string str) {
    int len = str.length();
    if (len <= 2)return false;
    bool book[3] = {false};
    for (int i = 0; i < len; i++) {
        if(str[i] == 'P')book[0] = true;
        else if(str[i] == 'A')book[1] = true;
        else if(str[i] == 'T')book[2] = true;
        else
            return false;
        if (str[i] == 'P') {
            for (int j = 0; j < i; j++) if (str[j] != 'A')return false;
            if (str [i+1] != 'A')return false;
            for (int k = i + 2; k < len; k++) 
                if (str[k] != 'A') {
                    if (str[k] != 'T') return false;
                    if ((len - 1 - k) != ((k - 1 - i) * i))return false;
                    for (int m = k + 1; m < len; m++) if (str[m] != 'A')return false;
                }
        }
    }
    if(book[0] == false || book[1] == false || book[2] == false)
        return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(judge(s) == true)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
