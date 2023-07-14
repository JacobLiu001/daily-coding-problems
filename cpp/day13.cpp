#include "includes/universal.h"
using namespace std;

const int CHAR_SIZE = 8;
const int CHARSET_SIZE = 1 << CHAR_SIZE;

void addch(int *chcounts, int c, int &count) {
    if (!chcounts[c]) {
        count++;
    }
    chcounts[c]++;
}

void removech(int *chcounts, int c, int &count) {
    chcounts[c]--;
    if (!chcounts[c]) {
        count--;
    }
}

string day13(const string &s, int k) {
    const int n = s.size();
    // We use a sliding window [l, r).
    int l = 0, r = 0;
    int bestl = -1, bestr = -1;

    int count = 0;
    int chcounts[CHARSET_SIZE];
    memset(chcounts, 0, sizeof(chcounts));

    while (true) {
        // We expand the string to the right as much as possible
        while (r < n && count <= k) {
            addch(chcounts, s[r], count);
            r++;
        }
        // If we expanded such that it contains too many characters,
        // we back up by one character.
        if (count > k) {
            r--;
            removech(chcounts, s[r], count);
        }
        // Now the string is in a valid and locally optimal state.
        if (r - l > bestr - bestl) {
            bestr = r;
            bestl = l;
        }
        // If we have reached the end, we are finished.
        if (r == n) {
            break;
        }

        // Now we slice off the front of the string so that we can expand later on.
        while (l < r && count >= k) {
            removech(chcounts, s[l], count);
            l++;
        }
    }
    return s.substr(bestl, bestr - bestl);
}

int main() {
    string s;
    int k;
    while (cin >> s >> k) {
        cout << day13(s, k) << endl;
    }
    return 0;
}