#include "includes/universal.h"
using namespace std;

string day34(const string &s) {
    const int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0x7fffffff));

    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
        dp[i - 1][i] = !(s[i-1] == s[i]);
    }

    for (int d = 2; d < n; d++) {
        for (int l = 0; l < n - d; l++) {
            int r = l + d;
            dp[l][r] = (s[l] == s[r] ? dp[l+1][r-1] : 1 + min(dp[l+1][r], dp[l][r-1]));
        }
    }

    cout << dp[0][n-1] << endl;
    // dp[i][j] === Min no. insertions to make s[i..j] (inclusive) a palindrome

    string ret(n + dp[0][n-1], '#');
    int l = 0, r = n - 1;
    int writeHeadL = 0;
    int writeHeadR = n + dp[0][n-1] - 1;

    while (l <= r) {
        if (s[l] == s[r]) {
            ret[writeHeadL++] = s[l++];
            ret[writeHeadR--] = s[r--];
        } else if (dp[l + 1][r] < dp[l][r - 1] || (dp[l + 1][r] == dp[l][r - 1] && s[l] < s[r])) {
            ret[writeHeadL++] = ret[writeHeadR--] = s[l++];
        } else {
            ret[writeHeadL++] = ret[writeHeadR--] = s[r--];
        }
    }
    return ret;
}

int main() {
    string s;
    while (cin >> s) {
        cout << day34(s) << endl;
    }
}
