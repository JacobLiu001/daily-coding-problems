#include "includes/universal.h"
using namespace std;


/**
 * @brief Returns a random integer in the range [lo, hi)
 */
int randint(int lo, int hi) {
    static random_device rd;
    static mt19937 rng(rd());
    static uniform_int_distribution dist(0, INT_MAX);

    return dist(rng) % (hi - lo) + lo;
}

template<typename LegacyInputIterator>
LegacyInputIterator pick_random(LegacyInputIterator begin, LegacyInputIterator end) {
    int cnt = 0;
    LegacyInputIterator res = begin;
    while (begin != end) {
        ++cnt;
        if (!randint(0, cnt)) {
            res = begin;
        }
        ++begin;
    }
    return res;
}

int main() {
    vector<int> v({1, 2, 3, 4, 5});
    map<int, int> hist;
    for (int i = 0; i < 5000; i++) {
        int x = *pick_random(v.begin(), v.end());
        ++hist[x];
    }
    // expect every value to be around 1000
    for (auto p: hist) {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}
