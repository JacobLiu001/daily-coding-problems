#include "includes/universal.h"
using namespace std;

// almost same as day11.
class Trie {
    private:
    static const int ALPHABET_SIZE = 26;
    static int mapInto(char c) {
        assert (islower(c));
        return (c - 'a');
    }
    static char mapOut(int x) {
        assert (x >= 0 && x < ALPHABET_SIZE);
        return ('a' + x);
    }
    bool isWord;
    Trie* children[ALPHABET_SIZE];

    public:
    Trie() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }

    ~Trie() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (children[i]) {
                children[i] -> ~Trie();
            }
        }
    }

    void add(const char *s) {
        int idx = mapInto(*s);
        if (!children[idx]) {
            children[idx] = new Trie();
        }
        if (s[1] == '\0') {
            children[idx] -> isWord = true;
            return ;
        }
        children[idx] -> add(s + 1);
        return ;
    }

    bool find(const char *s) {
        if (s[0] == '\0') {
            return true;
        }
        int idx = mapInto(*s);
        if (!children[idx]) {
            return false;
        }
        return children[idx] -> find(s + 1);
    }

    void debug(string prefix = "") {
        cout << "\n";
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (children[i]) {
                cout << prefix << mapOut(i);
                children[i] -> debug(prefix + "    ");
            }
        }
    }

    vector<int> matches(const char *s) const {
        vector<int> ans;
        const Trie *p = this;
        for (int i = 0; s[i] != '\0'; i++) {
            int idx = mapInto(s[i]);
            if (!(p -> children[idx])) {
                return ans;
            }
            p = p -> children[idx];
            if (p -> isWord) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};


vector<string> day22(const Trie &dict, const char *sentence, int n) {
    // dp[i] == length of the first word in the reconstruction of sentence[i:]
    // -1 if impossible.
    vector<int> dp(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> v = dict.matches(sentence + i);
        for (auto x: v) {
            if (i + x == n || dp[i + x] != -1) {
                dp[i] = x;
                break;
            }
        }
    }
    if (dp[0] == -1) {
        return vector<string>();
    }
    vector<string> ans;
    int p = 0;
    while (p < n) {
        ans.push_back(string(sentence + p, dp[p]));
        p += dp[p];
    }
    return ans;
}

int main() {
    Trie dict;
    dict.add("quick");
    dict.add("the");
    dict.add("fox");
    string s;
    while (cin >> s) {
        cout << day22(dict, s.c_str(), s.size()) << endl;
    }
    return 0;
}
