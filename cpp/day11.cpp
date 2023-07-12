// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

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

    void getAll(string cur, vector<string> &v) {
        if (isWord) {
            v.push_back(cur);
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (children[i]) {
                children[i] -> getAll(cur + mapOut(i), v);
            }
        }
    }

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

    vector<string> searchAll(const char *s, int offset = 0) {
        if (s[offset] == '\0') {
            vector<string> ans;
            getAll(string(s), ans);
            return ans;
        }
        int idx = mapInto(s[offset]);
        if (!children[idx]) {
            return vector<string>();
        }
        return children[idx] -> searchAll(s, offset + 1);
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
};


int main() {
    Trie x;
    x.add("dog");
    x.add("deer");
    x.add("deal");
    x.add("dee");
    x.add("de");
    cout << x.searchAll("de") << endl;
    cout << endl;
    return 0;
}