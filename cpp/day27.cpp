#include "includes/universal.h"
using namespace std;

bool isClosingBracket(char c) {
    return (c == ')') || (c == ']') || (c == '}');
}

char matchingBracket(char c) {
    if (c == ')') {
        return '(';
    }
    if (c == ']') {
        return '[';
    }
    if (c == '}') {
        return '{';
    }
    return '\0';
}

bool isBalanced(string s) {
    stack<char> st;
    for (auto &ch: s) {
        if (isClosingBracket(ch)) {
            if (st.top() != matchingBracket(ch)) {
                return false;
            }
            st.pop();
        } else {
            st.push(ch);
        }
    }
    return st.empty();
}

int main() {
    string s;
    while (cin >> s) {
        cout << isBalanced(s) << endl;
    }
    return 0;
}
