#include "includes/universal.h"
using namespace std;

pair<int, int> manacher(const string &s) {
    int len = s.size();
    vector<int> p(len + 1, 0);
    int mx = 0, id = 0;
    for (int i = 1; i <= len; ++i) {
        if (mx > i) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (s[i + p[i]] == s[i - p[i]]) {
            ++p[i];
        }
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    int resIdx = max_element(p.begin() + 1, p.end() - 1) - p.begin();
    return make_pair(resIdx, p[resIdx]);
}

string day46(string st) {
    string s = "$#";
    for (auto ch: st) {
        s += ch; s += '#';
    }
    auto [idx, l] = manacher(s);
    int start = (idx - l) / 2;
    return st.substr(start, l - 1);
}

int main() {
    string s;
    while (cin >> s) {
        cout << day46(s) << endl;
    }
}
