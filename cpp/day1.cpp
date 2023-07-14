// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

bool day1(vector<int> l, int k) {
    unordered_set<int> encountered; // Hash table
    for (auto x: l) {  // Go C++ 11!
        if (encountered.count(k - x)) {
            return true;
        }
        encountered.insert(x);
    }
    return false;
}


int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << (day1(v, k) ? "True" : "False") << endl;
    }
}
