// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

bool in_range(string s) {
    if (s.starts_with('0')) {
        return false;
    }
    int x = stoi(s);
    return (1 <= x && x <= 26);
}

int day7(const string &encoded) {
    vector<int> dp(encoded.size() + 1, 0);
    
    dp[0] = 1;

    for (int i = 1; i <= (int) encoded.size(); i++) {
        if (encoded[i-1] != '0') {
            dp[i] = dp[i-1];
        }
        if (i >= 2) {
            if (in_range(encoded.substr(i-2, 2))) {
                dp[i] += dp[i-2];
            }
        }
    }
    return dp.back();
}

int main() {
    string s;
    while (cin >> s) {
        cout << day7(s) << endl;
    }
}