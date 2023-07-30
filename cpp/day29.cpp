#include "includes/universal.h"
using namespace std;

string rleEncode(const string &s) {
    string ret;
    char prev = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != prev) {
            ret += to_string(cnt);
            ret += prev;
            prev = s[i];
            cnt = 0;
        }
        ++cnt;
    }
    ret += to_string(cnt);
    ret += prev;
    return ret;
}

string rleDecode(const string &s) {
    string ret;
    int k = 0;
    for (auto &ch: s) {
        if (isdigit(ch)) {
            k *= 10;
            k += ch - '0';
        } else {
            ret += string(k, ch);
            k = 0;
        }
    }
    return ret;
}


int main() {
    string s;
    while (cin >> s) {
        string s1 = rleEncode(s);
        cout << s1 << endl;
        string s2 = rleDecode(s1);
        cout << s2 << endl;
        assert(s2 == s);
    }
    return 0;
}
