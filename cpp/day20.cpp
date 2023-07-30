#include "includes/universal.h"
using namespace std;

struct Node {
    int val;
    Node *nxt;

    Node(int v = 0, Node *next = nullptr): val(v), nxt(next) {}

    static Node* findIntersect(Node *hA, Node *hB) {
        if (!hA || !hB) {
            return nullptr;
        }
        Node *pA = hA;
        Node *pB = hB;
        while (pA != pB) {
            pA = pA ? pA -> nxt : hB;
            pB = pB ? pB -> nxt : hA;
        }
        return pA;
    }
};

int main() {
    Node *a = new Node(1, new Node(2, new Node(3)));
    Node *b = new Node(4, a -> nxt);
    cout << (Node::findIntersect(a, b) -> val) << endl;
    Node *c = new Node(5, new Node(6));
    assert (Node::findIntersect(a, c) == nullptr);
    return 0;
}
