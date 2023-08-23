#include "includes/universal.h"
using namespace std;

struct Node {
    bool isLeaf;
    union {
        struct {
            char opcode;
            Node *left;
            Node *right;
        } op;
        double val;
    } payload;

    Node(int v) {
        isLeaf = true;
        payload.val = v;
    }

    Node(double v) {
        isLeaf = true;
        payload.val = v;
    }

    Node(char c, Node *l = NULL, Node *r = NULL) {
        isLeaf = false;
        payload.op.opcode = c;
        payload.op.left = l;
        payload.op.right = r;
    }

    double getVal() const {
        if (isLeaf) {
            return payload.val;
        }
        char ch = payload.op.opcode;
        double v1 = payload.op.left -> getVal();
        double v2 = payload.op.right -> getVal();

        if (ch == '+') {
            return v1 + v2;
        }
        if (ch == '-') {
            return v1 - v2;
        }
        if (ch == '*') {
            return v1 * v2;
        }
        if (ch == '/') {
            return v1 / v2;
        }
        // should never happen.
        return 0;
    }
};

int main() {
    Node *n = new Node('*', new Node('+', new Node(3), new Node(2)), new Node('+', new Node(4), new Node(5)));

    assert(fabs(n -> getVal() - 45) <= 1e-8);
    return 0;
}
