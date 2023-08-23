#include "includes/universal.h"
using namespace std;

// literally the same, just with a prefix sum.
/* int day47(const vector<int> &v) {
    int rollingMin = INT_MAX;
    int ans = 0;
    for (auto x: v) {
        // assuming you can buy and sell on the same day.
        rollingMin = min(rollingMin, x);
        ans = max(ans, x - rollingMin);
    }
    return ans;
} */


int day49(const vector<int> &v) {
    int partialSum = 0;
    int rollingMin = INT_MAX;
    int ans = 0;
    for (auto x: v) {
        partialSum += x;
        rollingMin = min(rollingMin, partialSum);
        ans = max(ans, partialSum - rollingMin);
    }
    return ans;
}


int main() {
    assert(day49({34, -50, 42, 14, -5, 86}) == 137);
    assert(day49({-5, -1, -8, -9}) == 0);
    return 0;
}
