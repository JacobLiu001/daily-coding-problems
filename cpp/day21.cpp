#include "includes/universal.h"
using namespace std;

int day21(vector<pair<int, int>> v) {
    map<int, int> m;
    for (auto p: v) {
        ++m[p.first];
        --m[p.second];
    }
    int rolling = 0;
    int ans = rolling;
    for (auto p: m) {
        rolling += p.second;
        ans = max(rolling, ans);
    }
    return ans;
}

int main() {
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    cout << day21(v) << endl;
    return 0;
}
