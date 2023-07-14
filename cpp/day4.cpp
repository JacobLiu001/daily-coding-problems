// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

int day4(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n; i++) {
        if (v[i] <= 0) {
            v[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = abs(v[i]);
        if (x >= 1 && x <= n) {
            if (v[x-1] > 0) {
                v[x-1] *= -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            return (i + 1);
        }
    }
    return n + 1;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << day4(v) << endl;
    }
    return 0;
}
