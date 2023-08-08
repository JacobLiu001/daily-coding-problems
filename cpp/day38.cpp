#include "includes/universal.h"
using namespace std;

void NQueens(ull &ans, int n, int l, bool *space) {
    // needs space to have a size of at least 5 * n
    if (l == n) {
        ++ans;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!space[i] && !space[n + i - l + n] && !space[3 * n + i + l]) {
            space[i] = true;
            space[n + i - l + n] = true;
            space[3 * n + i + l] = true;
            NQueens(ans, n, l + 1, space);
            space[i] = false;
            space[n + i - l + n] = false;
            space[3 * n + i + l] = false;
        }
    }
}

ull day38(int n) {
    ull ans = 0;
    bool *space = new bool[5 * n];
    memset(space, 0, 5 * n * sizeof(bool));
    NQueens(ans, n, 0, space);
    delete[] space;
    return ans;
}


int main() {
    int n;
    while (cin >> n) {
        cout << day38(n) << endl;
    }
    return 0;
}
