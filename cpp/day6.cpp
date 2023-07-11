// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

struct Node {
    string val;
    Node* both;

    Node(string v, Node* b): val(v), both(b) {}
};

// test if bit_cast is defined, if so, use it.
// apparently the C standard ensures that uintptr_t and void* are the same size.
#if __cpp_lib_bit_cast >= 201806L 
uintptr_t toInt(Node const *x) {
    return bit_cast<uintptr_t>(x);
}
Node* toPtr(uintptr_t x) {
    return bit_cast<Node*>(x);
}
#else
uintptr_t toInt(Node const *x) {
    return reinterpret_cast<uintptr_t>(x);
}
Node* toPtr(uintptr_t x) {
    return reinterpret_cast<Node*>(x);
}
#endif

Node* XOR(Node const *x, Node const *y) {
    return toPtr(toInt(x) ^ toInt(y));
}

class XorLinkedList {
    private:
    Node *head;
    Node *end;
    size_t length;

    public:

    XorLinkedList(): head(NULL), end(NULL), length(0) {}

    ~XorLinkedList() {
        Node *prev = NULL;
        Node *cur = head;

        while (length && cur) {
            length -= 1;
            Node *old_cur = cur;
            cur = XOR(cur -> both, prev);
            prev = old_cur;
            delete old_cur;
        }
    }

    void add(string payload) {
        Node *newPtr = new Node(payload, end);
        if (head == NULL) {
            head = newPtr;
        }
        if (end != NULL) {
            end -> both = XOR((end -> both), newPtr);
        }
        end = newPtr;
        length += 1;
    }

    Node* get(size_t index) const {
        assert (index < length);

        Node *prev = NULL;
        Node *cur = head;

        while (index && cur) {
            index -= 1;
            Node *old_cur = cur;
            cur = XOR(cur -> both, prev);
            prev = old_cur;
        }

        return cur;
    }

    string toString() const {
        string s = "[";

        Node *prev = NULL;
        Node *cur = head;
        int l = length;

        while (l && cur) {
            l -= 1;
            s += (cur -> val) + " -> ";
            Node *old_cur = cur;
            cur = XOR(cur -> both, prev);
            prev = old_cur;
        }

        s += "(NULL)]";

        return s;
    }
};


int main() {
    XorLinkedList l;
    l.add("15");
    l.add("20");
    l.add("50");
    l.add("25");
    cout << l.toString() << endl;
    cout << l.get(1) -> val << endl;
    return 0;
}