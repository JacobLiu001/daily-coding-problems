// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

vector<int> day2(vector<int> l) {
    vector<int> res(l.size(), 1);
    int n = l.size();
    ull prod = 1;

    for (int i = 0; i < n; i++) {
        res[i] = prod;
        prod *= l[i];
    }

    prod = 1;

    for (int i = n - 1; i >= 0; i--) {
        res[i] *= prod;
        prod *= l[i];
    }

    return res;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << day2(v) << endl;
    }
}
