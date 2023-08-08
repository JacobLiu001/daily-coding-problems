#include "includes/universal.h"
using namespace std;

struct Node {
    int payload;
    Node *left;
    Node *right;

    Node(int payload = 0, Node *left = nullptr, Node *right = nullptr):
        payload(payload),
        left(left),
        right(right) {}

    Node* secondLargest() {
        // assert that this tree has at least two nodes.
        assert (right != nullptr || left != nullptr);

        // find the largest element (and its parent)
        Node *pos = this, *prev = nullptr;
        while (pos -> right) {
            prev = pos;
            pos = pos -> right;
        }
        if (pos -> left) {
            Node *ans = pos -> left;
            while (ans -> right) {
                ans = ans -> right;
            }
            return ans;
        }
        return prev;
    }
};


int main() {
    Node *x = new Node(
        10,
        new Node(
            5,
            new Node(1),
            new Node(6)
        ),
        new Node(
            15,
            new Node(11),
            new Node(20)
        )
    );
    cout << (x -> secondLargest() -> payload) << endl;
    return 0;
}
