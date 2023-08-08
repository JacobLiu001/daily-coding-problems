#include "includes/universal.h"
using namespace std;

int day30(const vector<int> &v) {
    ull ans = 0;
    const int n = v.size();
    int l = 0, r = n - 1;
    int leftMax = v[l], rightMax = v[r];
    while (l < r) {
        if (v[l] < v[r]) {
            ans += leftMax - v[l];
            ++l;
            leftMax = max(leftMax, v[l]);
        } else {
            ans += rightMax - v[r];
            --r;
            rightMax = max(rightMax, v[r]);
        }
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << day30(v) << endl;
    }
    return 0;
}
