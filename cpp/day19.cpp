#include "includes/universal.h"
using namespace std;

int day19(vector<vector<int>> mat) {
    const int INF = 0x7fffffff;
    int N = mat.size();
    int K = mat[0].size();

    // dp[i][j] = min cost of painting the first i houses,
    // with the i-th house being painted as colour j.

    // dp[i][j] = mat[i][j] + min{dp[i-1][k]} (k != j)
    // We use the optimization that since we only use the previous 1 row,
    // we can discard older results and alternate between only two rows.
    vector<vector<int>> dp(2, vector<int>(K, 0));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            dp[i & 1][j] = mat[(i & 1) ^ 1][j];
            int best = INF;
            for (int k = 0; k < K; k++) {
                if (k == j) {
                    continue;
                }
                best = min(dp[(i & 1) ^ 1][k], best);
            }
            dp[i & 1][j] += best;
        }
    }
    return *min_element(dp[N & 1].begin(), dp[N & 1].end());
}


int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<vector<int>> v(n, vector<int>(k, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> v[i][j];
            }
        }
        cout << day19(v) << endl;
    }
    return 0;
}
