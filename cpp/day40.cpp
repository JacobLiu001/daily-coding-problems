#include "includes/universal.h"
using namespace std;

int day40(const vector<int> &v) {
    // gist: count number of occurences by each bit and mod 3.
    // instead of modding 3, we use the cycle 00 -> 01 -> 11 -> 00 (cycle)
    unsigned int reg1 = 0, reg2 = 0;
    for (auto &x: v) {
        reg1 ^= x & reg2;
        reg2 ^= x & (~reg1);
    }
    return (reg1 | reg2);
}

int main() {
    cout << day40({1, 1, 1, 2, 6, 6, 6}) << endl;
    return 0;
}
