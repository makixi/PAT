#include<iostream>
#include<string>
using namespace std;
string s; 
long long int dp[1000005][3];
int main() {
    cin >> s;
	int Len = s.size();
    for (int i = 0; i < Len; ++i) dp[i][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < Len; ++i) 
		dp[i][1] = s[i] == s[i - 1] ? dp[i - 1][1] : dp[i - 1][0] + dp[i - 1][1];
    dp[1][2] = 1;
    for (int i = 2; i < Len; ++i)
        if(s[i] == s[i - 1]) dp[i][2] = dp[i - 1][1] + dp[i - 1][2] - dp[i-2][1];
        else if (s[i] == s[i - 2]) dp[i][2] = dp[i - 1][1] + dp[i - 1][2] - 1;
        else dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
    cout << dp[Len - 1][0] + dp[Len - 1][1] + dp[Len - 1][2] << endl;
    return 0; 
}
