#include "includes/universal.h"
using namespace std;


// what is this monstrosity...
vector<int> day42(const vector<int> &v, int k) {
    vector<vector<bool>> dp(v.size(), vector(k + 1, false));
    vector<int> ans;
    if (v[0] <= k) {
        dp[0][v[0]] = true;
    }
    for (int i = 1; i < v.size(); ++i) {
        int x = v[i];
        dp[i] = dp[i - 1];
        if (x > k) {
            continue;
        }
        dp[i][x] = true;
        for (int j = k; j >= x; --j) {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - x];
        }
    }
    if (!dp[v.size() - 1][k]) {
        return ans; // impossible, return null
    }
    int pos = v.size() - 1;
    while (k) {
        if (dp[pos][k] && k >= v[pos] && (pos == 0 || dp[pos - 1][k - v[pos]])) {
            ans.push_back(v[pos]);
            k -= v[pos];
        }
        --pos;
    }
    return ans;
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << day42(v, k) << endl;
    }
    return 0;
}
