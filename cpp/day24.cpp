#include "includes/universal.h"
using namespace std;

class Node {
private:
    int lockCount = 0;
    bool locked = false;

    bool lockCanChange() const {
        if (lockCount > 0) {
            return false;
        }
        const Node *p = this;
        while (p) {
            if (p -> locked) {
                return false;
            }
            p = p -> parent;
        }
        return true;
    }
public:
    int payload;
    Node *left;
    Node *right;
    Node *parent;

    Node(int payload, Node *left = NULL, Node *right = NULL, Node *parent = NULL):
        payload(payload),
        left(left),
        right(right),
        parent(parent) {}

    bool isLocked() const {
        return locked;
    }

    bool lock() {
        if (locked) {
            return true;
        }
        if (!lockCanChange()) {
            return false;
        }
        locked = true;
        Node *p = this -> parent;
        while (p) {
            ++(p -> lockCount);
            p = p -> parent;
        }
        return true;
    }

    bool unlock() {
        if (!locked) {
            return true;
        }
        if (!lockCanChange()) {
            return false;
        }
        locked = false;
        Node *p = this -> parent;
        while (p) {
            --(p -> lockCount);
            p = p -> parent;
        }
        return true;
    }
};
// I can't be bothered to test this...
