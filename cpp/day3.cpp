// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

struct Node {
    private:
    int id;  // to facilitate serialization.

    static void replaceAll(string& source, const string& from, const string& to) {
        // https://stackoverflow.com/a/29752943
        string newString;
        newString.reserve(source.length());  // avoids a few memory allocations

        string::size_type lastPos = 0;
        string::size_type findPos;

        while(string::npos != (findPos = source.find(from, lastPos)))
        {
            newString.append(source, lastPos, findPos - lastPos);
            newString += to;
            lastPos = findPos + from.length();
        }
        // Care for the rest after last occurrence
        newString += source.substr(lastPos);
        source.swap(newString);
    }

    static string escape_string(string s) {
        replaceAll(s, "\\", "\\\\");
        replaceAll(s, "/", "\\/");
        return s;
    }

    string preOrderVals(int &id_to_set) {
        string s = escape_string(val) + "/";
        id = id_to_set++;
        if (left) {
            s += (left -> preOrderVals(id_to_set));
        }
        if (right) {
            s += (right -> preOrderVals(id_to_set));
        }
        return s;
    }

    string inOrderIds() const {
        string s = to_string(id) + "/";
        return (
            (left ? left -> inOrderIds() : string())
            + s
            + (right ? right -> inOrderIds() : string())
        );
    }

    static Node* inorderToTree(vector<int> ids, 
        vector<int>::iterator s, vector<int>::iterator e) {
        if (s >= e) {
            return NULL;
        }
        auto iter = min_element(s, e);
        // min_id is the root of the tree
        Node *n = new Node();
        n -> id = *iter;  // not necessary, but useful for double-checking.
        n -> left = inorderToTree(ids, s, iter);
        n -> right = inorderToTree(ids, iter + 1, e);
        return n;
    }

    void fillVals(vector<string> vals, int &v) {
        val = vals[v++];
        if (left) {
            left -> fillVals(vals, v);
        }
        if (right) {
            right -> fillVals(vals, v);
        }
    }

    public:
    string val;
    Node *left;
    Node *right;

    Node(string v = "", Node *l = NULL, Node *r = NULL):
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

    string serialize() {
        int x = 0;
        string s = preOrderVals(x);
        return to_string(x) + "/" + s + inOrderIds();
    }

    static Node* deserialize(const string &s) {
        int LEN = s.size();
        int pos = s.find('/');
        int n = stoi(s.substr(pos - 1));
        vector<string> allfields;
        allfields.reserve(2 * n);
        string x = "";
        for (int i = pos+1; i < LEN; i++) {
            char ch;
            if (s[i] == '\\') {
                ch = s[++i];
            } else {
                ch = s[i];
                if (ch == '/') {
                    allfields.push_back(x);
                    x = "";
                    continue;
                }
            }
            x += ch;
        }
        vector<int> ids;
        ids.reserve(n);
        for (int i = n; i < 2 * n; i++) {
            ids.push_back(stoi(allfields[i]));
        }
        Node *node = inorderToTree(ids, ids.begin(), ids.end());
        int c = 0;
        node -> fillVals(allfields, c);
        // assert (c == n);
        return node;
    }

    string toString() const {
        return string("Node(") 
            + val + ", " 
            + (left ? left -> toString() : "NULL") + ", "
            + (right ? right -> toString() : "NULL") + ")";
    }
};

int main() {
    Node x("root", new Node("l", new Node("l.l"), new Node("l.r")), new Node("r"));
    string s;
    s = x.serialize();
    cout << s << endl;
    Node *n = Node::deserialize(s);
    cout << x.toString() << endl;
    cout << (n -> toString()) << endl;
    delete n;
    return 0;
}