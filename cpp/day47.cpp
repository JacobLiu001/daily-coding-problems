#include "includes/universal.h"
using namespace std;

int day47(const vector<int> &v) {
    int rollingMin = INT_MAX;
    int ans = 0;
    for (auto x: v) {
        // assuming you can buy and sell on the same day.
        rollingMin = min(rollingMin, x);
        ans = max(ans, x - rollingMin);
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cout << day47(v) << endl;
    }
    return 0;
}
