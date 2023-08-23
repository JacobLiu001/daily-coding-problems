#include "includes/universal.h"
using namespace std;

int countInv(int *arr, int l, int r, int *scrap) {
    if (r - l <= 1) {
        return 0;
    }
    int m = (l + r) >> 1;
    int ans = 0;
    ans += countInv(arr, l, m, scrap);
    ans += countInv(arr, m, r, scrap);
    // one can copy the second half of arr into scrap
    // and merge the first half of arr with scrap into arr from right to left
    // this can save about half of the scrap space
    // but I can't be bothered, so here is the more naive implementation

    int lHead = l, rHead = m;
    int writeHead = 0;
    while (lHead < m && rHead < r) {
        if (arr[lHead] <= arr[rHead]) {
            scrap[writeHead++] = arr[lHead++];
        } else {
            scrap[writeHead++] = arr[rHead++];
            ans += (m - lHead);
        }
    }
    while (lHead < m) {
        scrap[writeHead++] = arr[lHead++];
    }
    while (rHead < r) {
        scrap[writeHead++] = arr[rHead++];
    }
    memcpy(arr + l, scrap, writeHead * sizeof(int));
    return ans;
}

int main() {
    int a[114514];
    int scrap[114514];
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = countInv(a, 0, n, scrap);
        cout << ans << endl;
    }
    return 0;
}
