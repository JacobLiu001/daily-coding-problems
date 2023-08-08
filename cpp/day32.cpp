#include "includes/universal.h"
using namespace std;

bool day32(vector<vector<double>> v) {
    for (auto &r: v) {
        for (auto &x: r) {
            x = log(x);
        }
    }

    // use any negative-cycle detection method you like.
    const int n = v.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i][i] < 0) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<double>> v = {
        {1, 2, 3, 4},
        {0.5, 0.1, 0.9, 100},
        {1, 2, 3, 4},
        {0.5, 0.1, 0.9, 100},
    };
}
