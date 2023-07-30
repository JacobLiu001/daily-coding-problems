#include "includes/universal.h"
using namespace std;


bool matchRegex(const string &s, const string &p) {
    auto matches = [&s, &p](int i, int j) {
        if (i == 0) {
            return false;
        }
        if (p[j - 1] == '.') {
            return true;
        }
        return s[i-1] == p[j-1];
    };

    vector<vector<int>> v(s.size() + 1, vector(p.size() + 1, 0));
    v[0][0] = 1;
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 1; j <= p.size(); j++) {
            if (p[j - 1] == '*') {
                v[i][j] |= v[i][j - 2];
                v[i][j] |= (matches(i, j - 1) && v[i - 1][j]);
            } else {
                v[i][j] |= matches(i, j) && v[i - 1][j - 1];
            }
        }
    }
    return v[s.size()][p.size()];
}

int main() {
    string s, p;
    while (cin >> s >> p) {
        cout << matchRegex(s, p) << endl;
    }
    return 0;
}
