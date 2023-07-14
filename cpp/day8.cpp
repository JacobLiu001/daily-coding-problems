// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

struct Node {
    private:
    pair<int, pair<bool, int> > count_unival_subtrees_helper() const {
        int c = 0;
        bool b = true;
        int v = val;
        if (left) {
            int cl;
            pair<int, pair<bool, int> > rl = left -> count_unival_subtrees_helper();
            cl = rl.first;
            c += cl;
            if (!rl.second.first || rl.second.second != v) {
                b = false;
            }
        }
        if (right) {
            int cr;
            pair<int, pair<bool, int> > rr = right -> count_unival_subtrees_helper();
            cr = rr.first;
            c += cr;
            if (!rr.second.first || rr.second.second != v) {
                b = false;
            }
        }
        if (b) {
            c++;
        }
        return make_pair(c, make_pair(b, v));
    }
    public:
    int val;
    Node *left;
    Node *right;

    Node(int v, Node* l = NULL, Node* r = NULL):
        val(v),
        left(l),
        right(r) {}

    ~Node() {
        if (left) {
            left -> ~Node();
        }
        if (right) {
            right -> ~Node();
        }
    }

    string toString() const {
        string s;
        s += "Node(";
        s += to_string(val);
        s += ", ";
        s += (left ? left -> toString() : "NULL");
        s += ", ";
        s += (right ? right -> toString() : "NULL");
        s += ")";
        return s;
    }

    int count_unival_subtrees() const {
        auto res = count_unival_subtrees_helper();
        return res.first;
    }
};

int main() {
    Node t = Node(0, new Node(1), new Node(0, new Node(1, new Node(1), new Node(1)), new Node(0)));
    cout << t.count_unival_subtrees() << endl;
    return 0;
}
