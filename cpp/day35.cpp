#include "includes/universal.h"
using namespace std;

void day35(vector<char> &v) {
    int i = 0, j = 0, k = v.size() - 1;
    while (j <= k) {
        if (v[j] == 'R') {
            swap(v[i++], v[j++]);
        } else if (v[j] == 'G') {
            j++;
        } else {
            swap(v[j], v[k--]);
        }
    }
}

int main() {
    string s;
    while (cin >> s) {
        vector<char> v(s.begin(), s.end());
        day35(v);
        cout << string(v.begin(), v.end()) << endl;
    }
    return 0;
}
