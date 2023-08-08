#include "includes/universal.h"
using namespace std;

int day31(const string &s1, const string &s2) {
    const int n = s1.size();
    const int m = s2.size();
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0x7fffffff));
    v[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        v[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        v[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = 1 + min({
                v[i-1][j],
                v[i][j-1],
                v[i-1][j-1] - (s1[i - 1] == s2[j - 1])
            });
        }
    }
    return v.back().back();
}


int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << day31(s1, s2) << endl;
    }
}
