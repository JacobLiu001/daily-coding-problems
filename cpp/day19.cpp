#include "includes/universal.h"
using namespace std;

int day19(vector<vector<int>> mat) {
    const int INF = 0x7fffffff;
    int N = mat.size();
    int K = mat[0].size();

    // dp[i][j] = min cost of painting the first i houses,
    // with the i-th house being painted as colour j.

    // dp[i][j] = mat[i][j] + min{dp[i-1][k]} (k != j)
    vector<vector<int>> dp(N + 1, vector<int>(K, INF));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i <= N; i++) {
        // TODO: since we only use the current row and the previous
        // we can use a rolling array (i.e., discard older rows).
        for (int j = 0; j < K; j++) {
            dp[i][j] = mat[i-1][j];
            int best = INF;
            for (int k = 0; k < K; k++) {
                if (k == j) {
                    continue;
                }
                best = min(dp[i-1][k], best);
            }
            dp[i][j] += best;
        }
    }
    return *min_element(dp.back().begin(), dp.back().end());
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
