#include "includes/universal.h"
using namespace std;

ull day12(int n, const vector<int>& steps) {
    vector<ull> ways(n+1, 0); // ways[i] == number of ways climb i steps
    ways[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (auto delta: steps) {
            if (i - delta >= 0) {
                ways[i] += ways[i-delta];
            }
        }
    }
    return ways[n];
}

int main() {
    vector<int> steps{1,2};
    int n;
    while (cin >> n) {
        cout << day12(n, steps) << endl;
    }
    return 0;
}