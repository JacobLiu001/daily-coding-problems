#include "includes/universal.h"
using namespace std;

class Node {
public:
    string payload;
    Node *next;

    Node(string payload = "", Node *next = NULL):
        payload(payload), next(next) {}

    string deleteKthLast(int k) {
        Node *t, *p;
        t = this;

        for (int i = 0; i < k + 1; i++) {
            t = t -> next;
        }

        p = this;

        while (t) {
            t = t -> next;
            p = p -> next;
        }

        Node *toDelete = p -> next;
        string ret = toDelete -> payload;

        p -> next = toDelete -> next;
        delete toDelete;
        return payload;
    }

    void debug() const {
        const Node *p = this;
        while (p) {
            cout << (p -> payload) << " at " << p << endl;
            p = p -> next;
        }
    }
};

int main() {
    Node *l = new Node("1", new Node("2", new Node("3", new Node("4"))));
    l -> deleteKthLast(2);
    l -> debug();
    return 0;
}
