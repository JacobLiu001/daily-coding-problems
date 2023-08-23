#include "includes/universal.h"
using namespace std;

struct Node {
    string val;
    Node* l;
    Node* r;

    Node(const string& v = "", Node* l = NULL, Node* r = NULL)
        : val(v), l(l), r(r) {}

    string toString() const {
        return string("Node(") + val + ", " + (l ? l->toString() : "NULL") +
               ", " + (r ? r->toString() : "NULL") + ")";
    }

    template <typename RandomAccessIterator>
    static Node* fromPreAndInOrder(RandomAccessIterator preBegin,
                                   RandomAccessIterator preEnd,
                                   RandomAccessIterator inBegin,
                                   RandomAccessIterator inEnd);
};

template <typename RandomAccessIterator>
Node* Node::fromPreAndInOrder(
    RandomAccessIterator preBegin,
    RandomAccessIterator preEnd,
    RandomAccessIterator inBegin,
    RandomAccessIterator inEnd) {
    if (preBegin >= preEnd || inBegin >= inEnd) {
        return NULL;
    }
    Node* ret = new Node(*preBegin);
    RandomAccessIterator inPivot = find(inBegin, inEnd, *preBegin);
    assert(inPivot != inEnd);
    int leftSize = inPivot - inBegin;
    ret -> l = fromPreAndInOrder(preBegin + 1, preBegin + 1 + leftSize, inBegin, inPivot);
    ret -> r = fromPreAndInOrder(preBegin + 1 + leftSize, preEnd, inPivot + 1, inEnd);
    return ret;
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> pre(n, "");
        vector<string> in(n, "");
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        Node *ans = Node::fromPreAndInOrder(pre.begin(), pre.end(), in.begin(), in.end());
        cout << ans->toString() << endl;
    }
    return 0;
}
