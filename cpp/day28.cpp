#include "includes/universal.h"
using namespace std;

vector<string> day28(const vector<string> &v, int k) {
    vector<string> ret;
    int n = v.size();
    int p = 0;
    int running = 0; // sum of len of words
    for (int i = 0; i < n; i++) {
        if (running + (i - p) + v[i].size() > k) {
            // [p, i)
            int m = i - p - 1;
            int spaces = k - running;
            string line;
            for (int j = p; j < i; j++) {
                line += v[j];
                if (m == 0) {
                    line += string(spaces, ' ');
                } else if (j != i - 1) {
                    line += string(spaces / m + ((j - p) < spaces % m), ' ');
                }
            }
            ret.push_back(line);
            p = i;
            running = 0;
        }
        running += v[i].size();
    }
    if (running != 0) {
        int m = n - p - 1;
        int spaces = k - running;
        string line;
        for (int j = p; j < n; j++) {
            line += v[j];
            if (m == 0) {
                line += string(spaces, ' ');
            } else if (j != n - 1) {
                line += string(spaces / m + ((j - p) < spaces % m), ' ');
            }
        }
        ret.push_back(line);
    }
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << day28(v, k) << endl;
    return 0;
}
