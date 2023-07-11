// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

int day8(const vector<int> &v) {
    int ans_with_last = 0;
    int ans_without_last = 0;
    for (auto x: v) {
        int tmp = ans_with_last;
        ans_with_last = x + ans_without_last;
        ans_without_last = max(tmp, ans_without_last);
    }
    return max(ans_with_last, ans_without_last);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << day8(v) << endl;
    }
    return 0;
}