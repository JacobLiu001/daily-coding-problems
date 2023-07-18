#include "includes/universal.h"
using namespace std;

vector<string> split(const string &s, const string &delimiter) {
    // https://stackoverflow.com/a/46931770/11895387
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int day17(const vector<string> &s) {
    int best = 0;
    int cwdLen = 0;
    int cwdDepth = 0; // counts tabs
    vector<string> cwdPath;
    for (auto &x: s) {
        int cntTab = x.find_first_not_of('\t');
        while (cwdDepth > cntTab) { // yes this is devious, but it's fun!
            // cd .. until we're at the right level
            cwdDepth--;
            cwdLen -= cwdPath.back().size() + 1;
            cwdPath.pop_back();
        }
        if (x.find('.') == string::npos) {
            // it's a directory, cd into it
            ++cwdDepth;
            cwdLen += x.size() - cntTab + 1; // +1 for "/"
            cwdPath.push_back(x.substr(cntTab));
        } else {
            // it's a file
            int finalLen = x.size() - cntTab + cwdLen;
            best = max(best, finalLen);
        }
    }
    return best;
}

int day17(const string &s) {
    return day17(split(s, "\n"));
}

int main() {
    vector<string> vs;
    string s;
    while (getline(cin, s)) vs.push_back(s);
    cout << day17(vs) << endl;
    return 0;
}
